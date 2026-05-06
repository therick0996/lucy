// Tap dance stuff

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicative that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currently not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustrating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'email' tap dance.
static td_tap_t email_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void email_finished(tap_dance_state_t *state, void *user_data) {
    email_state.state = cur_dance(state);
    switch (email_state.state) {
      case TD_SINGLE_TAP: register_code(KC_LSFT); register_code(KC_2); break; //send @
      case TD_DOUBLE_TAP: SEND_STRING("/email"); break; // send email address
      case TD_TRIPLE_TAP: SEND_STRING("/workemail"); break; // send work email
      default: break;
  }
}

void email_reset(tap_dance_state_t *state, void *user_data) {
    switch (email_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_2); break; // unregister @
      case TD_DOUBLE_TAP: ; break;
      case TD_TRIPLE_TAP: ; break;
      default: break;
    }
  email_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'sum' tap dance.
static td_tap_t sum_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void sum_finished(tap_dance_state_t *state, void *user_data) {
    sum_state.state = cur_dance(state);
    switch (sum_state.state) {
      case TD_SINGLE_TAP: register_code(KC_EQL); break; // send =
      case TD_DOUBLE_TAP: SEND_STRING("=sum("); break; // =sum(
      case TD_TRIPLE_TAP: SEND_STRING("=subtotal(9,)"); break ; // send =subtotal
      default: break;
    }
}

void sum_reset(tap_dance_state_t *state, void *user_data) {
    switch (sum_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_EQL); break; // unregister =
      case TD_DOUBLE_TAP: ; break;
      case TD_TRIPLE_TAP: ; break;
      default: break;
    }
  sum_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'left brackets' tap dance.
static td_tap_t lbkts_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void lbkts_finished(tap_dance_state_t *state, void *user_data) {
    lbkts_state.state = cur_dance(state);
    switch (lbkts_state.state) {
      case TD_SINGLE_TAP: register_code(KC_LSFT); register_code(KC_9); break; // send (
      case TD_DOUBLE_TAP: register_code(KC_LBRC); break; // send [
      case TD_TRIPLE_TAP: register_code(KC_LSFT); register_code(KC_LBRC); break ; // send {
      default: break;
    }
}

void lbkts_reset(tap_dance_state_t *state, void *user_data) {
    switch (lbkts_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_9); break; // unregister (
      case TD_DOUBLE_TAP: unregister_code(KC_LBRC); break; // unregister [
      case TD_TRIPLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_LBRC); // unregsister {
      default: break;
    }
  lbkts_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'right brackets' tap dance.
static td_tap_t rbkts_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void rbkts_finished(tap_dance_state_t *state, void *user_data) {
    rbkts_state.state = cur_dance(state);
    switch (rbkts_state.state) {
    case TD_SINGLE_TAP: register_code(KC_LSFT); register_code(KC_0); break; // send )
    case TD_DOUBLE_TAP: register_code(KC_RBRC); break; // send ]
    case TD_TRIPLE_TAP: register_code(KC_LSFT); register_code(KC_RBRC); break; // send }
    default: break;
  }
}

void rbkts_reset (tap_dance_state_t *state, void *user_data) {
  switch (rbkts_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_0); break; // unregister )
    case TD_DOUBLE_TAP: unregister_code(KC_RBRC); break; // unregister ]
    case TD_TRIPLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_RBRC); // unregsister }
    default: break;
  }
  rbkts_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'tilde' tap dance.
static td_tap_t tilde_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void tilde_finished(tap_dance_state_t *state, void *user_data) {
    tilde_state.state = cur_dance(state);
    switch (tilde_state.state) {
      case TD_SINGLE_TAP: register_code(KC_GRAVE); break; // send `
      case TD_DOUBLE_TAP: register_code(KC_LSFT); register_code(KC_GRAVE); break; // send ~
      case TD_TRIPLE_TAP: SEND_STRING("```"); break; // ```
      default: break;
    }
}

void tilde_reset(tap_dance_state_t *state, void *user_data) {
    switch (tilde_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_GRAVE); break; // unregister `
      case TD_DOUBLE_TAP: unregister_code(KC_LSFT); unregister_code(KC_GRAVE); break; // unregister ~
      case TD_TRIPLE_TAP: ; break;
      default: break;
    }
  tilde_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [EMAIL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, email_finished, email_reset),
    [SUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sum_finished, sum_reset),
    [LBKTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lbkts_finished, lbkts_reset),
    [RBKTS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rbkts_finished, rbkts_reset),
    [TILDE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tilde_finished, tilde_reset)
};