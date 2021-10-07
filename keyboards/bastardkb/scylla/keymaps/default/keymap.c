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

enum layer_names {
  _QWERTY,
  _EXTRA,
  _SYSTEM
};

// LED Indices - Extra Layer
int ARROW_INDICES[] = { 5, 9, 10, 13, 34, 38, 39, 42 };
int EXTRA_COMMON_INDICES[] = { 23, 31, 35, 51 };
int BRIGHTNESS_INDICES[] = { 15, 19 };
int MEDIA_INDICES[] = { 3, 32, 36 };
int VOLUME_INDICES[] = { 40, 44, 48 };
int EXTRA_LAYER_UNUSED_INDICES[] = { 0, 1, 2, 4, 6, 7, 8, \
                            11, 12, 14, 16, 17, 18, \
                            20, 21, 22, 24, 25, 26, 27, 28, 29, \
                            30, 33, 37, \
                            41, 43, 45, 46, 47, 49, \
                            50, 52, 53, 54, 55, 56, 57, 58 };

// LED Indices - System Layer
int CURSOR_INDICES[] = { 5, 9, 10, 13 };
int SCROLL_INDICES[] = { 34, 38, 39, 42 };
int CLICK_INDICES[] = { 6, 14, 35, 43 };
int RGB_INDICES[] = { 16, 18, 20, 21, 22 };
int FUNCTION_INDICES[] = { 3, 7, 11, 15, 19, 32, 36, 40, 44, 48 };
int SYSTEM_LAYER_UNUSED_INDICES[] = { 0, 1, 2, 4, 8, \
                            12, 17, \
                            24, 25, 26, 27, 28, 29, \
                            30, 31, 33, 37, \
                            41, 45, 46, 47, 49, \
                            50, 51, 53, 54, 55, 56, 57, 58 };
int RESET_INDEX = 23;
int SLEEP_INDEX = 52;

// Find sizes of the arrays using a method described here: https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/
int ARROW_INDICES_SIZE = *(&ARROW_INDICES + 1) - ARROW_INDICES;
int EXTRA_COMMON_INDICES_SIZE = *(&EXTRA_COMMON_INDICES + 1) - EXTRA_COMMON_INDICES;
int BRIGHTNESS_INDICES_SIZE = *(&BRIGHTNESS_INDICES + 1) - BRIGHTNESS_INDICES;
int MEDIA_INDICES_SIZE = *(&MEDIA_INDICES + 1) - MEDIA_INDICES;
int VOLUME_INDICES_SIZE = *(&VOLUME_INDICES + 1) - VOLUME_INDICES;
int EXTRA_LAYER_UNUSED_INDICES_SIZE = *(&EXTRA_LAYER_UNUSED_INDICES + 1) - EXTRA_LAYER_UNUSED_INDICES;
int CURSOR_INDICES_SIZE = *(&CURSOR_INDICES + 1) - CURSOR_INDICES;
int SCROLL_INDICES_SIZE = *(&SCROLL_INDICES + 1) - SCROLL_INDICES;
int CLICK_INDICES_SIZE = *(&CLICK_INDICES + 1) - CLICK_INDICES;
int RGB_INDICES_SIZE = *(&RGB_INDICES + 1) - RGB_INDICES;
int FUNCTION_INDICES_SIZE = *(&FUNCTION_INDICES + 1) - FUNCTION_INDICES;
int SYSTEM_LAYER_UNUSED_INDICES_SIZE = *(&SYSTEM_LAYER_UNUSED_INDICES + 1) - SYSTEM_LAYER_UNUSED_INDICES;

void set_colors_on_indices(int *indices, int array_size, int h, int s, int v) {
  HSV hsv = {h, s, v};
  if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
  }
  RGB rgb = hsv_to_rgb(hsv);
  for (int i = 0; i < array_size; i++) { 
    rgb_matrix_set_color(indices[i], rgb.r, rgb.g, rgb.b);
  }
}

void set_color_on_index(int index, int h, int s, int v) {
  HSV hsv = {h, s, v};
  if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
  }
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

void rgb_matrix_indicators_user(void) {
  if (rgb_matrix_is_enabled()) {
    switch (get_highest_layer(layer_state)) {
      case _EXTRA:
        set_colors_on_indices(ARROW_INDICES, ARROW_INDICES_SIZE, HSV_CHARTREUSE);
        set_colors_on_indices(EXTRA_COMMON_INDICES, EXTRA_COMMON_INDICES_SIZE, HSV_TURQUOISE);
        set_colors_on_indices(BRIGHTNESS_INDICES, BRIGHTNESS_INDICES_SIZE, HSV_YELLOW);
        set_colors_on_indices(MEDIA_INDICES, MEDIA_INDICES_SIZE, HSV_ORANGE);
        set_colors_on_indices(VOLUME_INDICES, VOLUME_INDICES_SIZE, HSV_MAGENTA);
        set_colors_on_indices(EXTRA_LAYER_UNUSED_INDICES, EXTRA_LAYER_UNUSED_INDICES_SIZE, HSV_OFF);
        break;
      case _SYSTEM:
        set_colors_on_indices(CURSOR_INDICES, CURSOR_INDICES_SIZE, HSV_MAGENTA);
        set_colors_on_indices(SCROLL_INDICES, SCROLL_INDICES_SIZE, HSV_CHARTREUSE);
        set_colors_on_indices(CLICK_INDICES, CLICK_INDICES_SIZE, HSV_TURQUOISE);
        set_colors_on_indices(RGB_INDICES, RGB_INDICES_SIZE, HSV_ORANGE);
        set_colors_on_indices(FUNCTION_INDICES, FUNCTION_INDICES_SIZE, HSV_CORAL);
        set_colors_on_indices(SYSTEM_LAYER_UNUSED_INDICES, SYSTEM_LAYER_UNUSED_INDICES_SIZE, HSV_OFF);
        set_color_on_index(RESET_INDEX, HSV_RED);
        set_color_on_index(SLEEP_INDEX, HSV_WHITE);
        break;
    }
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_4x6_5(
  /* QWERTY
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  -_  |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Shft |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   ;  |  '"  |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Ctrl |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |  ,<  |  .>  |  /?  |  \|  |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /  Opt  /---------------.    .---------------\ Shft  \
   *                                 /       /  Cmd  / Layer /      \ Layer \ Space \       \
   *                                '-------/       / EXTRA /        \ EXTRA \       \-------'
   *                                       /---------------/          \---------------\
   *                                      / Space / Layer /            \  Cmd  \ Enter \
   *                                     /       / SYSTEM/              \       \       \
   *                                    '---------------'                '---------------'
   */
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5,			            KC_6, KC_7, KC_8,    KC_9,   KC_0,     KC_BSPC,
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,			            KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_MINS,
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,	                KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_BSLS,
             KC_LOPT, KC_LCMD, MO(_EXTRA),		              MO(_EXTRA), KC_SPC, KC_RSFT,
                     KC_SPC,  MO(_SYSTEM),                  KC_ROPT,    KC_ENT
  ),

  [_EXTRA] = LAYOUT_split_4x6_5(
  /* EXTRA
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |  `~  | BrDn | BrUp |      |      |  ◀◀  |                                  |   ▶■ |  ▶▶  | Mute | VolD | VolU |  Del |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |      |      |   ↑  |      |      |                                  |  [{  |  ]}  |   ↑  |      |      |  =+  |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Shft |      |   ←  |   ↓  |   →  |      |                                  |      |   ←  |   ↓  |   →  |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Ctrl |      |      |      |      |      |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /  Opt  /---------------.    .---------------\ Shft  \
   *                                 /       /  Cmd  / Layer /      \ Layer \ Space \       \
   *                                '-------/       / EXTRA /        \ EXTRA \       \-------'
   *                                       /---------------/          \---------------\
   *                                      / Space / Layer /            \  Cmd  \ Enter \
   *                                     /       / SYSTEM/              \       \       \
   *                                    '---------------'                '---------------'
   */
    KC_GRV,  KC_BRMD, KC_BRMU, _______,  _______, KC_MPRV,			  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU,  KC_DEL,
    KC_TAB,  _______, _______,   KC_UP,  _______, _______,			  KC_LBRC, KC_RBRC,   KC_UP,  _______, _______,  KC_EQL,
    KC_LSFT, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,	      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
    KC_LCTL, _______, _______, _______,  _______, _______,        _______, _______, _______,  _______, _______, _______,
                               KC_LOPT,  KC_LCMD, KC_TRNS,		    KC_TRNS,  KC_SPC, KC_RSFT,
                                          KC_SPC, KC_TRNS,        KC_ROPT,  KC_ENT
  ),

  [_SYSTEM] = LAYOUT_split_4x6_5(
  /* SYSTEM
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | RESET|  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 | Sleep|
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | RGB_←|RGB_HI| LClk | Mse↑ | RClk |      |                                  |      | LClk | Scrl↑| RClk |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | RGB_■|      | Mse← | Mse↓ | Mse→ |      |                                  |      | Scrl←| Scrl↓| Scrl→|      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | RGB_→|RGB_HD|      |      |      |      |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /  Opt  /---------------.    .---------------\ Shft  \
   *                                 /       /  Cmd  / Layer /      \ Layer \ Space \       \
   *                                '-------/       / EXTRA /        \ EXTRA \       \-------'
   *                                       /---------------/          \---------------\
   *                                      / Space / Layer /            \  Cmd  \ Enter \
   *                                     /       / SYSTEM/              \       \       \
   *                                    '---------------'                '---------------'
   */
    RESET,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,			    KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, LAG(KC_POWER),
    RGB_RMOD, RGB_HUI, KC_BTN1, KC_MS_U, KC_BTN2, _______,			  _______, KC_BTN1, KC_WH_U, KC_BTN2, _______, _______,
    RGB_TOG,  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,	      _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
    RGB_MOD,  RGB_HUD, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
                               KC_LOPT, KC_LCMD,  KC_TRNS,	      KC_TRNS,  KC_SPC, KC_RSFT,
                                        KC_SPC,   KC_TRNS,        KC_ROPT,  KC_ENT
  ),
};
