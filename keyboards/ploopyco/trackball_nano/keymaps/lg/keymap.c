/* Copyright 2022 Aidan Gauland
 * Copyright 2021 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2019 Hiroyuki Okada
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define NUM_LOCK_BITMASK 0b001
#define CAPS_LOCK_BITMASK 0b010
#define SCROLL_LOCK_BITMASK 0b100

// World record for fastest index finger tapping is 1092 taps per minute, which
// is 55ms for a single tap.
// https://recordsetter.com/world-record/index-finger-taps-minute/46066
#define LED_CMD_TIMEOUT 25
#define DELTA_X_THRESHOLD 60
#define DELTA_Y_THRESHOLD 15

typedef enum {
    // You could theoretically define 0b00 and send it by having a macro send
    // the second tap after LED_CMD_TIMEOUT has elapsed.
    // CMD_EXTRA = 0b00,
    TG_SCROLL = 0b001,
    CYC_DPI   = 0b010,
    CMD_RESET = 0b011, // CMD_ prefix to avoid clash with QMK macro
    REV_DPI   = 0b100,
} led_cmd_t;

// State
static bool   scroll_enabled    = false;
static bool   num_lock_state    = false;
static bool   caps_lock_state   = false;
static bool   scroll_lock_state = false;
static bool   in_cmd_window     = false;
static int8_t delta_x           = 0;
static int8_t delta_y           = 0;

typedef struct {
    led_cmd_t led_cmd;
    uint8_t   num_lock_count;
    uint8_t   caps_lock_count;
    uint8_t   scroll_lock_count;
} cmd_window_state_t;

// Dummy
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{{KC_NO}}};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scroll_enabled) {
        delta_x += mouse_report.x;
        delta_y += mouse_report.y;

        if (delta_x > DELTA_X_THRESHOLD) {
            mouse_report.h = 1;
            delta_x        = 0;
        } else if (delta_x < -DELTA_X_THRESHOLD) {
            mouse_report.h = -1;
            delta_x        = 0;
        }

        if (delta_y > DELTA_Y_THRESHOLD) {
            mouse_report.v = -1;
            delta_y        = 0;
        } else if (delta_y < -DELTA_Y_THRESHOLD) {
            mouse_report.v = 1;
            delta_y        = 0;
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

void keyboard_post_init_user(void) {
    num_lock_state    = host_keyboard_led_state().num_lock;
    caps_lock_state   = host_keyboard_led_state().caps_lock;
    scroll_lock_state = host_keyboard_led_state().scroll_lock;
}

uint16_t dpi_config = 0;
uint16_t dpis[]     = {400, 800, 1200, 2400};
#define DPI_OPTION_SIZE (sizeof(dpis) / sizeof(uint16_t))

void change_dpi(int8_t i) {
#if 0
    int16_t s = (int16_t)dpi_config + i;
    if (s < 0) {
        dpi_config = 0;
    } else if (s >= DPI_OPTION_SIZE) {
        dpi_config = DPI_OPTION_SIZE - 1;
    } else {
        dpi_config = s;
    }
#else
    dpi_config = (dpi_config + i) % DPI_OPTION_SIZE;
#endif

    pointing_device_set_cpi(dpis[dpi_config]);
}

uint32_t command_timeout(uint32_t trigger_time, void *cb_arg) {
    cmd_window_state_t *cmd_window_state = (cmd_window_state_t *)cb_arg;
    switch (cmd_window_state->led_cmd) {
        case TG_SCROLL:
            scroll_enabled = !scroll_enabled;
            break;
        case CYC_DPI:
            /*cycle_dpi();*/
            change_dpi(1);
            break;
        case REV_DPI:
            scroll_enabled = !scroll_enabled;
            /*change_dpi(-1);*/
            break;
        case CMD_RESET:
            reset_keyboard();
            break;
        default:
            // Ignore unrecognised commands.
            break;
    }
    cmd_window_state->led_cmd           = 0;
    cmd_window_state->num_lock_count    = 0;
    cmd_window_state->caps_lock_count   = 0;
    cmd_window_state->scroll_lock_count = 0;
    in_cmd_window                       = false;

    return 0; // Don't repeat
}

bool led_update_user(led_t led_state) {
    static cmd_window_state_t cmd_window_state = {
        .led_cmd           = 0b00,
        .num_lock_count    = 0,
        .caps_lock_count   = 0,
        .scroll_lock_count = 0,
    };

    // Start timer to end command window if we are not already in the middle of
    // one.
    if (!in_cmd_window) {
        in_cmd_window = true;
        defer_exec(LED_CMD_TIMEOUT, command_timeout, &cmd_window_state);
    }

    // Set num lock and caps lock bits when each is toggled on and off within
    // the window.
    if (led_state.num_lock != num_lock_state) {
        cmd_window_state.num_lock_count++;

        if (cmd_window_state.num_lock_count == 2) {
            cmd_window_state.led_cmd |= NUM_LOCK_BITMASK;
            cmd_window_state.num_lock_count = 0;
        }
    }

    if (led_state.caps_lock != caps_lock_state) {
        cmd_window_state.caps_lock_count++;

        if (cmd_window_state.caps_lock_count == 2) {
            cmd_window_state.led_cmd |= CAPS_LOCK_BITMASK;
            cmd_window_state.caps_lock_count = 0;
        }
    }

    if (led_state.scroll_lock != scroll_lock_state) {
        cmd_window_state.scroll_lock_count++;

        if (cmd_window_state.scroll_lock_count == 2) {
            cmd_window_state.led_cmd |= SCROLL_LOCK_BITMASK;
            cmd_window_state.scroll_lock_count = 0;
        }
    }

    // Keep our copy of the LED states in sync with the host.
    num_lock_state    = led_state.num_lock;
    caps_lock_state   = led_state.caps_lock;
    scroll_lock_state = led_state.scroll_lock;
    return true;
}
