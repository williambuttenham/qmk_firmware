/*
Copyright 2023 William Buttenham

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _LOWER 1

// Fillers to make layering more clear
#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
  KC_Q, KC_W,    KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    \
  KC_A, KC_S,    KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, \
  KC_Z, KC_X,    KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
        KC_LGUI, KC_LALT,                                                            KC_QUOT, KC_DEL,          \
                                      KC_TAB,  KC_LCTL,              KC_ENT,  KC_BSPC,                                          \
                                      KC_LSFT, LT(_LOWER, KC_SPC),   LT(_LOWER, KC_SPC),   KC_ESC,                                           \
                                      ____, ____,                  ____, ____
),

[_LOWER] = LAYOUT( \
  KC_GRAVE,  ____,  ____,  ____,  ____,                           ____,   ____,   ____,   ____,   ____,   \
  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       ____,   KC_LEFT,   KC_UP,   KC_DOWN,   KC_RGHT,    \
  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
          ____,   ____,                                                       ____,    ____,             \
                                    ____, ____,             ____, ____,                                               \
                                    ____, ____,             ____, ____,                                               \
                                    ____, ____,             ____, ____                                                \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch (biton32(layer_state)) {
            case 1:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    return true;
}
