#include QMK_KEYBOARD_H
#include "losinggeneration-config.h"
#include "losinggeneration-keymap.h"

#if 0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LCTL, KC_LALT, KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_DLR,  KC_PERC,                  KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC,
    KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                  KC_PGDN, KC_4,    KC_5,   KC_6, KC_BSLS,
    KC_LBRC, KC_RBRC, KC_HASH, KC_LBRC, KC_RBRC, KC_CIRC, KC_AMPR,KC_ASTR, KC_1,    KC_2,   KC_3, KC_PLUS,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,   _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )
};
#endif

/*
 * ┌───────┬───────┬───────┬───────┬───────┬───────┐┌───────┬───────┬───────┬───────┬───────┬───────┐
 * │Adjust │ Ctrl  │  Alt  │  GUI  │ SHIFT │ Bksp  ││ Enter │ Space │ Left  │ Down  │   Up  │ Right │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
#undef BOTTOM_ROW
#define BOTTOM_ROW(KC_ANY) \
    KC_TAB , TD_CTL, TD_ALT, LOWER ,KC_LSFT,KC_BSPC,KC_ENTER, KC_SPC, RAISE , KC_DEL, KC_ANY, KC_ESC


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY]  = CATMAP(
/* Qwerty
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │   Q   │    W  │    E  │   R   │   T   │                │   Y   │   U   │   I   │   O   │   P   │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │   A   │    S  │    D  │   F   │   G   │                │   H   │   J   │   K   │   L   │   ;   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │   Z   │    X  │    C  │   V   │   B   │       ││       │   N   │   M   │   ,   │   .   │   /   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │ Adjust│ Ctrl  │  Alt  │  GUI  │ Bksp  │ Lower ││ Raise │ Space │  Left │  Down │  Up   │ Right │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
      KC_Q , KC_W  , KC_E  , KC_R  , KC_T  ,                 KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,
      KC_A , KC_S  , KC_D  , KC_F  , KC_G  ,                 KC_H  , KC_J  ,  KC_K , KC_L  ,KC_SCLN,
      KC_Z , KC_X  , KC_C  , KC_V  , KC_B  , TD_GUI, TD_ADJ, KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,
      BOTTOM_ROW(KC_QUOT)
),

/* Colemak
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │   Q   │   W   │   F   │   P   │   G   │                │   J   │   L   │   U   │   Y   │   ;   │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │   A   │   R   │   S   │   T   │   D   │                │   H   │   N   │   E   │   I   │   O   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │   Z   │   X   │   C   │   V   │   B   │       ││       │   K   │   M   │   ,   │   .   │   /   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │ Adjust│ Ctrl  │  Alt  │  GUI  │ Bkspc │ Lower ││ Raise │ Space │  Left │  Down │   Up  │ Right │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
[_COLEMAK] = CATMAP(
    KC_Q   , KC_W   , KC_F , KC_P  , KC_G  ,                   KC_J ,  KC_L ,  KC_U ,  KC_Y ,KC_SCLN,
    KC_A   , KC_R   , KC_S , KC_T  , KC_D  ,                   KC_H ,  KC_N ,  KC_E ,  KC_I ,  KC_O ,
    KC_Z   , KC_X   , KC_C , KC_V  , KC_B  , TD_GUI, TD_ADJ ,  KC_K ,  KC_M ,KC_COMM, KC_DOT,KC_SLSH,
   BOTTOM_ROW(KC_QUOT)
),

/* Dvorak
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │   "   │    ,  │    .  │   P   │   Y   │                │   F   │   G   │   C   │   R   │   L   │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │   A   │    O  │    E  │   U   │   I   │                │   D   │   H   │   T   │   N   │   S   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │   ;   │    Q  │    J  │   K   │   X   │  GUI  ││ Adjust│   B   │   M   │   W   │   V   │   Z   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │  Tab  │ Ctrl  │  Alt  │ Lower │ Shift │ Bkspc ││ Enter │ Space │ Raise │  Del  │   /   │  Esc  │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
[_DVORAK]  = CATMAP(
    KC_QUOT,KC_COMM, KC_DOT,  KC_P ,  KC_Y ,                   KC_F ,  KC_G ,  KC_C ,  KC_R ,  KC_L ,
    KC_A   , KC_O  ,  KC_E ,  KC_U ,  KC_I ,                   KC_D ,  KC_H ,  KC_T ,  KC_N ,  KC_S ,
    KC_SCLN, KC_Q  ,  KC_J ,  KC_K ,  KC_X , TD_GUI,  TD_ADJ,  KC_B ,  KC_M ,  KC_W ,  KC_V ,  KC_Z ,
    BOTTOM_ROW(KC_SLSH)
),

#if 0
/* Game (Qwerty without one shot modifiers & tap dancing)
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │    Q  │    W  │    E  │    R  │    T  │                │    Y  │    U  │    I  │    O  │    P  │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │    A  │    S  │    D  │    F  │    G  │                │    H  │    J  │    K  │    L  │    ;  │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │    Z  │    X  │    C  │    V  │    B  │       ││       │    N  │    M  │    ,  │    .  │    /  │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │ Adjust│  Ctrl │  Alt  │  GUI  │ Lower │ Space ││ Space │ Raise │  Left │  Down │   Up  │ Right │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
[_GAME]    = CATMAP(
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC, \
  KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT , \
  MO_ADJ , KC_LCTL, KC_LALT, KC_LGUI, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

/* Number pad
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │  Tab  │  XXX  │  XXX  │  XXX  │  XXX  │                │    7  │   8   │   9   │  -    │  BKSP │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │  Esc  │  XXX  │  XXX  │  XXX  │  XXX  │                │    4  │   5   │   6   │  +    │  BKSP │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │ Shift │  XXX  │  XXX  │  XXX  │  XXX  │  XXX  ││   /   │    1  │   2   │   3   │  ENT  │  XXX  │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │ Adjust│  Ctrl │  Alt  │  GUI  │  XXX  │ Space ││ Space │    *  │   0   │   .   │  ENT  │  NLCK │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
[_NUMPAD]  = CATMAP(
  KC_TAB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, KC_BSPC, \
  KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_BSPC, \
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_P1  , KC_P2  , KC_P3  , KC_PENT, XXXXXXX, \
  TD_ADJ , TD_CTL , TD_ALT , TD_GUI , XXXXXXX, KC_SPC , KC_SPC , KC_P0  , KC_P0  , KC_PDOT, KC_PENT, XXXXXXX
),

/* Mouse movement
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │       │       │       │       │       │                │       │       │       │       │       │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │       │       │       │       │       │                │       │       │       │       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │       │       │       │       │       ││       │       │       │       │       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │       │       │       │       │       ││       │       │       │       │       │       │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 * ,-----------------------------------------------..-----------------------------------------------.
 * |  Tab  |  MB_1 |  MB_3 |  MB_2 |  MB_4 |  MB_5 || MA_0  | MB_1  | MB_3  | MB_2  | MB_4  | MB_5  |
 * |-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------|
 * |  Esc  |  MW_L |  MW_U |  MW_D |  MW_R |  XXX  || MA_1  | M_LT  | M_UP  | M_DN  | M_RT  | XXX   |
 * |-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------|
 * | Shift |  MA_0 |  MA_1 |  MA_2 |  XXX  |  XXX  || MA_2  | MW_L  | MW_U  | MW_D  | MW_R  | XXX   |
 * |-------+-------+-------+-------+-------+-------||-------+-------+-------+-------+-------+-------|
 * | Adjust|  Ctrl |  Alt  |  GUI  |  XXX  | Space || XXX   | XXX   | XXX   |  XXX  | XXX   | XXX   |
 * `-----------------------------------------------''-----------------------------------------------'
 */
[_MOUSE]   = CATMAP(
  KC_TAB , MS_BTN1, MS_BTN3, MS_BTN2, MS_BTN4, MS_BTN5, MS_ACL0, MS_BTN1, MS_BTN3, MS_BTN2, MS_BTN4, MS_BTN5, \
  KC_ESC , MW_LEFT, MW_DOWN, MW_UP  , MW_RGHT, XXXXXXX, MS_ACL1, MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX, \
  KC_LSFT, MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX, XXXXXXX, MS_ACL2, MW_LEFT, MW_DOWN, MW_UP  , MW_RGHT, XXXXXXX, \
  TD_ADJ , TD_CTL , TD_ALT , TD_GUI , XXXXXXX, KC_SPC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
#endif

/* Lower
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │   !   │   @   │   #   │   $   │   %   │                │   ^   │   &   │   *   │   (   │   )   │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │   -   │   =   │   [   │   ]   │   \   │                │   |   │   _   │   +   │   {   │   }   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │   ~   │   `   │   /   │       │       │       ││       │ PgUp  │ PgDn  │ Home  │ End   │  ⏹    │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │       │       │       │       │       ││       │       │ Mute  │ Vol   │ Vol   │  ⏯    │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
[_LOWER]   = CATMAP(
    KC_EXLM, KC_AT ,KC_HASH, KC_DLR,KC_PERC,                 KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,
    KC_MINS, KC_EQL,KC_LBRC,KC_RBRC,KC_BSLS,                 KC_PIPE,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,
    _______,_______,_______,_______,_______,_______,_______, KC_PGUP,KC_PGDN,KC_HOME, KC_END, KC_MSTP, \
    _______,_______,_______,_______,_______,KC_BSPC,_______,_______,KC_LEFT, KC_DOWN,  KC_UP ,KC_RGHT
),

/* Raise
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │   1   │   2   │   3   │   4   │   5   │                │   6   │   7   │   8   │   9   │   0   │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │   !   │   @   │   #   │   $   │   %   │                │   ^   │   &   │   *   │   (   │   )   │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │   ~   │   `   │   /   │       │       │       ││       │ PgUp  │ PgDn  │ Home  │ End   │  ⏹    │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │       │       │       │       │       ││       │       │ Mute  │ Vol   │ Vol   │  ⏯    │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
[_RAISE]   = CATMAP(
    KC_1   , KC_2  , KC_3  , KC_4  ,  KC_5 ,                    KC_6,  KC_7 ,  KC_8 ,  KC_9 ,  KC_0 ,
    KC_EXLM, KC_AT ,KC_HASH, KC_DLR,KC_PERC,                 KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,
    KC_TILD, KC_GRV,KC_SLSH,_______,_______,_______,_______, KC_PGUP,KC_PGDN,KC_HOME, KC_END, KC_MSTP, \
    KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,_______,KC_BSPC,_______,_______,KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ┌───────┬───────┬───────┬───────┬───────┐                ┌───────┬───────┬───────┬───────┬───────┐
 * │       │   F1  │   F2  │   F3  │   F4  │                │  Game │ Numpad│ Mouse │       │ Sleep │
 * ├───────┼───────┼───────┼───────┼───────┤                ├───────┼───────┼───────┼───────┼───────┤
 * │       │   F5  │   F6  │   F7  │   F8  │                │ Qwerty│ Dvorak│Colemak│       │       │
 * ├───────┼───────┼───────┼───────┼───────┼───────┐┌───────┼───────┼───────┼───────┼───────┼───────┤
 * │  CAPS │   F9  │   F10 │   F11 │   F12 │       ││       │       │       │       │       │ RESET │
 * ├───────┼───────┼───────┼───────┼───────┼───────┤├───────┼───────┼───────┼───────┼───────┼───────┤
 * │       │       │       │       │       │       ││       │       │       │       │       │       │
 * └───────┴───────┴───────┴───────┴───────┴───────┘└───────┴───────┴───────┴───────┴───────┴───────┘
 */
[_ADJUST] = CATMAP( \
    /*_______,  KC_F1, KC_F2 , KC_F3 , KC_F4 ,                 TO_GAME, TO_NUM, TO_MS ,_______,KC_SLEP, \*/
    _______,  KC_F1, KC_F2 , KC_F3 , KC_F4 ,                 _______,_______,_______,_______,KC_SLEP, \
    _______,  KC_F5, KC_F6 , KC_F7 , KC_F8 ,                 QWERTY , DVORAK,COLEMAK,_______,_______, \
    KC_CAPS,  KC_F9, KC_F10, KC_F11, KC_F12,_______, _______,_______,_______,_______,_______, RESET , \
    _______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______  \
)

};

