// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "print.h" // at the top of the file
#include "keymap_us.h"
#include "keymap_swedish.h"
#include QMK_KEYBOARD_H
#define CTRL_ESC LCTL_T(KC_ESC) // ESC acts as Ctrl when held
#define OE_GUI LGUI_T(OE_U)     // OE acts as GUI when held
#define WINDOW LM(_SYM, MOD_LALT | MOD_LCTL)
enum os_modes { OS_MAC, OS_WIN };

static uint8_t current_os = OS_WIN;

enum custom_keycodes { OS_TOGGLE = SAFE_RANGE, AE_U, OE_U, AO_U, MY_LCRL, SW_TOGGLE };

enum custom_layers { _QWERTY, _SWEDISH, _SYM, _SYM_SE, _RGB };

// clang format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang format off
    [_QWERTY] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            QK_GESC,  KC_1,   KC_2,    KC_3,     KC_4,    KC_5,                               KC_6,   KC_7,    KC_8,     KC_9,     KC_0,   KC_DEL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    AO_U,
        // ├────────┼────────┼────────┬────────┬────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            CTRL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    OE_U,    AE_U,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LALT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    MO(_RGB),         WINDOW,  KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                           LM(_SYM, MOD_LCTL), MY_LCRL, SFT_T(KC_SPC),   RSFT_T(KC_BSPC), MO(_SYM), LM(_SYM, MOD_LSFT)
        //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_SYM] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F12, KC_GRV, KC_LPRN, KC_RPRN, KC_SCLN, KC_COMM, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_EXLM, KC_LCBR, KC_QUOT, KC_DQUO, KC_RCBR, KC_QUES, KC_AT, KC_LBRC, KC_RBRC, KC_BSLS, KC_QUES, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_HASH, KC_CIRC, KC_EQL, KC_UNDS, KC_DLR, KC_ASTR, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_QUOT, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TILD, KC_LABK, KC_PIPE, KC_MINS, KC_RABK, KC_SLSH, KC_COLN, XXXXXXX, KC_DOT, KC_PLUS, KC_AMPR, _______, _______, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        KC_PERC, KC_SCLN, KC_DOT, XXXXXXX, _______, MO(_RGB)
        // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_SWEDISH] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        QK_GESC, SE_1, SE_2, SE_3, SE_4, SE_5, SE_6, SE_7, SE_8, SE_9, SE_0, KC_BSPC,
        // ├────────┼────────┼────────┬────────┬────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB, SE_Q, SE_W, SE_E, SE_R, SE_T, SE_Y, SE_U, SE_I, SE_O, SE_P, SE_ARNG,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        CTRL_ESC, SE_A, SE_S, SE_D, SE_F, SE_G,                                                 SE_H, SE_J, SE_K, SE_L, SE_ODIA, SE_ADIA,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LALT, SE_Z, SE_X, SE_C, SE_V, SE_B, MO(_RGB), WINDOW, SE_N, SE_M, SE_COMM, SE_DOT, SE_MINS, KC_ENT,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        KC_LGUI, MY_LCRL, SFT_T(KC_SPC), RSFT_T(KC_BSPC), MO(_SYM_SE), LM(_SYM_SE, MOD_LSFT)
        // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_RGB] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        RM_TOGG, KC_EXLM, KC_AT, KC_HASH, KC_DLR, QK_BOOT, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, SW_TOGGLE,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        RM_NEXT, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS, KC_EQL, KC_HOME, RM_HUEU, RM_SATU, RM_VALU, KC_SLEP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN, _______, KC_PLUS, KC_END, RM_HUED, RM_SATD, RM_VALD, EE_CLR,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        _______, _______, _______, _______, _______, _______
        // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_SYM_SE] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F12, SE_SECT, SE_LPRN, SE_RPRN, SE_SCLN, SE_COMM, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        SE_EXLM, SE_LCBR, SE_QUOT, SE_DQUO, SE_RCBR, SE_QUES, SE_AT, SE_LBRC, SE_RBRC, SE_BSLS, SE_QUES, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        SE_HASH, SE_CIRC, SE_EQL, SE_UNDS, SE_DLR, SE_ASTR, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, SE_ACUT, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        SE_TILD, SE_LABK, SE_PIPE, SE_MINS, SE_RABK, SE_SLSH, SE_COLN, XXXXXXX, SE_DOT, SE_PLUS, SE_AMPR, _______, _______, _______,
        // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
        SE_PERC, SE_SCLN, SE_DOT, XXXXXXX, _______, MO(_RGB)
        // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        )};
void send_alt_code(uint16_t code) {
    char buf[6];
    snprintf(buf, sizeof(buf), "%04d", code);

    register_code(KC_LALT);
    for (uint8_t i = 0; i < 4; ++i) {
        tap_code16(KC_KP_0 + (buf[i] - '0'));
    }
    unregister_code(KC_LALT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        switch (keycode) {
            case OS_TOGGLE:
            case AE_U:
            case OE_U:
            case AO_U:
            case SW_TOGGLE:
                return false; // Do not process these keycodes when released
            case MY_LCRL:
                // Do not process these keycodes when released
                if (current_os == OS_MAC) {
                    unregister_code(KC_LGUI); // Release Command key
                } else {
                    unregister_code(KC_LCTL); // Release Ctrl key
                }
                return false; // Do not process these keycodes when released
        }
    };
    uprintf("Keycode: %u\n", keycode);
    bool shift_held = get_mods() & MOD_MASK_SHIFT;
    switch (keycode) {
        case OS_TOGGLE:
            current_os = (current_os == OS_MAC) ? OS_WIN : OS_MAC;

            if (current_os == OS_MAC) {
                uprintf("Current OS: macOS\n");
                rgb_matrix_set_color_all(RGB_WHITE);
            } else {
                uprintf("Current OS: Windows\n");
                rgb_matrix_set_color_all(RGB_BLUE);
            }
            return false;
        case AE_U:
            if (current_os == OS_MAC) {
                if (shift_held) {
                    uint8_t mods = get_mods();
                    clear_mods();
                    register_code(KC_LALT); // Option key
                    tap_code(KC_U);
                    unregister_code(KC_LALT);

                    register_code(KC_LSFT);
                    tap_code(KC_A);
                    unregister_code(KC_LSFT);
                    set_mods(mods);

                } else {
                    send_string(SS_LALT("u") "a"); // Option+u then a = ä
                }

            } else {
                if (shift_held) {
                    uint8_t mods = get_mods();
                    clear_mods();
                    send_string(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_6) SS_UP(X_LALT)); // Alt+0196
                    set_mods(mods);
                } else {
                    send_string(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_8) SS_UP(X_LALT)); // Alt+0228
                }
            }
            return false;
        case OE_U:
            if (current_os == OS_MAC) {
                if (shift_held) {
                    uint8_t mods = get_mods();
                    clear_mods();
                    register_code(KC_LALT); // Option key
                    tap_code(KC_U);
                    unregister_code(KC_LALT);
                    register_code(KC_LSFT);
                    tap_code(KC_O);
                    unregister_code(KC_LSFT);
                    set_mods(mods);
                } else {
                    send_string(SS_LALT("u") "o"); // Option+u then o = ö
                }
            } else {
                if (shift_held) {
                    uint8_t mods = get_mods();
                    clear_mods();
                    send_string(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_UP(X_LALT)); // Alt+0214
                    set_mods(mods);
                } else {
                    send_string(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6) SS_UP(X_LALT)); // Alt+0246
                }
            }
            return false;
        case AO_U:
            if (current_os == OS_MAC) {
                if (shift_held) {
                    uint8_t mods = get_mods();
                    clear_mods();
                    register_code(KC_LALT); // Option key
                    register_code(KC_LSFT);
                    tap_code(KC_A);
                    unregister_code(KC_LALT);
                    unregister_code(KC_LSFT);

                    set_mods(mods);

                } else {
                    send_string(SS_LALT("a")); // Option+a = å
                }
            } else {
                if (shift_held) {
                    uint8_t mods = get_mods();
                    clear_mods();
                    send_string(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_7) SS_UP(X_LALT)); // Alt+0197
                    set_mods(mods);
                } else {
                    send_string(SS_DOWN(X_LALT) SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_9) SS_UP(X_LALT)); // Alt+229
                }
            }
            return false;
        case MY_LCRL:
            if (current_os == OS_MAC) {
                register_code(KC_LGUI); // Command key
            } else {
                register_code(KC_LCTL); // Ctrl key
            }

            return false;
        case SW_TOGGLE:
            // Toggle between QWERTY and Swedish layouts
            if (get_highest_layer(default_layer_state) == _QWERTY) {
                default_layer_set(1UL << _SWEDISH);
            } else {
                default_layer_set(1UL << _QWERTY);
            }
            return false;
    }

    return true;
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            current_os = OS_MAC;
            break;
        case OS_WINDOWS:
            current_os = OS_WIN;
            break;
        case OS_LINUX:
            current_os = OS_WIN; // Default to Windows for Linux
            break;
        case OS_UNSURE:
            current_os = OS_WIN; // Default to Windows if unsur
            break;
    }

    return true;
}
