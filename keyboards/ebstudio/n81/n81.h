/*
Copyright 2020 QMK Community, Janos Daniel Reibl <janos.daniel.reibl@protonmail.com> @riblee

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

#include "quantum.h"

// readability
#define XXX KC_NO

#define LAYOUT( \
    K66,      K41, K42, K91, K48, K95, K19, K11, K39, K68, K21, K57, K62, K18, K36, \
    K77, K50, K60, K29, K75, K67, K27, K69, K35, K56, K54, K64, K58, K22,      K17, \
    K37, K28, K61, K51, K40, K31, K33, K73, K79, K25, K96, K20, K53, K13,      K08, \
    K30, K02, K26, K34, K10, K86, K45, K55, K65, K44, K59, K63,      K24,           \
    KA2,      K87, K47, K90, K23, K38, K71, K46, K32, K49, K43,      KA1, K76,      \
    K94, K89, K98,           K99,                K97, K80, K93,      K72, K74, K70  \
) \
{ \
    {XXX, K08, XXX, XXX, XXX, XXX, XXX, XXX, K02, XXX}, \
    {K18, K17, XXX, XXX, XXX, K13, XXX, K11, K10, XXX}, \
    {K28, K27, K26, K25, K24, K23, K22, K21, K20, K19}, \
    {K38, K37, K36, K35, K34, K33, K32, K31, K30, K29}, \
    {K47, K46, K45, XXX, K44, K43, K42, K41, K40, K39}, \
    {K57, K56, K55, K54, K53, XXX, K51, K50, K49, K48}, \
    {K67, K66, K65, K64, K63, K62, K61, K60, K59, K58}, \
    {K77, K76, K75, K74, K73, K72, K71, K70, K69, K68}, \
    {XXX, XXX, XXX, XXX, XXX, XXX, XXX, K80, K79, XXX}, \
    {XXX, XXX, XXX, XXX, XXX, XXX, K89, XXX, K87, K86}, \
    {XXX, XXX, XXX, XXX, K94, K93, XXX, XXX, K91, K90}, \
    {XXX, XXX, K98, K97, XXX, XXX, XXX, XXX, K96, K95}, \
    {KA2, KA1, XXX, XXX, XXX, XXX, XXX, XXX, XXX, K99}  \
}
