/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#include "scylla.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // left
    {  23,  19, 15, 11, 7, 3 },
    {  22,  18, 14, 10, 6, 2 },
    {  21,  17, 13, 9, 5, 1 },
    {  20,  16, 12, 8, 4, 0 },
    { 24, 25, 26, 27, 28, NO_LED },
    // right
    { 32, 36, 40, 44, 48, 52 },
    { 31, 35, 39, 43, 47, 51 },
    { 30, 34, 38, 42, 46, 50 },
    { 29, 33, 37, 41, 45, 49 },
    { NO_LED, 53, 54, 55, 56, 57 }
}, {
    // left
    // row 4     /    row 3    /    row 2    /    row 1
    { 102,  48 }, { 102,  32 }, { 102,  16 }, { 102,   0 }, // col 6 viewed from top (col 1 matrix)
    {  81,  48 }, {  81,  32 }, {  81,  16 }, {  81,   0 }, // col 5 viewed from top (col 2 matrix)
    {  61,  48 }, {  61,  32 }, {  61,  16 }, {  61,   0 }, // col 4 viewed from top (col 3 matrix)
    {  41,  48 }, {  41,  32 }, {  41,  16 }, {  41,   0 }, // col 3 viewed from top (col 4 matrix)
    {  20,  48 }, {  20,  32 }, {  20,  16 }, {  20,   0 }, // col 2 viewed from top (col 5 matrix)
    {   0,  48 }, {   0,  32 }, {   0,  16 }, {   0,   0 }, // col 1 viewed from top (col 6 matrix)
    {  61,  56 }, {  81,  56 }, { 102,  56 }, { 102,  64 }, {  81,  64 }, // left thumb cluster
    // right
    { 122,  48 }, { 122,  32 }, { 122,  16 }, { 122,  0 }, // col  7 viewed from top (col 6 matrix)
    { 142,  48 }, { 142,  32 }, { 142,  16 }, { 142,  0 }, // col  8 viewed from top (col 5 matrix)
    { 163,  48 }, { 163,  32 }, { 163,  16 }, { 163,  0 }, // col  9 viewed from top (col 4 matrix)
    { 183,  48 }, { 183,  32 }, { 183,  16 }, { 183,  0 }, // col 10 viewed from top (col 3 matrix)
    { 204,  48 }, { 204,  32 }, { 204,  16 }, { 204,  0 }, // col 11 viewed from top (col 2 matrix)
    { 224,  48 }, { 224,  32 }, { 224,  16 }, { 224,  0 }, // col 12 viewed from top (col 1 matrix)
    { 163,  56 }, { 142,  56 }, { 122,  56 }, { 122,  64 }, { 142,  64 } // right thumb cluster
}, {
    // left
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2,
    2, 2, 2, 2, 2,
    // right
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2,
    2, 2, 2, 2, 2
} };
#endif
