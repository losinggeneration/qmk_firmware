#include "losinggeneration.h"

/* This will ignore the bottom two keys on each side */
#define LAYOUT_ergo_4x12(                                     \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
  K30, K31, K32, K33, x00, x01, x02, x03, K38, K39, K3A, K3B, \
                      K34, K35, K36, K37,                     \
                           K40, K41,                          \
                 K50, K51, K52, K53, K54, K55                 \
) \
LAYOUT( \
  K00, K01, K02, K03, K04, K05,           K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15,           K16, K17, K18, K19, K1A, K1B, \
  K20, K21, K22, K23, K24, K25,           K26, K27, K28, K29, K2A, K2B, \
  K30, K31, K32, K33, K34, K35, K40, K41, K36, K37, K38, K39, K3A, K3B, \
                      K50, K51, K52, K53, K54, K55                      \
)

/* This will ignore the bottom row keys from the 5x12 */
#define LAYOUT_ergo_5x12(                                     \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, \
  x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x4A, x4B, \
                           K50, K51,                          \
                 K60, K61, K62, K63, K64, K65                 \
) \
LAYOUT( \
  K00, K01, K02, K03, K04, K05,           K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15,           K16, K17, K18, K19, K1A, K1B, \
  K20, K21, K22, K23, K24, K25,           K26, K27, K28, K29, K2A, K2B, \
  K30, K31, K32, K33, K34, K35, K50, K51, K36, K37, K38, K39, K3A, K3B, \
                      K60, K61, K62, K63, K64, K65                      \
)

/* Epand macros passed into LAYOUT because the default don't expand arguments. */
#define LAYOUT_ergo_4x12_expand(...) LAYOUT_ergo_4x12(__VA_ARGS__)
#define LAYOUT_ergo_5x12_expand(...) LAYOUT_ergo_5x12(__VA_ARGS__)
#define LAYOUT_expand(...) LAYOUT(__VA_ARGS__)

#define THUMB_TRANS_LAYER_4x12                          \
           _______, _______, _______, _______,          \
                    _______, _______,                   \
  _______, _______, _______, _______, _______, _______

/*
 *   ┌──────┐                              ┌──────┐
 *   │      ├──────┐                ┌──────┤Delete│
 *   └──────┤      │┌──────┐┌──────┐│      ├──────┘
 * ┌──────┐ └──────┘│ GUI  ││ CTRL │└──────┘ ┌──────┐
 * │ GUI  ├──────┐ ┌┴─────┬┘└┬─────┴┐ ┌──────┤ GUI  │
 * └──────┤Lower │ │Shift │  │Space │ │Raise ├──────┘
 *        └──────┘ └──────┘  └──────┘ └──────┘
 */
#define THUMB_DEFAULT_LAYER_4x12                        \
           _______, _______, _______, KC_DEL ,          \
                    KC_LGUI, TD_CTL ,                   \
  KC_LGUI,  LOWER , KC_LSFT, KC_SPC , RAISE  , KC_LGUI


#define THUMB_TRANS_LAYER_5x12                          \
                    _______, _______,                   \
  _______, _______, _______, _______, _______, _______

/*
 *                  ┌──────┐┌──────┐
 * ┌──────┐         │Adjust││ CTRL │         ┌──────┐
 * │ GUI  ├──────┐ ┌┴─────┬┘└┬─────┴┐ ┌──────┤ GUI  │
 * └──────┤Lower │ │Shift │  │Space │ │Raise ├──────┘
 *        └──────┘ └──────┘  └──────┘ └──────┘
 */
#define THUMB_DEFAULT_LAYER_5x12                        \
                    TD_ADJ , TD_CTL ,                   \
  KC_LGUI,  LOWER , KC_LSFT, KC_SPC , RAISE  , KC_LGUI

/*
 *                  ┌──────┐┌──────┐
 * ┌──────┐         │ Alt  ││Adjust│         ┌──────┐
 * │ GUI  ├──────┐ ┌┴─────┬┘└┬─────┴┐ ┌──────┤ GUI  │
 * └──────┤ Ctrl │ │Space │  │Space │ │Raise ├──────┘
 *        └──────┘ └──────┘  └──────┘ └──────┘
 */
#define THUMB_GAME_LAYER_5x12                           \
                    KC_LALT, TD_ADJ ,                   \
  KC_LGUI, KC_LCTL, KC_SPC , LOWER  , RAISE  , KC_LGUI

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 4x12 */
/*
[_QWERTY]  = LAYOUT_ergo_4x12_expand( QWERTY_LAYER_4x12,  THUMB_DEFAULT_LAYER_4x12 ),
[_COLEMAK] = LAYOUT_ergo_4x12_expand( COLEMAK_LAYER_4x12, THUMB_DEFAULT_LAYER_4x12 ),
[_WORKMAN] = LAYOUT_ergo_4x12_expand( WORKMAN_LAYER_4x12, THUMB_DEFAULT_LAYER_4x12 ),
[_DVORAK]  = LAYOUT_ergo_4x12_expand( DVORAK_LAYER_4x12,  THUMB_DEFAULT_LAYER_4x12 ),
[_GAME]    = LAYOUT_ergo_4x12_expand( GAME_LAYER_4x12,    THUMB_DEFAULT_LAYER_4x12 ),
[_NUMPAD]  = LAYOUT_ergo_4x12_expand( NUMPAD_LAYER_4x12,  THUMB_DEFAULT_LAYER_4x12 ),
[_MOUSE]   = LAYOUT_ergo_4x12_expand( MOUSE_LAYER_4x12,   THUMB_DEFAULT_LAYER_4x12 ),
[_LOWER]   = LAYOUT_ergo_4x12_expand( LOWER_LAYER_4x12,   THUMB_DEFAULT_LAYER_4x12 ),
[_RAISE]   = LAYOUT_ergo_4x12_expand( RAISE_LAYER_4x12,   THUMB_DEFAULT_LAYER_4x12 ),
*/

/* 5x12 */
[_QWERTY]  = LAYOUT_ergo_5x12_expand( QWERTY_LAYER_5x12 , THUMB_DEFAULT_LAYER_5x12 ),
[_COLEMAK] = LAYOUT_ergo_5x12_expand( COLEMAK_LAYER_5x12, THUMB_DEFAULT_LAYER_5x12 ),
[_WORKMAN] = LAYOUT_ergo_5x12_expand( WORKMAN_LAYER_5x12, THUMB_DEFAULT_LAYER_5x12 ),
/* Dvorak
 *                      ┌──────┐                                            ┌──────┐
 *               ┌──────┤   3  ├──────┐                              ┌──────┤   8  ├──────┐
 * ┌──────┬──────┤   2  ├──────┤   4  ├──────┐                ┌──────┤   7  ├──────┤   9  ├──────┬──────┐
 * │   `  │   1  ├──────┤   .  ├──────┤   5  │                │   6  ├──────┤   C  ├──────┤   0  │  Del │
 * ├──────┼──────┤   ,  ├──────┤   U  ├──────┤                ├──────┤   G  ├──────┤   R  ├──────┼──────┤
 * │  Tab │   '  ├──────┤  E   ├──────┤   Y  │                │   F  ├──────┤   T  ├──────┤   L  │ BkSp │
 * ├──────┼──────┤   O  ├──────┤   U  ├──────┤                ├──────┤   H  ├──────┤   N  ├──────┼──────┤
 * │ Ctrl │   A  ├──────┤  J   ├──────┤   I  │                │   D  ├──────┤   W  ├──────┤   S  │   /  │
 * ├──────┼──────┤   Q  ├──────┤   K  ├──────┤                ├──────┤   M  ├──────┤   V  ├──────┼──────┤
 * │ Alt  │   ;  ├──────┘      └──────┤   K  │┌──────┐┌──────┐│   B  ├──────┘      └──────┤   Z  │  Ent │
 * └──────┴──────┘           ┌──────┐ └──────┘│Adjust││ CTRL │└──────┘ ┌──────┐           └──────┴──────┘
 *                           │ GUI  ├──────┐ ┌┴─────┬┘└┬─────┴┐ ┌──────┤  GUI │
 *                           └──────┤Lower │ │Shift │  │Space │ │Raise ├──────┘
 *                                  └──────┘ └──────┘  └──────┘ └──────┘
 */
[_DVORAK]  = LAYOUT_ergo_5x12_expand(
    NUMBER_ROW,
    ortho_4x12_expand(
      DVORAK_LAYER_L, DVORAK_LAYER_R,
      STD_TAB,
      STD_ESC,
      TD_ALT, MT_ENT,
      BOTTOM_ROW
    ),
    THUMB_DEFAULT_LAYER_5x12
),
[_GAME]    = LAYOUT_ergo_5x12_expand( GAME_LAYER_5x12  , THUMB_GAME_LAYER_5x12    ),
[_NUMPAD]  = LAYOUT_ergo_5x12_expand( NUMPAD_LAYER_5x12, THUMB_DEFAULT_LAYER_5x12 ),
[_MOUSE]   = LAYOUT_ergo_5x12_expand( MOUSE_LAYER_5x12 , THUMB_DEFAULT_LAYER_5x12 ),
[_LOWER]   = LAYOUT_ergo_5x12_expand(
    NUMBER_ROW,
    ortho_2x12_expand(LOWER_LAYER_L, LOWER_LAYER_R),
    _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END , _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,
    BLANK_HALF, BLANK_HALF,
    THUMB_DEFAULT_LAYER_5x12
),
[_RAISE]   = LAYOUT_ergo_5x12_expand(
    NUMBER_ROW,
    ortho_2x12_expand(RAISE_LAYER_L, RAISE_LAYER_R),
    _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END , _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
    BLANK_HALF, BLANK_HALF,
    THUMB_DEFAULT_LAYER_5x12
),


/* Adjust (Lower + Raise)
 *                      ┌──────┐                                            ┌──────┐
 *               ┌──────┤  F3  ├──────┐                              ┌──────┤RGB H+├──────┐
 * ┌──────┬──────┤  F2  ├──────┤  F4  ├──────┐                ┌──────┤RGB H-├──────┤RGB S-├──────┬──────┐
 * │      │  F1  ├──────┤  F7  ├──────┤RGB TG│                │ RESET├──────┤NumPad├──────┤RGB S+│Sleep │
 * ├──────┼──────┤  F6  ├──────┤  F8  ├──────┤                ├──────┤ Game ├──────┤Mouse ├──────┼──────┤
 * │      │  F5  ├──────┤  F11 ├──────┤RGB V+│                │      ├──────┤Colmak├──────┤      │      │
 * ├──────┼──────┤  F10 ├──────┤  F12 ├──────┤                ├──────┤Qwerty├──────┤WorkMn├──────┼──────┤
 * │ CAPS │  F9  ├──────┤      ├──────┤RBG V-│                │      ├──────┤ Left ├──────┤Dvorak│      │
 * ├──────┼──────┤      ├──────┤      ├──────┤                ├──────┤      ├──────┤ Down ├──────┼──────┤
 * │      │      ├──────┘      └──────┤RGB M │┌──────┐┌──────┐│      ├──────┘      └──────┤  Up  │Right │
 * └──────┴──────┘           ┌──────┐ └──────┘│      ││      │└──────┘ ┌──────┐           └──────┴──────┘
 *                           │      ├──────┐ ┌┴─────┬┘└┬─────┴┐ ┌──────┤      │
 *                           └──────┤      │ │      │  │      │ │      ├──────┘
 *                                  └──────┘ └──────┘  └──────┘ └──────┘
 */
[_ADJUST] = LAYOUT_expand(
  _______, KC_F1  ,  KC_F2 , KC_F3  , KC_F4  , RGB_TOG,                   RESET  , RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_SLEP,
  _______, KC_F5  ,  KC_F6 , KC_F7  , KC_F8  , RGB_VAI,                   _______, TO_GAME, TO_NUM , TO_MS  , _______, _______,
  KC_CAPS, KC_F9  ,  KC_F10, KC_F11 , KC_F12 , RGB_VAD,                   _______, QWERTY , COLEMAK, WORKMAN, DVORAK , _______,
  _______, _______, _______, _______, _______, RGB_MOD, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
                                      _______, _______, _______, _______, _______, _______
),
};

