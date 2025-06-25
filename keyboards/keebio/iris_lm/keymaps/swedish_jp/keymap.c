// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define EE_HANDS
#ifdef MAC_MODE
  #include "keymap_swedish_mac_iso.h"
#else
  #include "keymap_swedish.h"
#endif

#define HOME_A SE_A
#define HOME_S SE_S
#define HOME_D SE_D
#define HOME_F SE_F
#define CTRL_ESC LCTL_T(KC_ESC)  // ESC acts as Ctrl when held

#define HOME_J SE_J
#define HOME_K SE_K
#define HOME_L SE_L
#define HOME_OIDA RGUI_T(SE_ODIA)  // Ö acts as GUI (Cmd/Win) when held
#define GUI_G RGUI_T(SE_G)  // G acts as GUI (Cmd/Win) when held

enum custom_layers {
     _QWERTY,
     _SYM,
     _NAV,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, SE_1,    SE_2,    SE_3,    SE_4,    SE_5,                               SE_6,    SE_7,    SE_8,    SE_9,    SE_0,     SE_SECT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,                               SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,     SE_ARNG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTRL_ESC, HOME_A,  HOME_S,   HOME_D,  HOME_F,   GUI_G,                               SE_H, HOME_J,  HOME_K,  HOME_L,  HOME_OIDA,  SE_ADIA,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    MO(_NAV),         KC_LGUI,  SE_N,  SE_M,    SE_COMM, SE_DOT,  SE_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_LCTL, KC_LSFT , KC_SPC,                    KC_BSPC, MO(_SYM),MO(_NAV)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬───────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, _______, SE_7,    SE_8,    SE_9,    _______,                            _______, _______, _______, _______, _______, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, SE_4,    SE_5,    SE_6,    _______,                            _______, KC_PGDN, KC_PGUP, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, SE_1,    SE_2,    SE_3,    _______,                            KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, SE_0,    SE_DOT,  SE_COLN, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______ // kana
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  SE_PLUS, SE_ACUT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SE_DQUO, SE_HASH,  SE_AT, SE_PERC, SE_AMPR, SE_SLSH,                            SE_LPRN, SE_RPRN, SE_EQL,  SE_QUES, SE_GRV,  SE_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SE_PIPE, SE_ASTR, SE_QUOT, SE_LABK, SE_RABK, SE_UNDS,                            SE_LCBR, SE_RCBR, SE_LBRC, SE_RBRC, SE_BSLS, SE_TILD,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, SE_QUES, _______, SE_MINS,          _______, SE_PLUS, SE_CIRC, SE_DLR, _______, SE_UNDS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, SE_UNDS,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


};

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;
        case OS_WINDOWS:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case OS_LINUX:
            rgb_matrix_set_color_all(RGB_ORANGE);
            break;
        case OS_UNSURE:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }

    return true;
}
