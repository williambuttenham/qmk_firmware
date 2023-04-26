#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT, \
        KC_BSPACE, KC_ENTER, \
        KC_A, KC_S, KC_Z, KC_X   \
    )
};
