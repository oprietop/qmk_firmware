/* Copyright 2015-2017 Jack Humbert
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
#define _FN 4

enum keycodes {
  // Persitent Layers
  MODDH = SAFE_RANGE,
  QWERTY,
  // Macros
  KC_VER,
  KC_PULL,
  KC_PUSH,
  KC_LS,
  KC_INCL,
  // Sound
  S_BSKTC,
  S_ODEJY,
  S_RCKBY,
  S_DOEDR,
  S_SCALE,
  S_ONEUP,
  S_COIN,
  S_SONIC,
  S_ZELDA,
  S_DOOM,
  S_RICKR,
};

#ifdef AUDIO_ENABLE
  float song_basketcase[][2] = SONG(BASKET_CASE);
  float song_ode_to_joy[][2] = SONG(ODE_TO_JOY);
  float song_rock_a_bye_baby[][2] = SONG(ROCK_A_BYE_BABY);
  float song_doe_a_deer[][2] = SONG(DOE_A_DEER);
  float song_scale[][2] = SONG(MUSIC_SCALE_SOUND);
  float song_coin[][2] = SONG(COIN_SOUND);
  float song_one_up[][2] = SONG(ONE_UP_SOUND);
  float song_sonic_ring[][2] = SONG(SONIC_RING);
  float song_zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
  float song_zelda_treasure[][2] = SONG(ZELDA_TREASURE);
  float song_doom[][2] = SONG(E1M1_DOOM);
  float song_all_star[][2] = SONG(ALL_STAR);
  float song_mario_theme[][2] = SONG(MARIO_THEME);
  float song_mario_gameover[][2] = SONG(MARIO_GAMEOVER);
  float song_mario_mushroom[][2] = SONG(MARIO_MUSHROOM);
  float song_victory_fanfare_short[][2] = SONG(VICTORY_FANFARE_SHORT);
  float song_old_spice[][2] = SONG(OLD_SPICE);
  float song_rick_roll[][2] = SONG(RICK_ROLL);
#endif

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
#define LT_ESC LT(_FN, KC_ESC)
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
  [_CO] = LAYOUT_planck_grid(
    KC_Q,      KC_W,    KC_F,    KC_P,   AGT(KC_B), KC_LBRC, KC_RBRC, AGT(KC_J), KC_L,    KC_U,    KC_Y,   KC_SCLN,
    LST(KC_A), KC_R,    KC_S,    KC_T,   KC_G,      KC_GRV,  KC_QUOT, KC_M,      KC_N,    KC_E,    KC_I,   RST(KC_O),
    KC_Z,      KC_X,    KC_C,    KC_D,   KC_V,      KC_MINS, KC_EQL,  KC_K,      KC_H,    KC_COMM, KC_DOT, KC_SLSH,
    KC_LCTL,   KC_LGUI, KC_LALT, LT_ESC, LT_SPC,    S_TAB,   S_DEL,   LT_BSPC,   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
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
  [_QW] = LAYOUT_planck_grid(
    _______, _______, KC_E,    KC_R,    AGT(KC_T), _______, _______, AGT(KC_Y), KC_U,    KC_I,    KC_O,    KC_P,
    _______, KC_S,    KC_D,    KC_F,    _______,   _______, _______, KC_H,      KC_J,    KC_K,    KC_L,    RST(KC_SCLN),
    _______, _______, _______, KC_V,    KC_D,      _______, _______, KC_N,      KC_M,    _______, _______, _______,
    _______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______
  ),
  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |  Esc | COPY | WH_U | CUT  | PASTE|      |      | PgUp |  M_1 |  M_U |  M_2 |  M_3 |
   * |------+------+------+------+------+------+-------------+------+------+------+------|
   * |  Tab | WH_L | WH_D | WH_R | INS  |      |      | Home |  M_L |  M_D |  M_R | End  |,
   * |------+------+------+------+------+------+-------------+------+------+------+------|
   * | Ctrl | Shft | Gui  | M_1  | DEL  |      |      | PgDn | Left | Down |  Up  | Right|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Reset| CO/QW| PrtSc|NumLck|      |      |      | Enter| Ins  | Left | Down | Right|
   * `-----------------------------------------------------------------------------------'
   */
  [_LO] = LAYOUT_planck_grid(
    KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,   _______, _______, KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,
    KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_INS,  _______, _______, KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,
    KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_DEL,  _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    RESET,   TG(_QW), KC_PSCR, KC_NLCK, _______, _______, _______, KC_ENT,  KC_INS,  KC_LEFT, KC_DOWN, KC_RGHT
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
  [_RA] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_MINS, KC_EQL,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_COMM, KC_DOT,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_PULL, KC_PUSH, KC_LS,   KC_VER,  KC_ENT,  KC_BSLS, KC_PIPE, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),
  [_FN] = LAYOUT_planck_grid(
    S_BSKTC, S_ODEJY, S_RCKBY, _______, PASTE,   _______, KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN3, KC_WH_U, KC_BTN4,
    S_DOEDR, S_SCALE, S_ONEUP, S_RICKR, CUT,     _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R,
    S_COIN,  S_SONIC, S_ZELDA, S_DOOM,  COPY,    KC_INCL, KC_PULL, KC_PUSH, KC_LS,   KC_BTN1, KC_MS_U, KC_BTN2,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
  )
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
    // Sound
    case S_BSKTC:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_basketcase);
      }
      return false;
    case S_ODEJY:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_ode_to_joy);
      }
      return false;
    case S_RCKBY:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_rock_a_bye_baby);
      }
      return false;
    case S_DOEDR:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_doe_a_deer);
      }
      return false;
    case S_SCALE:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_scale);
      }
      return false;
    case S_ONEUP:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_one_up);
      }
      return false;
    case S_COIN:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_coin);
      }
      return false;
    case S_SONIC:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_sonic_ring);
      }
      return false;
    case S_ZELDA:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_zelda_puzzle);
      }
      return false;
    case S_DOOM:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_doom);
      }
      return false;
    case S_RICKR:
      if (record->event.pressed) {
          stop_all_notes();
          PLAY_SONG(song_rick_roll);
      }
      return false;
  }
  return true;
}
