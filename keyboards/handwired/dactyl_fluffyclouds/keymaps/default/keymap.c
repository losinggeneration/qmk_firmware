/* A QWERTY 3 Layer layout for the Dactyl Manuform 6x6 Keyboard */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_DVORAK] = LAYOUT_6x6(
     KC_TILD ,  KC_1  , KC_2  , KC_3  , KC_4   , KC_5   ,      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
     KC_TAB  , KC_QUOT,KC_COMM, KC_DOT, KC_P   , KC_Y   ,      KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSPC,
     KC_ESC  , KC_A   , KC_O  , KC_E  , KC_U   , KC_I   ,      KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_SLSH,
     KC_LSFT , KC_SCLN, KC_Q  , KC_J  , KC_K   , KC_X   ,      KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_ENT ,
     KC_PLUS , KC_HOME, KC_END,KC_PGUP, KC_PGDN,                        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_EQL ,
                                        KC_LGUI, KC_LALT,      KC_RALT, KC_RGUI,
                                                 LOWER  ,      RAISE  ,
                              KC_BSPC , KC_ENT , KC_LCTL,      KC_RCTL, KC_ENT, KC_SPC
  ),


  [_LOWER] = LAYOUT_6x6(
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,         KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,         KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,         KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,         KC_P0  , KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
     _______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,
                                     _______,_______,         _______,_______,
                                             _______,         _______,
                             _______,_______,_______,         _______,_______,_______
),

  [_RAISE] = LAYOUT_6x6(
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,         KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     _______,_______,_______,_______,_______,KC_LBRC,         KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
     _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,         KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
     _______,_______,_______,_______,_______,_______,         _______,_______,_______,_______,_______,KC_VOLD,
     _______,_______,_______,_______,_______,                         _______,_______,_______,_______,_______,
                                     _______,_______,         _______,_______,
                                             _______,         _______,
                             _______,_______,_______,         _______,_______,_______
  ),

  };
