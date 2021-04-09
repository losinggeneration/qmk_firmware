#include "tap_dances.h"

/*
  Used to indicate a CTRL should be pressed on one press, or CTRL+ALT on
  a double tap
*/
void dance_ctl_ctlalt_each(qk_tap_dance_state_t *state, void *user_data) {
  register_code(KC_LCTL);
  if(state->count > 1) {
    register_code(KC_LALT);
  }
}

/* Used to release CTRL or the double tapped variant CTRL+ALT */
void dance_ctl_ctlalt_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LCTL);
  if(state->count > 1) {
    unregister_code(KC_LALT);
  }
}

/*
  Set ADJUST layer on the first press and off after that.
  Each is used to make sure ADJUST activates as soon as it's pressed the first
  time.
*/
void dance_adj_each(qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    layer_on(_ADJUST);
  } else {
    layer_off(_ADJUST);
  }
}

/* Set NUMPAD layer on second tap and MOUSE layer on 3rd */
void dance_adj_finish(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1: break;
    case 2:
      layer_on(_NUMPAD);
      break;
    case 3:
      layer_on(_MOUSE);
      break;
    default:
      reset_tap_dance(state);
      break;
  }
}

/* Turn off any layer that may have been tapped on */
void dance_adj_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1:
      layer_off(_ADJUST);
      break;
    case 2:
      layer_off(_NUMPAD);
      break;
    case 3:
      layer_off(_MOUSE);
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTL_CTLALT] = ACTION_TAP_DANCE_FN_ADVANCED(dance_ctl_ctlalt_each, NULL, dance_ctl_ctlalt_reset),
  [TD_LGUI_RGUI]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_RGUI),
  [TD_LALT_RALT]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
  [TD_ADJUST]     = ACTION_TAP_DANCE_FN_ADVANCED(dance_adj_each, dance_adj_finish, dance_adj_reset),
};

