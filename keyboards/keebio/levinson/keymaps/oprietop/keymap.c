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
#define _DH 0
#define _QW 1
#define _DV 2
#define _LO 3
#define _RA 4
#define _AD 5

enum custom_keycodes {
  MODDH  = SAFE_RANGE,
  QWERTY,
  DVORAK,
  M_BSPC,
  M_WIPE,
  M_RAN64,
  // Macros
  KC_VER,
  KC_PULL,
  KC_PUSH,
  KC_LS,
  KC_INCL,
};

// Shortcuts
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
#define LT_ESC LT(_AD, KC_ESC)
#define LT_GUI LT(_AD, KC_RGUI)
#define LT_TAB LT(_LO, KC_TAB)
#define LT_DEL LT(_RA, KC_DEL)
#define LT_SPC LT(_LO, KC_SPC)
#define S_SPC LSFT_T(KC_SPC)
#define S_TAB LSFT_T(KC_TAB)
#define S_DEL RSFT_T(KC_DEL)
#define LT_BSPC LT(_RA, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Colemak Mod DH
   * ,-----------------------------------------------------------------------------------.
   * | [    |   Q  |   W  |   F  |   P  | B/AGR| J/AGR|   L  |   U  |   Y  |   ;  | ]    |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | `/SFT|   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  | '/SFT|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | -    |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  | =    |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |Esc/AD|Tab/SH|Spc/Lo|Bks/Up|Del/SH| Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_DH] = LAYOUT_ortho_4x12(
    KC_LBRC,     KC_Q,    KC_W,    KC_F,   KC_P,   AGT(KC_B), AGT(KC_J), KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_RBRC,
    LST(KC_GRV), KC_A,    KC_R,    KC_S,   KC_T,   KC_G,      KC_M,      KC_N,    KC_E,    KC_I,   KC_O,    RST(KC_QUOT),
    KC_MINS,     KC_Z,    KC_X,    KC_C,   KC_D,   KC_V,      KC_K,      KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_EQL,
    KC_LCTL,     KC_LGUI, KC_LALT, LT_ESC, S_TAB,  LT_SPC,    LT_BSPC,   S_DEL,   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
  ),
  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | [    |   Q  |   W  |   E  |   R  | T/AGR| Y/AGR|   U  |   I  |   O  |   P  | ]    |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | `/SFT|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | '/SFT|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | -    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | =    |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |Esc/AD|Tab/SH|Spc/Lo|Bks/Up|Del/SH| Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QW] = LAYOUT_ortho_4x12(
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    AGT(KC_T), AGT(KC_Y), KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______,   _______,   _______, _______, _______, _______, _______
  ),
  /* Dvorak
   * ,-----------------------------------------------------------------------------------.
   * | [    |   '  |   ,  |   .  |   P  | Y/AGR| F/AGR|   G  |   C  |   R  |   L  | ]    |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | `/SFT|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | /    |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | -    |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | =    |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | Gui  | Alt  |Esc/AD|Tab/SH|Spc/Lo|Bks/Up|Del/SH| Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_DV] = LAYOUT_ortho_4x12(
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    AGT(KC_Y), AGT(KC_F), KC_G,    KC_C,    KC_R,    KC_L,    _______, \
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,      KC_D,      KC_H,    KC_T,    KC_N,    KC_S,    RST(KC_SLSH), \
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,      KC_B,      KC_M,    KC_W,    KC_V,    KC_Z,    _______, \
    _______, _______, _______, _______, _______, _______,   _______,   _______, _______, _______, _______, _______
  ),
  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |Vol Up|  Esc | Copy | W_Up |  CUT | PASTE| PgUp |M_Btn1| M_Up |M_Btn2|M_Btn3| Next |
   * |------+------+------+------+------+------+-------------+------+------+------+------|
   * |Vol Do|  Tab | W_Le | W_Do | W_Ri |M_Btn3| Home | M_Le | M_Do | M_Ri | End  | Prev |
   * |------+------+------+------+------+------+-------------+------+------+------+------|
   * | Mute | Ctrl | Shift| Gui  |M_Btn1|M_Btn2| PgDN | Left | Down |  Up  | Rght | Play |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Enter|      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_LO] = LAYOUT_ortho_4x12(
    KC_VOLU, KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,   KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_MNXT, \
    KC_VOLD, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3, KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  KC_MPRV, \
    KC_MUTE, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, \
    _______, _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, _______
  ),
  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   |  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   \  |
   * |-------------+------+------+------+------+------+------+------+------+------+------|
   * |   .  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   ,  |
   * |-------------+------+------+------+------+------+------+------+------+------+------|
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      | Enter|      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_RA] = LAYOUT_ortho_4x12(
    KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_DOT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COMM, \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, _______, _______
  ),
  /* Adjust
   * ,-----------------------------------------------------------------------------------.
   * | Reset|CoMoDH|Qwerty|Dvorak|      |PrtScr| Minus|  P7  |  P8  |  P9  | Slash|NumLck|
   * |-------------+------+------+------+------+------+------+------+------+------+------|
   * | Wipe |RgbRMo|RgbHui|RgbSai|RgbVai|BrghUp|  P0  |  P4  |  P5  |  P6  | Dot  |CapLck|
   * |-------------+------+------+------+------+------+------+------+------+------+------|
   * |RbgTog|RgbMod|RbgHud|RgbSad|RgbVad|BrghDo| Plus |  P1  |  P2  |  P3  | Ast  |ScrLck|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |BckSpc|  Del |PEnter|      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_AD] = LAYOUT_ortho_4x12(
     RESET,   MODDH,    QWERTY,  DVORAK,  _______, KC_PSCR, KC_PMNS, KC_P7,  KC_P8,   KC_P9,   KC_PSLS, KC_NLCK, \
     M_WIPE,  RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU, KC_P0,   KC_P4,  KC_P5,   KC_P6,   KC_PDOT, KC_CAPS, \
     RGB_TOG, RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID, KC_PPLS, KC_P1,  KC_P2,   KC_P3,   KC_PAST, KC_SLCK, \
     BL_STEP, KC_VER,   _______, _______, _______, _______, KC_BSPC, KC_DEL, KC_PENT, _______, _______, _______ \
  )
};

void matrix_init_user(void) { // Runs boot tasks for keyboard
    rgblight_enable();
    //rgblight_sethsv(340, 255, 255); // Red Magenta
    rgblight_sethsv(12, 255, 255); // Orange
    //rgblight_sethsv(276,255,170); // Purple
    rgblight_mode(3);
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QW);
      }
      return false;
      break;
    case MODDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DH);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DV);
      }
      return false;
      break;
    case M_WIPE: // Wipe the eeprom and reset the board
      if (record->event.pressed) {
        eeconfig_init();
        reset_keyboard();
      }
      return false;
      break;
    case M_RAN64:
      if (record->event.pressed) {
        tap_random_base64();
      }
      return false;
      break;
    // Macros
    case KC_INCL:
      if (record->event.pressed) {
        SEND_STRING("#include <>"SS_TAP(X_LEFT));
      }
      return false;
      break;
    case KC_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case KC_PUSH:
      if (record->event.pressed) {
        SEND_STRING("git push"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case KC_LS:
      if (record->event.pressed) {
        SEND_STRING("ls -la"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case KC_VER:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
      }
      return false;
      break;
  }
  return true;
}
