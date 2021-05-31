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
                                      KC_TAB,  KC_LSFT,              KC_ENT,  KC_BSPC,                                          \
                                      KC_LCTL, LT(_LOWER, KC_SPC),   KC_UP,   KC_RGHT,                                           \
                                      LT(_LOWER, KC_SPC), KC_GESC,   KC_LEFT, KC_DOWN
),

[_LOWER] = LAYOUT( \
  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   \
  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  ____,   KC_F11, KC_F12,  ____, ____,                             KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
          KC_MS_BTN1,   KC_MS_BTN2,                                                               ____,    ____,             \
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
