/* Copyright 2018
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

// Allow printing version info
#include "version.h"

extern keymap_config_t keymap_config;

// Layers
#define _CO 0
#define _QW 1
#define _LO 2
#define _RA 3

enum keycodes {
  // Macros
  KC_VER = SAFE_RANGE,
  KC_PULL,
  KC_PUSH,
  KC_LS,
  KC_INCL,
};

// Cut/Paste shortcuts
#define COPY LCTL(KC_INS)
#define CUT LSFT(KC_DEL)
#define PASTE RSFT(KC_INS)

// Mod-Taps
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
#define LST(X) LSFT_T(X)
#define RST(X) RSFT_T(X)
#define LCT(X) LCTL_T(X)
#define RCT(X) RCTL_T(X)
#define LGT(X) LGUI_T(X)
#define RGT(X) RGUI_T(X)
#define TAT(X) LALT_T(X)
#define AGT(X) RALT_T(X)

// Modifiers
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_GUI OSM(MOD_LGUI)
#define LT_SPC LT(_LO, KC_SPC)
#define S_TAB LSFT_T(KC_TAB)
#define S_DEL RSFT_T(KC_DEL)
#define LT_BSPC LT(_RA, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Colemak Mod DH
   * ,-----------------------------------------------------------------------------------.
   * |   Q  |   W  |   F  |   P  | B/AGR| [    | ]    | J/AGR|   L  |   U  |   Y  |   ;  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | A/SFT|   R  |   S  |   T  |   G  | `    | '    |   M  |   N  |   E  |   I  | O/SFT|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   Z  |   X  |   C  |   D  |   V  | -    | =    |   K  |   H  |   ,  |   .  |   /  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  | Esc  | Space| Tab  | Del  | Bksp | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_CO] = LAYOUT_ortho_4x12(
    KC_Q,      KC_W,    KC_F,    KC_P,   AGT(KC_B), KC_LBRC, KC_RBRC, AGT(KC_J), KC_L,    KC_U,    KC_Y,   KC_SCLN,
    LST(KC_A), KC_R,    KC_S,    KC_T,   KC_G,      KC_GRV,  KC_QUOT, KC_M,      KC_N,    KC_E,    KC_I,   RST(KC_O),
    KC_Z,      KC_X,    KC_C,    KC_D,   KC_V,      KC_MINS, KC_EQL,  KC_K,      KC_H,    KC_COMM, KC_DOT, KC_SLSH,
    KC_LCTL,   KC_LGUI, KC_LALT, KC_ESC, LT_SPC,    S_TAB,   S_DEL,   LT_BSPC,   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
  ),
  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * |   Q  |   W  |   E  |   R  | T/AGR| [    | ]    | Y/AGR|   U  |   I  |   O  |   P  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | A/SFT|   S  |   D  |   F  |   G  | `    | '    |   H  |   J  |   K  |   L  | ;/SFT|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   Z  |   X  |   C  |   V  |   B  | -    | =    |   N  |   M  |   ,  |   .  |   /  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  | Esc  | Space| Tab  | Del  | Bksp | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QW] = LAYOUT_ortho_4x12(
    KC_Q,      KC_W,    KC_E,    KC_R,    AGT(KC_T), _______, _______, AGT(KC_Y), KC_U,    KC_I,    KC_O,    KC_P,
    LST(KC_A), KC_S,    KC_D,    KC_F,    KC_G,      _______, _______, KC_H,      KC_J,    KC_K,    KC_L,    RST(KC_SCLN),
    KC_Z,      KC_X,    KC_C,    KC_V,    KC_D,      _______, _______, KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    _______,   _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______
  ),
  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |  Esc |  CUT | WH_U | PASTE|  P*  |  P7  |  P8  |  P9  |  M_1 |  M_U |  M_2 |  M_3 |
   * |------+------+------+------+------+------+-------------+------+------+------+------|
   * |  Tab | WH_L | WH_D | WH_R |  P-  |  P4  |  P5  |  P6  |  M_L |  M_D |  M_R | PgUp |
   * |------+------+------+------+------+------+-------------+------+------+------+------|
   * | Ctrl | Shft | Gui  | M_1  |  P+  |  P1  |  P2  |  P3  | Home |  End |  Up  | PgDn |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Reset| CO/QW| PrtSc|NumLck|      |  P0  |  P.  | Enter|   P/ | Left | Down | Right|
   * `-----------------------------------------------------------------------------------'
   */
  [_LO] = LAYOUT_ortho_4x12(
    KC_ESC,  CUT,     KC_WH_U, PASTE,   KC_PAST, KC_P7,   KC_P8,   KC_P9,   KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,
    KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP,
    KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_PPLS, KC_P1,   KC_P2,   KC_P3,   KC_HOME, KC_END,  KC_UP,   KC_PGDN,
    RESET,   TG(_QW), KC_PSCR, KC_NLCK, _______, KC_P0,   KC_PDOT, KC_ENT,  KC_PSLS, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   !  |   @  |   #  |   $  |   %  |   -  |   =  |   ^  |   &  |   *  |   (  |   )  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |   1  |   2  |   3  |   4  |   5  |   ,  |   .  |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  M1  |  M2  |  M3  |  M4  | Enter|   \  |   |  |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RA] = LAYOUT_ortho_4x12(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_MINS, KC_EQL,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_COMM, KC_DOT,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_PULL, KC_PUSH, KC_LS,   KC_VER,  KC_ENT,  KC_BSLS, KC_PIPE, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Macros
    case KC_INCL:
      if (record->event.pressed) {
        SEND_STRING("#include <>"SS_TAP(X_LEFT));
      }
      return false;
    case KC_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull"SS_TAP(X_ENTER));
      }
      return false;
    case KC_PUSH:
      if (record->event.pressed) {
        SEND_STRING("git push"SS_TAP(X_ENTER));
      }
      return false;
    case KC_LS:
      if (record->event.pressed) {
        SEND_STRING("ls -la"SS_TAP(X_ENTER));
      }
      return false;
    case KC_VER:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
      }
      return false;
  }
  return true;
}
