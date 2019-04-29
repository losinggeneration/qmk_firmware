#include QMK_KEYBOARD_H
#include "losinggeneration-keymap.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY]  = CATMAP( QWERTY_LAYER  ),
[_COLEMAK] = CATMAP( COLEMAK_LAYER ),
[_WORKMAN] = CATMAP( WORKMAN_LAYER ),
[_DVORAK]  = CATMAP( DVORAK_LAYER  ),
[_GAME]    = CATMAP( GAME_LAYER    ),
[_NUMPAD]  = CATMAP( NUMPAD_LAYER  ),
[_MOUSE]   = CATMAP( MOUSE_LAYER   ),
[_LOWER]   = CATMAP( LOWER_LAYER   ),
[_RAISE]   = CATMAP( RAISE_LAYER   ),

/* MIDI
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │  F#  │  G   │  G#  │  A   │  A#  │  B   ││ XXX  │ XXX  │ XXX  │ XXX  │ XXX  │ ADJ  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │  C   │  C#  │  D   │  D#  │  E   │  F   ││ XXX  │ XXX  │ XXX  │ Trns-│ Trns+│RstTrs│
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │  F#  │  G   │  G#  │  A   │  A#  │  B   ││ XXX  │ XXX  │ XXX  │ ModS-│ ModS+│ Sus  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │  C   │  C#  │  D   │  D#  │  E   │  F   ││AllOff│ XXX  │ XXX  │ Oct- │ Oct+ │ Mod  │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
[_MIDI] = CATMAP(
  MI_Fs_1, MI_G_1 , MI_Gs_1, MI_A_1 , MI_As_1, MI_B_1 ,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   MO_ADJ ,
  MI_C_1 , MI_Cs_1, MI_D_1 , MI_Ds_1, MI_E_1 , MI_F_1 ,   XXXXXXX, XXXXXXX, XXXXXXX ,MI_TRNSD, MI_TRNSU, MI_TRNS_0,
  MI_Fs  , MI_G   , MI_Gs  , MI_A   , MI_As  , MI_B   ,   XXXXXXX, XXXXXXX, XXXXXXX, MI_MODSD, MI_MODSU,   MI_SUS ,
  MI_C   , MI_Cs  , MI_D   , MI_Ds  , MI_E   , MI_F   , MI_ALLOFF, XXXXXXX, XXXXXXX,  MI_OCTD,  MI_OCTU,   MI_MOD
),


/* Adjust (Lower + Raise)
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │  F1  │  F2  │  F3  │  F4  │BL Tg ││ RESET│ Game │Numpad│Mouse │      │Sleep │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  F5  │  F6  │  F7  │  F8  │BL Dec││MidiTg│Qwerty│Colmak│Workmn│Dvorak│      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ CAPS │  F9  │  F10 │  F11 │  F12 │BL Inc││      │      │      │      │  Up  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ││      │      │ XXX  │ Left │ Down │Right │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
[_ADJUST] = CATMAP( \
  _______, KC_F1  ,  KC_F2 , KC_F3  , KC_F4  , BL_TOGG, RESET  , TO_GAME, TO_NUM , TO_MS  , _______, KC_SLEP, \
  _______, KC_F5  ,  KC_F6 , KC_F7  , KC_F8  , BL_DEC , TO_MIDI, QWERTY , COLEMAK, WORKMAN, DVORAK , _______, \
  KC_CAPS, KC_F9  ,  KC_F10, KC_F11 , KC_F12 , BL_INC , _______, _______, _______, _______, KC_UP  , _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT  \
)

};

