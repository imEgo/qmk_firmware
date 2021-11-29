/* Copyright 2020 Daniel Reibl <janos.daniel.reibl@protonmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID                 0xEB50
#define PRODUCT_ID                0x0724
#define DEVICE_VER                0x0001
#define MANUFACTURER              EBStudio
#define PRODUCT                   EBStudio NewBee SE81 Wireless
#define DESCRIPTION               EBStudio NewBee SE81 Wireless

// #define BOARD_OTG_NOVBUSSENS   1
#define STM32_LSECLK              0U
#define STM32_HSECLK              16000000U

#if 0 // Already support by 0.15.0
#define FEE_PAGE_SIZE             0x4000
#define FEE_PAGE_COUNT            1
#define FEE_MCU_FLASH_SIZE        64
#endif

/* Key Matrix Size */
#define MATRIX_ROWS               13
#define MATRIX_COLS               10

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS           { A3, A4, A5, A6, A7, B0, B1, B2, B10, B12, B13, B14, B15 }
#define MATRIX_COL_PINS           { B9, B8, B7, B6, B5, B4, B3, A15, A14, A13 }
// #define UNUSED_PINS            { C13, C14, C15 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION           COL2ROW

/* LED Indicators */
// #define LED_NUM_LOCK_PIN       A13
#define LED_CAPS_LOCK_PIN         A1
// #define LED_SCROLL_LOCK_PIN    A8
#define LED_PIN_ON_STATE          1

/* Backlight */
#define BACKLIGHT_PIN             A9
#define BACKLIGHT_PWM_DRIVER      PWMD1
#define BACKLIGHT_PWM_CHANNEL     2
#define BACKLIGHT_PAL_MODE        1
#define BACKLIGHT_LEVELS          10
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD          10
#define BACKLIGHT_ON_STATE        0

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE                  5

/* Forces NKRO on during keyboard startup regardless of EEPROM setting */
// #define FORCE_NKRO
