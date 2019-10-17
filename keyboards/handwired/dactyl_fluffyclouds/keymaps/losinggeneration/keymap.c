#include QMK_KEYBOARD_H

#include "losinggeneration-config.h"
#include "losinggeneration-keymap.h"

extern keymap_config_t keymap_config;

#define NUMBER_ROW \
  KC_TILD ,KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY]  = CATMAP( NUMBER_ROW, QWERTY_LAYER, CLUSTER_ROW  ),
[_COLEMAK] = CATMAP( NUMBER_ROW, COLEMAK_LAYER, CLUSTER_ROW ),
[_WORKMAN] = CATMAP( NUMBER_ROW, WORKMAN_LAYER, CLUSTER_ROW ),
[_DVORAK]  = CATMAP( NUMBER_ROW, DVORAK_LAYER, CLUSTER_ROW  ),
[_NUMPAD]  = CATMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PAST, KC_PSLS, KC_BSPC, KC_BSPC, \
  NUMPAD_LAYER \
),

[_MOUSE] = CATMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  MOUSE_LAYER \
),

[_LOWER] = CATMAP( \
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL , \
  LOWER_LAYER, \
  CLUSTER_ROW \
),

[_RAISE] = CATMAP(NUMBER_ROW, RAISE_LAYER, CLUSTER_ROW ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------..-----------------------------------------.
 * | RESET|DEBUG |      |      |      |      ||      |      |      |      |      |      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      ||      |      |Numpad| Mouse|      |Sleep |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      ||      |Qwerty|Colmak|Workmn|Dvorak|      |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | CAPS |  F9  |  F10 |  F11 |  F12 |      ||      |      |      |      |  Up  |      |
 * |------+------+------+------+------+------''------+------+------+------+------+------|
 * |      |      |      |      |      |              |      | XXX  | Left | Down |Right |
 * `----------------------------------'              '----------------------------------'
 *                             ,-------------..------------.
 *                             | Lower| Gui  || Gui | Raise|
 *                      ,------+------+------||-----*------+------.
 *                      |      |      | Alt  || Alt |      |      |
 *                      |BkSpc | Ent  |------||-----| Ent  | Spc  |
 *                      |      |      | Ctrl || Ctrl|      |      |
 *                      `--------------------'`-------------------'
 */
[_ADJUST] = LAYOUT_6x6( \
  RESET  ,  DEBUG , _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
  _______, KC_F1  ,  KC_F2 , KC_F3  , KC_F4  , _______,      _______, _______, TO_NUM , TO_MS  , _______, KC_SLEP,
  _______, KC_F5  ,  KC_F6 , KC_F7  , KC_F8  , _______,      _______, QWERTY , COLEMAK, WORKMAN, DVORAK , _______,
  KC_CAPS, KC_F9  ,  KC_F10, KC_F11 , KC_F12 , _______,      _______, _______, _______, _______, KC_UP  , _______,
  _______, _______, _______, _______, _______,                        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,
                                      _______, _______,      _______, _______,
                                               _______,      _______,
                             _______, _______, _______,      _______, _______, _______
)
};

