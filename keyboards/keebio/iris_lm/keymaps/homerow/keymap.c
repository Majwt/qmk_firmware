// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keymap_japanese.h"
#include QMK_KEYBOARD_H

#undef TAPPING_TERM
#define TAPPING_TERM 102

#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

#define HOME_J LCTL_T(KC_J)
#define HOME_K LSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_C LGUI_T(KC_SCLN)

#define ESC_CTL LCTL_T(KC_ESC)

enum custom_keycodes {
    GAMING = SAFE_RANGE,
    // Add other custom keycodes here if needed
};

enum custom_layers {
     _QWERTY,
     _GAMING,  // Add gaming layer
     _KEYPAD,
     _SYM,
     _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     ESC_CTL, HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                               KC_H,    HOME_J,  HOME_K,   HOME_L, HOME_C,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(_RGB),          MO(_RGB),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    JP_MHEN, JP_HENK,  KC_SPC,                    KC_BSPC,  MO(_SYM), KC_LSFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    GAMING,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,     KC_S,   KC_D,    KC_F,     KC_G,                               KC_H,    KC_J,  KC_K,   KC_L, KC_SCLN,  KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LALT,          MO(_RGB),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_LSFT, KC_SPC,                  KC_BSPC,  MO(_SYM), KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),
    [_SYM] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_F12,   XXXXXXX,    KC_LPRN, KC_RPRN, KC_SCLN, KC_COMM,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10, KC_F11,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_EXLM, KC_LCBR, KC_QUOT, KC_DQUO, KC_RCBR, KC_QUES,                             KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS, KC_QUES, KC_DEL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_HASH, KC_CIRC, KC_EQL, KC_UNDS, KC_DLR, KC_ASTR,                               KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_QUOT, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            XXXXXXX, KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_SLSH, KC_COLN,             XXXXXXX, KC_DOT, KC_PLUS, KC_AMPR, _______, _______, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            KC_PERC, KC_SCLN, KC_DOT,                   XXXXXXX, _______, MO(_RGB)
        //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),
    [_RGB] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_F12,   KC_F1,    KC_F2,  KC_F3,   KC_F4,   KC_F5,                             KC_F6,    KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            RM_TOGG, KC_EXLM, GAMING,   KC_HASH, KC_DLR,  QK_BOOT,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, XXXXXXX, TG(_KEYPAD),
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            RM_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_LGUI,                            KC_EQL, KC_HOME, RM_HUEU, RM_SATU, RM_VALU, KC_SLEP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, _______,           _______, KC_PLUS, KC_END, RM_HUED, RM_SATD, RM_VALD, EE_CLR,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            _______, _______, _______,                   _______, _______, _______
        //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_KEYPAD] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_BSPC,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, _______, _______,                            _______, KC_P7,   KC_P8,   KC_P9,   _______, TG(_KEYPAD),
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, _______, _______,                            _______, KC_P4,   KC_P5,   KC_P6,   _______,  _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            _______, _______, _______, _______, _______, _______, _______,           KC_SLSH, KC_P0, KC_P1,   KC_P2,   KC_P3,   _______, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            _______, _______, _______,                   KC_BSPC,   MO(_SYM),   KC_PDOT
        //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GAMING:
            if (record->event.pressed) {
                // Toggle between Gaming and QWERTY layers
                if (get_highest_layer(default_layer_state) == _QWERTY) {
                    default_layer_set(1UL << _GAMING);  // Switch to gaming layer
                } else {
                    default_layer_set(1UL << _QWERTY);  // Switch back to QWERTY
                }
            }
            return false;  // Don't process this keycode further
    }
    return true;  // Process all other keycodes normally
}
