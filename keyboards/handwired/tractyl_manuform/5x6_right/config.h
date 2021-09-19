/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#include "config_common.h"

#define PRODUCT_ID  0x3536
#define DEVICE_VER  0x0001
#define PRODUCT     Tractyl Manuform(5x6)

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_COL_PINS \
    { C0, C1, C2, C3, C4, C5 }
#define MATRIX_ROW_PINS \
    { F7, F6, F5, F4, F3, F2 }

#define DIODE_DIRECTION COL2ROW

// WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN      E7
#define RGBLED_NUM      20
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT \
    { 10, 10 }
#define RGBLIGHT_SLEEP
// #define RGBW
#define RGBLIGHT_LIMIT_VAL          100
/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

#define DEBUG_LED_PIN               D6

#define ROTATIONAL_TRANSFORM_ANGLE  -25

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW          0
#define BOOTMAGIC_LITE_COLUMN       0
#define BOOTMAGIC_LITE_ROW_RIGHT    6
#define BOOTMAGIC_LITE_COLUMN_RIGHT 5

#define AUDIO_PIN                   C6
#define AUDIO_PIN_ALT               B7

#define DYNAMIC_KEYMAP_LAYER_COUNT  16
#define LAYER_STATE_16BIT

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D2
#define EE_HANDS

#define ENCODERS_PAD_A \
    { D5 }
#define ENCODERS_PAD_B \
    { D4 }
#define ENCODER_RESOLUTION 4

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE           5

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define SERIAL_USE_MULTI_TRANSACTION
#define SPLIT_TRANSACTION_IDS_KB RPC_ID_STATE_SYNC, RPC_ID_SLAVE_STATE
