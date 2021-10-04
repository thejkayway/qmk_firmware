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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_4x6_5(
    KC_GESC,  KC_1, KC_2, KC_3, KC_4, KC_5,			            KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_BSPC,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,			            KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_MINS,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,	                KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
//-------------------------------------------------//-----------------------------------------------------------//
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_BSLS,
//-------------------------------------------------//-----------------------------------------------------------//
                  KC_LCMD, KC_LOPT, MO(1),		              MO(1),  KC_SPC, KC_RSFT,
                           KC_SPC,  MO(2),                  KC_ROPT, KC_ENT
  ),

  [1] = LAYOUT_split_4x6_5(
    KC_GRV,  KC_BRMD, KC_BRMU, _______,  _______, KC_MPRV,			  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU,  KC_DEL,
//---------------------------------------------------------//-----------------------------------------------------------//
    _______, _______, _______,   KC_UP,  _______, _______,			  KC_LBRC, KC_RBRC,   KC_UP,  _______, _______,  KC_EQL,
//---------------------------------------------------------//-----------------------------------------------------------//
    _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,	      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
//---------------------------------------------------------//-----------------------------------------------------------//
      RESET, _______, _______, _______,  _______, _______,        _______, _______, _______,  _______, _______, _______,
//---------------------------------------------------------//-----------------------------------------------------------//
                                KC_LCMD, KC_LOPT, KC_TRNS,		    KC_TRNS, KC_SPC, KC_RSFT,
                                         KC_SPC,  KC_TRNS,        KC_ROPT, KC_ENT
  ),

    [2] = LAYOUT_split_4x6_5(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,			    KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10, KC_SLEP,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, _______, _______, _______, _______,			_______, _______, KC_WH_U,  _______, _______, _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, RGB_RMOD, RGB_TOG, RGB_MOD, _______,	    _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
//---------------------------------------------------------//--------------------------------------------------------------//
    _______, _______, _______,  _______, _______, _______,      _______, _______, _______, _______, _______, _______,
//---------------------------------------------------------//--------------------------------------------------------------//
                               KC_LCMD, KC_LOPT, KC_TRNS,		    KC_TRNS, KC_SPC, KC_RSFT,
                                        KC_SPC,  KC_TRNS,       KC_ROPT, KC_ENT
  ),
};
