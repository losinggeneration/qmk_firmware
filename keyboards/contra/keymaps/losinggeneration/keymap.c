#include "losinggeneration.h"

#define LAYOUT_ortho_4x12_expand(...) LAYOUT_ortho_4x12(__VA_ARGS__)

extern keymap_config_t keymap_config;

#define MT_CAPS LSFT_T(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY]  = LAYOUT_ortho_4x12_expand( QWERTY_LAYER_4x12  ),
[_COLEMAK] = LAYOUT_ortho_4x12_expand( COLEMAK_LAYER_4x12 ),
[_WORKMAN] = LAYOUT_ortho_4x12_expand( WORKMAN_LAYER_4x12 ),
[_DVORAK]  = LAYOUT_ortho_4x12_expand( DVORAK_LAYER_4x12  ),
[_GAME]    = LAYOUT_ortho_4x12_expand( GAME_LAYER_4x12    ),
[_NUMPAD]  = LAYOUT_ortho_4x12_expand( NUMPAD_LAYER_4x12  ),
[_MOUSE]   = LAYOUT_ortho_4x12_expand( MOUSE_LAYER_4x12   ),
[_LOWER]   = LAYOUT_ortho_4x12_expand( LOWER_LAYER_4x12   ),
[_RAISE]   = LAYOUT_ortho_4x12_expand( RAISE_LAYER_4x12   ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      | RESET| Game |Numpad|Mouse |      |Sleep |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |Qwerty|Colmak|Workmn|Dvorak|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | XXX  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12_expand( \
  _______, KC_F1  ,  KC_F2 , KC_F3  , KC_F4  , _______, QK_BOOT, TO_GAME, TO_NUM , TO_MS  , _______, KC_SLEP, \
  _______, KC_F5  ,  KC_F6 , KC_F7  , KC_F8  , _______, _______, QWERTY , COLEMAK, WORKMAN, DVORAK , _______, \
  MT_CAPS, KC_F9  ,  KC_F10, KC_F11 , KC_F12 , _______, _______, _______, _______, _______, KC_UP  , _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT  \
)

};

