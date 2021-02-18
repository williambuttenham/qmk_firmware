#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ,-------------------.
    * | T  | G  | TAB| SP |
    * |----|----|----|----|
    * | R  | F  | 4  | RET|B
    * |----|----|----|----|O
    * | E  | D  | 3  | RET|T
    * |----|----|----|----|T
    * | W  | S  | 2  | Z  |O
    * |----|----|----|----|M
    * | Q  | A  | 1  | FN |
    * |----|----|----|----|
    * | 5  |TAB |SHT |CTRL|
    * `-------------------'
    *        LEFT
    */
    [0] = LAYOUT_ortho_6x4(
        KC_T,  KC_G,    KC_ESCAPE,     KC_SPACE, \
        KC_R,  KC_F,    KC_4,       KC_ENTER, \
        KC_E,  KC_D,    KC_3,       KC_ENTER,  \
        KC_W,  KC_S,    KC_2,       KC_Z, \
        KC_Q,  KC_A,    KC_1,       MO(1), \
        KC_5,  KC_TAB,  KC_LSHIFT,  KC_LCTRL
    ),

    /*
    * ,-------------------.
    * | F6 |    |    |    |
    * |----|----|----|----|
    * |    |    |    |    |
    * |----|----|----|----|
    * | F4 |    |    |    |
    * |----|----|----|----|
    * | F3 |    |    |    |
    * |----|----|----|----|
    * | F2 |    |    | FN |
    * |----|----|----|----|
    * | F1 |    |    |    |
    * `-------------------'
    */
    [1] = LAYOUT_ortho_6x4(
        KC_F6,  BL_TOGG,  BL_STEP,   KC_NO, \
        KC_NO,  KC_NO,  KC_NO,   KC_NO, \
        KC_F4,  KC_NO,  KC_NO,   KC_NO, \
        KC_F3,  KC_NO,  KC_NO,   KC_NO, \
        KC_F2,  KC_NO,  KC_NO,   KC_TRNS, \
        KC_F1,  KC_NO,  KC_GRAVE,   KC_NO
    )
};
