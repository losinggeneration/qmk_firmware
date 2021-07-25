#include "losinggeneration.h"

__attribute__ ((weak)) void persistent_default_layer_set(uint16_t default_layer) {
  layer_state_set(default_layer);
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

__attribute__ ((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ACL0:
      if (record->event.pressed) {
        mk_interval = 12;
        mk_max_speed = 4;
      } else {
        mk_interval = MOUSEKEY_INTERVAL;
        mk_max_speed = MOUSEKEY_MAX_SPEED;
      }
      return false;
      break;
    case KC_ACL1:
      if (record->event.pressed) {
        mk_interval = 10;
        mk_max_speed = 72;
      } else {
        mk_interval = MOUSEKEY_INTERVAL;
        mk_max_speed = MOUSEKEY_MAX_SPEED;
      }
      return false;
      break;
    case KC_ACL2:
      if (record->event.pressed) {
        mk_interval = 5;
        mk_max_speed = 60;
      } else {
        mk_interval = MOUSEKEY_INTERVAL;
        mk_max_speed = MOUSEKEY_MAX_SPEED;
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        PLAY_SONG(tone_qwerty);
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        PLAY_SONG(tone_colemak);
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        PLAY_SONG(tone_workman);
        persistent_default_layer_set(1UL<<_WORKMAN);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        PLAY_SONG(tone_dvorak);
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }

  return true;
}
