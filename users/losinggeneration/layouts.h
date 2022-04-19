#pragma once

#include "losinggeneration.h"

#include "action_layer.h"
#include "eeconfig.h"
#include "mousekey.h"

#define ortho_2x12(             \
  /* left hand */               \
  K00, K01, K02, K03, K04, K05, \
  K10, K11, K12, K13, K14, K15, \
  /* right hand */              \
  K06, K07, K08, K09, K0A, K0B, \
  K16, K17, K18, K19, K1A, K1B  \
) \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B

#define ortho_2x12_expand(...) ortho_2x12(__VA_ARGS__)

/*
 * Take a left & right side to combine.
 *  Left side
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┘
 * Right side
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┐
 * │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┘
 * │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┘
 * Tab row
 * ┌──────┐┌──────┐
 * │      ││      │
 * └──────┘└──────┘
 * Escape row
 * ┌──────┐
 * │      │
 * └──────┘
 * Shift row
 * ┌──────┐┌──────┐
 * │      ││      │
 * └──────┘└──────┘
 * Bottom row
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      ││      │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define ortho_4x12(                                           \
  /* left hand */                                             \
  K01, K02, K03, K04, K05,                                    \
  K11, K12, K13, K14, K15,                                    \
  K21, K22, K23, K24, K25,                                    \
  /* right hand */                                            \
  K06, K07, K08, K09, K0A,                                    \
  K16, K17, K18, K19, K1A, K1B,                               \
  K26, K27, K28, K29, K2A,                                    \
  /* Tab row */                                               \
  K00, K0B,                                                   \
  /* Esc row */                                               \
  K10,                                                        \
  /* Sft row */                                               \
  K20, K2B,                                                   \
  /* Bottom row */                                            \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B  \
)                                                             \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B  \

#define ortho_5x12(                                           \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, \
  K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B  \
)                                                             \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, \
  K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B  \

/* This will expand the macro when used in another macro that uses __VA_ARGS__ */
#define ortho_4x12_expand(...) ortho_4x12(__VA_ARGS__)
#define ortho_5x12_expand(...) ortho_5x12(__VA_ARGS__)

/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Adjust│ Ctrl │ Alt  │ GUI  │Lower │ Shft │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BOTTOM_GRID_ROW_L \
  TD_ADJ  ,TD_CTL , TD_ALT , TD_GUI , LOWER  , KC_LSFT

/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Space │Raise │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BOTTOM_GRID_ROW_R \
  KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT

#define BOTTOM_GRID_ROW \
  BOTTOM_GRID_ROW_L, BOTTOM_GRID_ROW_R

/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Adjust│ Ctrl │ Alt  │ GUI  │Lower │Space │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BOTTOM_MIT_ROW_L \
  TD_ADJ  ,TD_CTL , TD_ALT , TD_GUI , LOWER  , KC_SPC
/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │Space │Raise │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BOTTOM_MIT_ROW_R \
  KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT

#define BOTTOM_MIT_ROW \
  BOTTOM_MIT_ROW_L, BOTTOM_MIT_ROW_R

/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BLANK_HALF \
  _______, _______, _______, _______, _______, _______


#ifdef USE_MIT_LAYOUT
#define BOTTOM_ROW BOTTOM_MIT_ROW

/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BOTTOM_RAISE_LOWER_ROWS_L \
  BLANK_HALF, \
  BLANK_HALF

/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │ PgUp │ PgDn │ Home │ End  │  ⏹   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │ Mute │ Vol- │ Vol+ │  ⏯   │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BOTTOM_RAISE_LOWER_ROWS_R \
   _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END , KC_MSTP, \
   _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY

#else /* Grid */
#define BOTTOM_ROW BOTTOM_GRID_ROW

/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │ Bksp │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BOTTOM_RAISE_LOWER_ROWS_L \
  BLANK_HALF, \
  _______, _______, _______, _______, _______, KC_BSPC
/*
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │ PgUp │ PgDn │ Home │ End  │  ⏹   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │ Mute │ Vol- │ Vol+ │  ⏯   │
 * └──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define BOTTOM_RAISE_LOWER_ROWS_R \
  _______, KC_PGUP, KC_PGDN, KC_HOME, KC_END , KC_MSTP, \
  _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
#endif

#define BOTTOM_RAISE_LOWER_ROWS ortho_2x12_expand( \
    BOTTOM_RAISE_LOWER_ROWS_L, BOTTOM_RAISE_LOWER_ROWS_R \
)

/* R1
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │   1  │   2  │   3  │   4  │   5  ││   6  │   7  │   8  │   9  │   9  │ Del  │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define NUMBER_ROW \
  KC_GRV  ,KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL

/* R2
 * ┌──────┬──────────────────────────────────┐┌──────────────────────────────────┬──────┐
 * │ Tab  │                                  ││                                  │ Bksp │
 * └──────┴──────────────────────────────────┘└──────────────────────────────────┴──────┘
 */
#define STD_TAB KC_TAB, KC_BSPC

/* R3
 * ┌──────┬──────────────────────────────────┐┌─────────────────────────────────────────┐
 * │ Esc  │                                  ││                                         │
 * └──────┴──────────────────────────────────┘└─────────────────────────────────────────┘
 */

#define STD_ESC MT_ESC

/* R4
 * ┌──────┬──────────────────────────────────┐┌──────────────────────────────────┬──────┐
 * │ Shift│                                  ││                                  │Enter │
 * └──────┴──────────────────────────────────┘└──────────────────────────────────┴──────┘
 */
#define STD_LSFT OSM_LSFT, MT_ENT

/* Qwerty Left Hand
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │   Q  │   W  │   E  │   R  │   T  │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │   A  │   S  │   D  │   F  │   G  │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │   Z  │   X  │   C  │   V  │   B  │
 * └──────┴──────┴──────┴──────┴──────┘
 */
#define QWERTY_LAYER_L \
  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , \
  KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , \
  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B     \

/* Qwerty Right Hand
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │   Y  │   U  │   I  │   O  │   P  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┐
 * │   H  │   J  │   K  │   L  │   ;  │  "   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┘
 * │   N  │   M  │   ,  │   .  │   /  │
 * └──────┴──────┴──────┴──────┴──────┘
 */
#define QWERTY_LAYER_R \
  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,          \
  KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH           \


/* Qwerty
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  ││   Y  │   U  │   I  │   O  │   P  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │   A  │   S  │   D  │   F  │   G  ││   H  │   J  │   K  │   L  │   ;  │  "   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│   Z  │   X  │   C  │   V  │   B  ││   N  │   M  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Adjust│ Ctrl │ Alt  │ GUI  │Lower │ Del  ││Space │Raise │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define QWERTY_LAYER_4x12 ortho_4x12_expand( \
  QWERTY_LAYER_L, \
  QWERTY_LAYER_R, \
  STD_TAB,        \
  STD_ESC,        \
  STD_LSFT,       \
  BOTTOM_ROW      \
)

#define QWERTY_LAYER_5x12 ortho_5x12_expand(NUMBER_ROW, QWERTY_LAYER_4x12)

/* Colemak-DH Left Hand
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │   Q  │   W  │   F  │   P  │   B  │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │   A  │   R  │   S  │   T  │   G  │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │   Z  │   X  │   C  │   D  │   V  │
 * └──────┴──────┴──────┴──────┴──────┘
 */
#define COLEMAK_LAYER_L \
  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , \
  KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , \
  KC_Z   , KC_X   , KC_C   , KC_D   , KC_V     \

/* Colemak-DH Right Hand
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │   J  │   L  │   U  │   Y  │   ;  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┐
 * │   M  │   N  │   E  │   I  │   O  │  "   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┘
 * │   K  │   H  │   ,  │   .  │   /  │
 * └──────┴──────┴──────┴──────┴──────┘
 */
#define COLEMAK_LAYER_R \
  KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN,           \
  KC_M   , KC_N   , KC_E   , KC_I   , KC_O   ,  KC_QUOT, \
  KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH            \


/* Colemak-DH
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Tab  │   Q  │   W  │   F  │   P  │   B  ││   J  │   L  │   U  │   Y  │   ;  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │   A  │   R  │   S  │   T  │   G  ││   M  │   N  │   E  │   I  │   O  │  "   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│   Z  │   X  │   C  │   D  │   V  ││   K  │   H  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Adjust│ Ctrl │ Alt  │ GUI  │Lower │ Del  ││Space │Raise │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define COLEMAK_LAYER_4x12 ortho_4x12_expand( \
  COLEMAK_LAYER_L, \
  COLEMAK_LAYER_R, \
  STD_TAB,         \
  STD_ESC,         \
  STD_LSFT,        \
  BOTTOM_ROW       \
)

#define COLEMAK_LAYER_5x12 ortho_5x12_expand(NUMBER_ROW, COLEMAK_LAYER_4x12)

/* Workman Left Hand
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │   Q  │   D  │   R  │   W  │   B  │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │   A  │   S  │   H  │   T  │   G  │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │   Z  │   X  │   M  │   C  │   V  │
 * └──────┴──────┴──────┴──────┴──────┘
 */
#define WORKMAN_LAYER_L \
  KC_Q   , KC_D   , KC_R   , KC_W   , KC_B   , \
  KC_A   , KC_S   , KC_H   , KC_T   , KC_G   , \
  KC_Z   , KC_X   , KC_M   , KC_C   , KC_V     \

/* Workman Right Hand
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │   J  │   F  │   U  │   P  │   ;  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┐
 * │   Y  │   N  │   E  │   O  │   I  │  "   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┘
 * │   K  │   L  │   ,  │   .  │   /  │
 * └──────┴──────┴──────┴──────┴──────┘
 */
#define WORKMAN_LAYER_R \
  KC_J   , KC_F   , KC_U   , KC_P   , KC_SCLN,          \
  KC_Y   , KC_N   , KC_E   , KC_O   , KC_I   , KC_QUOT, \
  KC_K   , KC_L   , KC_COMM, KC_DOT , KC_SLSH           \

/* Workman
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Tab  │   Q  │   D  │   R  │   W  │   B  ││   J  │   F  │   U  │   P  │   ;  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │   A  │   S  │   H  │   T  │   G  ││   Y  │   N  │   E  │   O  │   I  │  "   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│   Z  │   X  │   M  │   C  │   V  ││   K  │   L  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Adjust│ Ctrl │ Alt  │ GUI  │Lower │ Del  ││Space │Raise │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define WORKMAN_LAYER_4x12 ortho_4x12_expand( \
  WORKMAN_LAYER_L, \
  WORKMAN_LAYER_R, \
  STD_TAB,         \
  STD_ESC,         \
  STD_LSFT,        \
  BOTTOM_ROW       \
)

#define WORKMAN_LAYER_5x12 ortho_5x12_expand(NUMBER_ROW, WORKMAN_LAYER_4x12)

/* Dvorak Left Hand
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │   "  │   ,  │   .  │   P  │   Y  │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │   A  │   O  │   E  │   U  │   I  │
 * ├──────┼──────┼──────┼──────┼──────┤
 * │   ;  │   Q  │   J  │   K  │   X  │
 * └──────┴──────┴──────┴──────┴──────┘
 */
#define DVORAK_LAYER_L \
  KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y , \
  KC_A   , KC_O   , KC_E   , KC_U   , KC_I , \
  KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   \

/* Dvorak Right Hand
 * ┌──────┬──────┬──────┬──────┬──────┐
 * │   F  │   G  │   C  │   R  │   L  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┐
 * │   D  │   H  │   T  │   N  │   S  │  /   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┘
 * │   B  │   M  │   W  │   V  │   Z  │
 * └──────┴──────┴──────┴──────┴──────┘
 */
#define DVORAK_LAYER_R \
  KC_F   , KC_G   , KC_C   , KC_R   , KC_L   ,          \
  KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_SLSH, \
  KC_B   , KC_M   , KC_W   , KC_V   , KC_Z              \


/* Dvorak
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Tab  │   "  │   ,  │   .  │   P  │   Y  ││   F  │   G  │   C  │   R  │   L  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │   A  │   O  │   E  │   U  │   I  ││   D  │   H  │   T  │   N  │   S  │  /   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│   ;  │   Q  │   J  │   K  │   X  ││   B  │   M  │   W  │   V  │   Z  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Adjust│ Ctrl │ Alt  │ GUI  │Lower │ Del  ││Space │Raise │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define DVORAK_LAYER_4x12 ortho_4x12_expand( \
  DVORAK_LAYER_L, \
  DVORAK_LAYER_R, \
  STD_TAB,        \
  STD_ESC,        \
  STD_LSFT,       \
  BOTTOM_ROW      \
)

#define DVORAK_LAYER_5x12 ortho_5x12_expand(NUMBER_ROW, DVORAK_LAYER_4x12)

/* Game (Qwerty without one shot modifiers & tap dancing)
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  ││   Y  │   U  │   I  │   O  │   P  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │   A  │   S  │   D  │   F  │   G  ││   H  │   J  │   K  │   L  │   ;  │  "   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shift│   Z  │   X  │   C  │   V  │   B  ││   N  │   M  │   ,  │   .  │   /  │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Adjust│ Ctrl │ Alt  │ GUI  │Lower │Space ││Space │Raise │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define GAME_LAYER_4x12 ortho_4x12_expand( \
  QWERTY_LAYER_L,   \
  QWERTY_LAYER_R,   \
  KC_TAB , KC_BSPC, \
  KC_ESC ,          \
  KC_LSFT, KC_ENT , \
  MO_ADJ , KC_LCTL, KC_LALT, KC_LGUI, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT \
)

#define GAME_LAYER_5x12 ortho_5x12_expand(NUMBER_ROW, GAME_LAYER_4x12)

#define XXX_1x5 \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define XXX_2x5 \
  XXX_1x5, XXX_1x5

#define XXX_3x5 \
  XXX_2x5, XXX_1x5

#define NUMPAD_R \
  KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS,          \
  KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_BSPC, \
  KC_PSLS, KC_P1  , KC_P2  , KC_P3  , KC_PENT           \

/* Number pad
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Tab  │ XXX  │ XXX  │ XXX  │ XXX  │ XXX  ││ NLCK │   7  │  8   │   9  │  -   │ BKSP │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │ XXX  │ XXX  │ XXX  │ XXX  │ XXX  ││  *   │   4  │  5   │   6  │  +   │ BKSP │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │ XXX  │ XXX  │ XXX  │ XXX  │ XXX  ││  /   │   1  │  2   │   3  │ ENT  │ XXX  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Adjust│ Ctrl │ Alt  │ GUI  │ XXX  │Space ││Space │   0  │  0   │   .  │ ENT  │ XXX  │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define NUMPAD_LAYER_4x12 ortho_4x12_expand( \
  XXX_3x5,          \
  NUMPAD_R,         \
  KC_TAB, KC_BSPC,  \
  KC_ESC,           \
  KC_LSFT, XXXXXXX, \
  TD_ADJ , TD_CTL , TD_ALT , TD_GUI , XXXXXXX, KC_SPC , KC_SPC , KC_P0  , KC_P0  , KC_PDOT, KC_PENT, XXXXXXX \
)

#define NUMPAD_LAYER_5x12 ortho_5x12_expand( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PAST, KC_PSLS, KC_BSPC, KC_BSPC, \
  NUMPAD_LAYER_4x12 \
)

#define MOUSE_L \
  MS_BTN1, MS_BTN3, MS_BTN2, MS_BTN4, MS_BTN5, \
  MW_LEFT, MW_DOWN, MW_UP  , MW_RGHT, XXXXXXX, \
  MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX, XXXXXXX  \

#define MOUSE_R \
  MS_ACL0, MS_BTN1, MS_BTN3, MS_BTN2, MS_BTN4,          \
  MS_ACL1, MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX, \
  MS_ACL2, MW_LEFT, MW_DOWN, MW_UP  , MW_RGHT           \

/* Mouse movement
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Tab  │ MB_1 │ MB_3 │ MB_2 │ MB_4 │ MB_5 ││ MA_0 │ MB_1 │ MB_3 │ MB_2 │ MB_4 │ MB_5 │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │ MW_L │ MW_U │ MW_D │ MW_R │ XXX  ││ MA_1 │ M_LT │ M_UP │ M_DN │ M_RT │ XXX  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Shift │ MA_0 │ MA_1 │ MA_2 │ XXX  │ XXX  ││ MA_2 │ MW_L │ MW_U │ MW_D │ MW_R │ XXX  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │Adjust│ Ctrl │ Alt  │ GUI  │ XXX  │Space ││ XXX  │ XXX  │ XXX  │  XXX │ XXX  │ XXX  │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define MOUSE_LAYER_4x12 ortho_4x12_expand( \
  MOUSE_L,          \
  MOUSE_R,          \
  KC_TAB , MS_BTN5, \
  KC_ESC ,          \
  KC_LSFT, XXXXXXX, \
  TD_ADJ , TD_CTL , TD_ALT , TD_GUI , XXXXXXX, KC_SPC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
)

#define MOUSE_LAYER_5x12 ortho_5x12_expand( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  MOUSE_LAYER_4x12 \
)

#define LOWER_LAYER_L \
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, \
  KC_DEL , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS  \

#define LOWER_LAYER_R \
  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD  \

/* Lower
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │   ~  │   !  │   @  │   #  │   $  │   %  ││   ^  │   &  │   *  │   (  │   )  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Del  │   -  │   =  │   [  │   ]  │   \  ││   │  │   _  │   +  │   {  │   }  │  ~   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ││      │ PgUp │ PgDn │ Home │ End  │  ⏹   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ││      │      │ Mute │ Vol- │ Vol+ │  ⏯   │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define LOWER_LAYER_4x12 \
  ortho_2x12_expand(LOWER_LAYER_L, LOWER_LAYER_R), \
  BOTTOM_RAISE_LOWER_ROWS

#define LOWER_LAYER_5x12 ortho_5x12_expand( \
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL , \
  LOWER_LAYER_4x12 \
)

#define RAISE_LAYER_L \
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , \
  KC_DEL , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC  \

#define RAISE_LAYER_R \
  KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV   \

/* Raise
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │   1  │   2  │   3  │   4  │   5  ││   6  │   7  │   8  │   9  │   0  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Del  │   !  │   @  │   #  │   $  │   %  ││   ^  │   &  │   *  │   (  │   )  │  `   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ││      │ PgUp │ PgDn │ Home │ End  │  ⏹   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ││      │      │ Mute │ Vol- │ Vol+ │  ⏯   │
 * └──────┴──────┴──────┴──────┴──────┴──────┘└──────┴──────┴──────┴──────┴──────┴──────┘
 */
#define RAISE_LAYER_4x12 \
  ortho_2x12_expand(RAISE_LAYER_L, RAISE_LAYER_R), \
  BOTTOM_RAISE_LOWER_ROWS

#define RAISE_LAYER_5x12 ortho_5x12_expand(NUMBER_ROW, RAISE_LAYER_4x12)

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_workman[][2]    = SONG(PLOVER_SOUND);
#else
float tone_qwerty;
float tone_dvorak;
float tone_colemak;
float tone_workman;
#define PLAY_SONG(tone)
#endif

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  WORKMAN,
  DVORAK,
  LOWER,
  RAISE,
};


