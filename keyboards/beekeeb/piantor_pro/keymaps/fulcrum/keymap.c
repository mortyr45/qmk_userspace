// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap Dance declarations
enum {
    TD_ESC_GRV,
    TD_H_MINS,
    TD_J_RCTL_EQL,
    TD_K_RSFT_LBRC,
    TD_L_LALT_RBRC,
    TD_SCLN_RGUI_BSLS,
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

static td_tap_t td_h_mins_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void td_h_mins_finished(tap_dance_state_t *state, void *user_data) {
    td_h_mins_state.state = cur_dance(state);
    switch (td_h_mins_state.state) {
        case TD_SINGLE_TAP: register_code(KC_H); break;
        case TD_DOUBLE_TAP: register_code(KC_MINS); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_H); register_code(KC_H); break;
        default: break;
    }
}
void td_h_mins_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_h_mins_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_H); break;
        case TD_DOUBLE_TAP: unregister_code(KC_MINS); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_H); break;
        default: break;
    }
    td_h_mins_state.state = TD_NONE;
}

static td_tap_t td_j_rctl_eql_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void td_j_rctl_eql_finished(tap_dance_state_t *state, void *user_data) {
    td_j_rctl_eql_state.state = cur_dance(state);
    switch (td_j_rctl_eql_state.state) {
        case TD_SINGLE_TAP: register_code(KC_J); break;
        case TD_SINGLE_HOLD: register_code(KC_RCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_EQL); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_J); register_code(KC_J); break;
        default: break;
    }
}
void td_j_rctl_eql_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_j_rctl_eql_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_J); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_EQL); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_J); break;
        default: break;
    }
    td_j_rctl_eql_state.state = TD_NONE;
}

static td_tap_t td_k_rsft_lbrc_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void td_k_rsft_lbrc_finished(tap_dance_state_t *state, void *user_data) {
    td_k_rsft_lbrc_state.state = cur_dance(state);
    switch (td_k_rsft_lbrc_state.state) {
        case TD_SINGLE_TAP: register_code(KC_K); break;
        case TD_SINGLE_HOLD: register_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: register_code(KC_LBRC); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_K); register_code(KC_K); break;
        default: break;
    }
}
void td_k_rsft_lbrc_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_k_rsft_lbrc_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_K); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_LBRC); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_K); break;
        default: break;
    }
    td_k_rsft_lbrc_state.state = TD_NONE;
}

static td_tap_t td_l_lalt_rbrc_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void td_l_lalt_rbrc_finished(tap_dance_state_t *state, void *user_data) {
    td_l_lalt_rbrc_state.state = cur_dance(state);
    switch (td_l_lalt_rbrc_state.state) {
        case TD_SINGLE_TAP: register_code(KC_L); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        case TD_DOUBLE_TAP: register_code(KC_RBRC); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_L); register_code(KC_L); break;
        default: break;
    }
}
void td_l_lalt_rbrc_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_l_lalt_rbrc_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_L); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_RBRC); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_L); break;
        default: break;
    }
    td_l_lalt_rbrc_state.state = TD_NONE;
}

static td_tap_t td_scln_rgui_bsls_state = {
    .is_press_action = true,
    .state = TD_NONE
};
void td_scln_rgui_bsls_finished(tap_dance_state_t *state, void *user_data) {
    td_scln_rgui_bsls_state.state = cur_dance(state);
    switch (td_scln_rgui_bsls_state.state) {
        case TD_SINGLE_TAP: register_code(KC_SCLN); break;
        case TD_SINGLE_HOLD: register_code(KC_RGUI); break;
        case TD_DOUBLE_TAP: register_code(KC_BSLS); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_SCLN); register_code(KC_SCLN); break;
        default: break;
    }
}
void td_scln_rgui_bsls_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_scln_rgui_bsls_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SCLN); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RGUI); break;
        case TD_DOUBLE_TAP: unregister_code(KC_BSLS); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_SCLN); break;
        default: break;
    }
    td_scln_rgui_bsls_state.state = TD_NONE;
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE),
    [TD_H_MINS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_h_mins_finished, td_h_mins_reset),
    [TD_J_RCTL_EQL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_j_rctl_eql_finished, td_j_rctl_eql_reset),
    [TD_K_RSFT_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_k_rsft_lbrc_finished, td_k_rsft_lbrc_reset),
    [TD_L_LALT_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_l_lalt_rbrc_finished, td_l_lalt_rbrc_reset),
    [TD_SCLN_RGUI_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_scln_rgui_bsls_finished, td_scln_rgui_bsls_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(// default typing layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD(TD_ESC_GRV),KC_Q,KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,LGUI_T(KC_A),LALT_T(KC_S),LSFT_T(KC_D),LCTL_T(KC_F),KC_G,             TD(TD_H_MINS),TD(TD_J_RCTL_EQL),TD(TD_K_RSFT_LBRC),TD(TD_L_LALT_RBRC),TD(TD_SCLN_RGUI_BSLS),KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(3),  KC_SPC,   MO(1),      MO(1),  KC_ENT,   MO(3)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(// typing layer extra keys
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU,                      XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, LGUI_T(KC_LEFT), LALT_T(KC_DOWN), LSFT_T(KC_UP), LCTL_T(KC_RIGHT), KC_MPLY,    XXXXXXX, RCTL_T(KC_4), RSFT_T(KC_5), LALT_T(KC_6), RGUI_T(KC_NO), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_VOLD,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(// movement layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_S,    KC_W,    KC_D, XXXXXXX,                      XXXXXXX, KC_LEFT,   KC_UP, KC_DOWN,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TG(2),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(// menu layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   TO(2), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOTLOADER,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

//     [2] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//        KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
//                                       //`--------------------------'  `--------------------------'
//   ),

//     [3] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//         QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
//                                       //`--------------------------'  `--------------------------'
//   )
};
