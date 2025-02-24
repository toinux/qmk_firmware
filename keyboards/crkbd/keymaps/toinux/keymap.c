/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 @toinux

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
#include "users/toinux/keymap_qwerty_fr.h"
#include "keycodes.h"

#ifdef OLED_ENABLE
#include "oled.h"
#endif

// TEMPLATE
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Base
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |Tab/LGui|   Q    |   W    |   E    |   R    |   T    |                    |   Y    |   U    |   I    |   O    |   P    | Bksp   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | CtrlSc |   A    |   S    |   D    |   F    |   G    |                    |   H    |   J    |   K    |   L    | ;/Mous | '/Rctl |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | Shift  |   Z    |   X    |   C    |   V    |   B    |                    |   N    |   M    |   ,    |   .    |   /    | SftEnT |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |  LALT  | LOWER  |Spc/FUN |  | Spc/NAV| RAISE  |ACCENTS |
//                                      `--------------------------'  `--------------------------'
  [_BASE] = LAYOUT_split_3x6_3(
      TABLGUI,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
       CTRLSC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,  MOSCLN, QUORCTL,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SFTENT,
                                          KC_LALT,   LOWER,     FUN,     SPCNAV,   RAISE, ACCENTS

  ),

// Gaming
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  | Tab    |   Q    |   W    |   E    |   R    |   T    |                    |   Y    |   U    |   I    |   O    |   P    | Bksp   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | Ctrl   |   A    |   S    |   D    |   F    |   G    |                    |   H    |   J    |   K    |   L    | ;/Mous |   '    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | Shift  |   Z    |   X    |   C    |   V    |   B    |                    |   N    |   M    |   ,    |   .    |   /    | SftEnT |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |  LALT  |GAMING2 | Space  |  | Spc/NAV| RAISE  |ACCENTS |
//                                      `--------------------------'  `--------------------------'
  [_GAMING] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,  MOSCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SFTENT,
                                          KC_LALT, GAMING2,  KC_SPC,     SPCNAV,   RAISE, ACCENTS

  ),

// Gaming 2
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |  Tab   |   1    |   2    |   3    |   4    |   5    |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |  Esc   |   6    |   7    |   8    |   9    |   0    |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |  LGui  | Base   |        |  Vol-  |  Vol+  |  Mute  |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
  [_GAMING2] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_ESC,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_LGUI,    BASE, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          _______, _______, _______,    _______, _______, _______

  ),

// Accents, see http://marin.jb.free.fr/qwerty-fr/
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |   â    |   é    |   è    |   ê    |   €    |                    |   û    |   ù    |   î    |   ô    |   œ    |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   à    |   æ    |   ë    |        |   «    |                    |   »    |   ü    |   ï    |   ö    |   °    |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   à    |        |   ç    |        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
  [_ACCENTS] = LAYOUT_split_3x6_3(
      _______, QF_ACIR, QF_EACU, QF_EGRV, QF_ECIR, QF_EURO,                      QF_UCIR, QF_UGRV, QF_ICIR, QF_OCIR,   QF_OE, _______,
      _______, QF_AGRV,   QF_AE, QF_EDIA, _______, QF_LDAQ,                      QF_RDAQ, QF_UDIA, QF_IDIA, QF_ODIA,  QF_DEG, _______,
      _______, QF_AGRV, _______, QF_CCED, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,    _______, _______, _______

  ),

// Lower
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |   ~    |   !    |   @    |   #    |   $    |   %    |                    |   ^    |   &    |   *    |   (    |   )    |  Del   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        | SC_F1  | SC_F2  | SC_F3  | SC_F4  |        |                    |        |   _    |   +    |   {    |   }    |   |    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        | Gaming |        |  Vol-  |  Vol+  |  Mute  |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
  [_LOWER] = LAYOUT_split_3x6_3(
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
      _______,   SC_F1,   SC_F2,   SC_F3,   SC_F4, XXXXXXX,                      XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
      _______,  GAMING, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                          _______, _______, _______,   _______,  _______, _______

  ),

// Raise
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |   `    |   1    |   2    |   3    |   4    |   5    |                    |   6    |   7    |   8    |   9    |   0    |  Del   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |   -    |   =    |   [    |   ]    |   \    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        |        |        |        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
  [_RAISE] = LAYOUT_split_3x6_3(
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                          _______, _______, _______,   _______,  _______, _______

  ),

// Functions and keypad
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |   F1   |   F2   |   F2   |   F4   |        |                    |        |   7    |   8    |   9    |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   F5   |   F6   |   F7   |   F8   |        |                    |        |   4    |   5    |   6    |   -    |   /    |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   F9   |   F10  |   F11  |   F12  |        |                    |        |   1    |   2    |   3    |   +    |   *    |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |   =    |   0    |   .    |
//                                      `--------------------------'  `--------------------------'
  [_FUN] = LAYOUT_split_3x6_3(
      _______,   KC_F1,    KC_F2,  KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, _______,
      _______,   KC_F5,    KC_F6,  KC_F7,   KC_F8, XXXXXXX,                      XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PSLS,
      _______,   KC_F9,   KC_F10, KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PPLS, KC_PAST,
                                          _______, _______, _______,   KC_PENT,    KC_P0, KC_PDOT

  ),

//  Navigation and function keys
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |   F1   |   F2   |   F2   |   F4   |        |                    |        | Pg Up  |   Up   | Pg Dn  |  Ins   |  Del   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   F5   |   F6   |   F7   |   F8   |        |                    |  Home  |  Left  |  Down  |  Right |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |   F9   |   F10  |   F11  |   F12  |        |                    |  Space |  End   |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
  [_NAV] = LAYOUT_split_3x6_3(
      _______,   KC_F1,    KC_F2,  KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, KC_INS,   KC_DEL,
      _______,   KC_F5,    KC_F6,  KC_F7,   KC_F8, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
      _______,   KC_F9,   KC_F10, KC_F11,  KC_F12, XXXXXXX,                       KC_SPC,  KC_END, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                        _______,   _______, _______,    _______, _______, _______

  ),

// Mouse
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |        |        | Wh up  | Ms up  | Wh dn  |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        | Ms lft | Ms dn  | Ms rgt |        |                    |        |  btn1  |  btn3  |  btn2  |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  |        |        | Wh lft |        | Wh rgt |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
  [_MOUSE] = LAYOUT_split_3x6_3(
      _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______,                      _______, _______, _______, _______, _______, _______,
      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                      _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
      _______, _______, KC_WH_L, _______, KC_WH_R, _______,                      _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,    _______, _______, _______

  ),

// Adjust
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |  Reset |        |        |        |        | Print  |                    | Num    | Caps   | Scroll |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | On/Off | Hue ↑  | Sat ↑  | Brght ↑|        |        |                    |        |        |        |        |        |        |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | Cycle  | Hue ↓  | Sat ↓  | Brght ↓|        |        |                    |        |        |        |        |        |        |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |        |        |        |  |        |        |        |
//                                      `--------------------------'  `--------------------------'
  [_ADJUST] = LAYOUT_split_3x6_3(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                       KC_NUM, KC_CAPS, KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX,
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          _______, _______, _______,    _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTRLSC:
        case SFTENT:
        case TABLGUI:
            return true;
        default:
            return false;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case QF_ACIR:
        case QF_EACU:
        case QF_EGRV:
        case QF_ECIR:
        case QF_AGRV:
        case QF_AE:
        case QF_EDIA:
        case QF_CCED:
        case QF_UCIR:
        case QF_UGRV:
        case QF_ICIR:
        case QF_OCIR:
        case QF_OE:
        case QF_UDIA:
        case QF_IDIA:
        case QF_ODIA:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool caps_word_active  = false;
void caps_word_set_user(bool active) {
    caps_word_active = active;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif // OLED_ENABLE

    switch (keycode) {
        case FUN:
            if  (!host_keyboard_led_state().num_lock) {
                tap_code(KC_NUM_LOCK);
            }
        return true;
        break;
    }
    return true;
}

void keyboard_post_init_user(void) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
#endif
}
