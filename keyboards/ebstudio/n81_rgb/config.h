/*Copyright 2021 Blake Drayson / Draytronics

Contact info@draytronics.co.uk

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

#define VENDOR_ID         0xeb50
#define PRODUCT_ID        0x4c81
#define DEVICE_VER        0x0100
#define MANUFACTURER      EBStudio
#define PRODUCT           EBStudio NewBee SE81 RGB MCU
#define DESCRIPTION       EBStudio NewBee SE81 RGB MCU

#define USB_CFG_DPLUS_BIT 4

/* key matrix size */
#define MATRIX_ROWS       5
#define MATRIX_COLS       2

/* Keyboard Matrix Assignments */
#define DIRECT_PINS { \
    { NO_PIN, D2 }, \
    { D6,     D5 }, \
    { D7,     B0 }, \
    { C3,     C2 }, \
    { C1,     C0 }  \
}

/* Custom pins definitions */
#define WAK_CTL_PIN       D2
#define RGB_CTL_PIN       B1
#define BAT_LOW_PIN       B2
#define BAT_CHK_PIN       D0

#define UNUSED_PINS       { B3, B4, B5, C4, C5, D3, D4 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE          2

// Underglow
#define RGB_DI_PIN        D1 // Underglow led pin

#ifdef RGB_DI_PIN
    #define RGBLED_NUM 83

    #ifdef RGBLIGHT_ENABLE
        #define RGBLIGHT_LED_MAP \
        { \
            14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0, \
            29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, \
            44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
            57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, \
            70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, \
            82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71 \
        }

        #define RGBLIGHT_DEFAULT_VAL 120
        #define RGBLIGHT_DEFAULT_HUE 152
        #define RGBLIGHT_DEFAULT_SAT 232

        #define RGBLIGHT_HUE_STEP 8
        #define RGBLIGHT_SAT_STEP 8
        #define RGBLIGHT_VAL_STEP 8

        #define RGBLIGHT_LIMIT_VAL 120

        // #define RGBLIGHT_SLEEP      /* If defined, the RGB lighting will be switched off when the host goes to sleep */
        #define RGBLIGHT_ANIMATIONS
        #define RGBLIGHT_EFFECT_ALTERNATING
        #define RGBLIGHT_EFFECT_BREATHING
        #define RGBLIGHT_EFFECT_CHRISTMAS
        #define RGBLIGHT_EFFECT_KNIGHT
        #define RGBLIGHT_EFFECT_RAINBOW_MOOD
        #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
        #define RGBLIGHT_EFFECT_RGB_TEST
        #define RGBLIGHT_EFFECT_SNAKE
        #define RGBLIGHT_EFFECT_STATIC_GRADIENT
        #define RGBLIGHT_EFFECT_TWINKLE

        #define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_RAINBOW_SWIRL + 4)
        // #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

        // #define RGBLIGHT_DISABLE_KEYCODES
    #elif defined RGB_MATRIX_ENABLE
        #define DRIVER_LED_TOTAL RGBLED_NUM
    #endif
#endif
