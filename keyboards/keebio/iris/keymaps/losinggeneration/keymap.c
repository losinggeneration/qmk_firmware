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

/* Epand macros passed into LAYOUT because the default don't expand arguments. */
#define LAYOUT_ergo_4x12_expand(...) LAYOUT_ergo_4x12(__VA_ARGS__)
#define LAYOUT_expand(...) LAYOUT(__VA_ARGS__)

#define THUMB_TRANS_LAYER                               \
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
#define THUMB_DEFAULT_LAYER                             \
           _______, _______, _______, KC_DEL ,          \
                    KC_LGUI, TD_CTL ,                   \
  KC_LGUI,  LOWER , KC_LSFT, KC_SPC , RAISE  , KC_LGUI


extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY]  = LAYOUT_ergo_4x12_expand( QWERTY_LAYER_4x12,  THUMB_DEFAULT_LAYER ),
[_COLEMAK] = LAYOUT_ergo_4x12_expand( COLEMAK_LAYER_4x12, THUMB_DEFAULT_LAYER ),
[_WORKMAN] = LAYOUT_ergo_4x12_expand( WORKMAN_LAYER_4x12, THUMB_DEFAULT_LAYER ),
[_DVORAK]  = LAYOUT_ergo_4x12_expand( DVORAK_LAYER_4x12,  THUMB_DEFAULT_LAYER ),
[_GAME]    = LAYOUT_ergo_4x12_expand( GAME_LAYER_4x12,    THUMB_DEFAULT_LAYER ),
[_NUMPAD]  = LAYOUT_ergo_4x12_expand( NUMPAD_LAYER_4x12,  THUMB_DEFAULT_LAYER ),
[_MOUSE]   = LAYOUT_ergo_4x12_expand( MOUSE_LAYER_4x12,   THUMB_DEFAULT_LAYER ),
[_LOWER]   = LAYOUT_ergo_4x12_expand( LOWER_LAYER_4x12,   THUMB_DEFAULT_LAYER ),
[_RAISE]   = LAYOUT_ergo_4x12_expand( RAISE_LAYER_4x12,   THUMB_DEFAULT_LAYER ),


/* Adjust (Lower + Raise)
 *                      ┌──────┐                                            ┌──────┐
 *               ┌──────┤  F3  ├──────┐                              ┌──────┤NumPad├──────┐
 * ┌──────┬──────┤  F2  ├──────┤  F4  ├──────┐                ┌──────┤Game  ├──────┤Mouse ├──────┬──────┐
 * │      │  F1  ├──────┤  F7  ├──────┤RGB TG│                │ RESET├──────┤Colmak├──────┤      │Sleep │
 * ├──────┼──────┤  F6  ├──────┤  F8  ├──────┤                ├──────┤Qwerty├──────┤Workmn├──────┼──────┤
 * │      │  F5  ├──────┤  F11 ├──────┤RGB V+│                │ Midi ├──────┤      ├──────┤Dvorak│      │
 * ├──────┼──────┤  F10 ├──────┤  F12 ├──────┤                ├──────┤RGB S+├──────┤      ├──────┼──────┤
 * │ CAPS │  F9  ├──────┤      ├──────┤RBG V-│                │RGB H+├──────┤ XXX  ├──────┤  Up  │      │
 * ├──────┼──────┤      ├──────┤      ├──────┤                ├──────┤RGB S-├──────┤ Left ├──────┼──────┤
 * │      │      ├──────┘      └──────┤RGB M │┌──────┐┌──────┐│RGB H-├──────┘      └──────┤ Down │Right │
 * └──────┴──────┘           ┌──────┐ └──────┘│      ││      │└──────┘ ┌──────┐           └──────┴──────┘
 *                           │      ├──────┐ ┌┴─────┬┘└┬─────┴┐ ┌──────┤      │
 *                           └──────┤      │ │      │  │      │ │      ├──────┘
 *                                  └──────┘ └──────┘  └──────┘ └──────┘
 */
[_ADJUST] = LAYOUT_expand( \
  _______, KC_F1  ,  KC_F2 , KC_F3  , KC_F4  , RGB_TOG,                   RESET  , TO_GAME, TO_NUM , TO_MS  , _______, KC_SLEP, \
  _______, KC_F5  ,  KC_F6 , KC_F7  , KC_F8  , RGB_VAI,                   _______, QWERTY , COLEMAK, WORKMAN, DVORAK , _______, \
  KC_CAPS, KC_F9  ,  KC_F10, KC_F11 , KC_F12 , RGB_VAD,                   RGB_HUI, RGB_SAI, _______, _______, KC_UP  , _______, \
  _______, _______, _______, _______, _______, RGB_MOD, _______, _______, RGB_HUD, RGB_SAD, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,  \
                                      _______, _______, _______, _______, _______, _______
),
};

