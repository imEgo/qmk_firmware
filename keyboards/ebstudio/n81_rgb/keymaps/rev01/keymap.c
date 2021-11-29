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

#include QMK_KEYBOARD_H

#include <stdint.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        _______, MO(1)  ,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [1] = LAYOUT(
        _______, _______,
        _______, RGB_TOG,
        RGB_VAI, MO(2)  ,
        _______, _______,
        RGB_HUI, RGB_SAI
    ),
    [2] = LAYOUT(
        _______, _______,
        _______, RGB_MOD,
        RGB_VAD, _______,
        _______, _______,
        RGB_HUD, RGB_SAD
    )
};
