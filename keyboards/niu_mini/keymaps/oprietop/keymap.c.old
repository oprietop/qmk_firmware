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
 :* You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
  _QWERTY,
  _COLEMAK,
  _COLEMDH,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCT,
  _FUNCT2
};

enum clayers {
  _CQWERTY,
  _CCOLEMAK,
  _CCOLEMDH,
  _CDVORAK,
  _CLOWER,
  _CRAISE,
  _CADJUST
};

enum keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  COLEMDH,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  FUNCT
};


#ifdef autoshift_enabled
  autoshift_enabled = false;
  autoshift_flush();
#endif

// Default Layer toggle
// #define QWERTY  DF(_QWERTY)
// #define COLEMAK DF(_COLEMAK)
// #define COLEMDH DF(_COLEMDH)
// #define DVORAK  DF(_DVORAK)
// #define FUNCT   DF(_FUNCT)

// MOmentary layer switch
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FUNCT  MO(_FUNCT)

// Layer Tap. Switch to <left> layer when held of tap <right>
#define LOWSPC LT(_LOWER, KC_BSPC)
#define RAIENT LT(_RAISE, KC_ENT)
#define DELFN  LT(_FUNCT, KC_DEL)

// Shift when held, Enter when tapped
#define LSENT LSFT_T(KC_ENT)
#define RSENT RSFT_T(KC_ENT)

// Tap Dance Declarations
enum {
  TD_INT = 0,
  TD_BRC,
  TD_BRK, 
  TD_PAR,
  TD_ML,
  TD_AD,
  TD_QUO,
  TD_NET,
  TD_BE,
  TD_AO,
  TD_REG,
  TD_PLM,
  TD_SLA,
  TD_ORA,
  TD_LSP
};

// Custom tap_dance_double function to allow mod keys, RALT basically
void mod_tpd(qk_tap_dance_state_t *state, uint16_t left, uint16_t right, uint16_t lmod, uint16_t rmod) {
  uint16_t kc, mod;

  if (state->count == 0)
    return;

  kc  = (state->count == 1) ? left : right;
  mod = (state->count == 1) ? lmod : rmod;

  if (mod)
    register_code(mod);

  register_code(kc);
  unregister_code(kc);

  if (mod)
    unregister_code(mod);

  if (state->count >= 2)
    reset_tap_dance(state);
}

void braces(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_LBRC, KC_RBRC, KC_RALT, KC_RALT);
}

void brackets(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_QUOTE, KC_BSLS, KC_RALT, KC_RALT);
}

void net(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_3, KC_2, KC_RALT, KC_RALT);
}

void andor(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_6, KC_1, KC_LSFT, KC_RALT);
}

void regex(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_0, KC_6, KC_LSFT, KC_RALT);
}

void plusmul(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_RBRC, KC_RBRC, 0, KC_LSFT);
}

void slash(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_7, KC_GRV, KC_LSFT, KC_RALT);
}

void ora(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_GRV, KC_GRV, 0, KC_LSFT);
}

void lessper(qk_tap_dance_state_t *state, void *user_data) {
  mod_tpd(state, KC_SLSH, KC_5, 0, KC_LSFT);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_PAR] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_8), LSFT(KC_9)),    /* () */ 
  [TD_BRC] = ACTION_TAP_DANCE_FN(braces),                        /* [] */
  [TD_BRK] = ACTION_TAP_DANCE_FN(brackets),                      /* {} */
  [TD_ML]  = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_NUBS), KC_NUBS),    /* >< */
  [TD_AD]  = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_EQL),           /* !¡ */
  [TD_INT] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_PLUS),          /* ?¿ */
  [TD_QUO] = ACTION_TAP_DANCE_DOUBLE(KC_AT, KC_MINS),            /* "' */
  [TD_NET] = ACTION_TAP_DANCE_FN(net),                           /* #@ */
  [TD_BE]  = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_LBRC), LSFT(KC_4)), /* ^$ */
  [TD_AO]  = ACTION_TAP_DANCE_FN(andor),                         /* &| */
  [TD_REG] = ACTION_TAP_DANCE_FN(regex),                         /* =~ */
  [TD_PLM] = ACTION_TAP_DANCE_FN(plusmul),                       /* +* */
  [TD_SLA] = ACTION_TAP_DANCE_FN(slash),                         /* /\ */
  [TD_ORA] = ACTION_TAP_DANCE_FN(ora),                           /* ºª */
  [TD_LSP] = ACTION_TAP_DANCE_FN(lessper)                        /* -% */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | Tab  | Bksp |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | Esc  |   ´  |   H  |   J  |   K  |   L  |   Ñ  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | Shift|Enter |   N  |   M  |   ,  |   .  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Func |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_CQWERTY] = LAYOUT_ortho_4x12(
  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_DEL, KC_BSPC, KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,   
  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_TAB, KC_QUOT, KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,
  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   LSENT,  RSENT,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  KC_LCTL, KC_LALT, KC_LGUI, DELFN, LOWSPC, KC_SPC, KC_SPC,  RAIENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  | Tab  | Bksp |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  | Esc  |  "   |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |Shift |Enter |   K  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Func |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_CCOLEMAK] = LAYOUT_ortho_4x12(
  KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,   KC_DEL, KC_BSPC, KC_J,   KC_L,    KC_U,    KC_Y,   KC_SCLN,
  KC_A,    KC_R,    KC_S,    KC_T,  KC_D,   KC_TAB, KC_QUOT, KC_H,   KC_N,    KC_E,    KC_I,   KC_O,   
  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   LSENT,  RSENT,   KC_K,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,
  KC_LCTL, KC_LALT, KC_LGUI, DELFN, LOWSPC, KC_SPC, KC_SPC,  RAIENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
 
/* Colemak DH
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  | Tab  | Bksp |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  | Esc  |  "   |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |Shift |Enter |   K  |   H  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Func |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_CCOLEMDH] = LAYOUT_ortho_4x12(
  KC_Q,    KC_W,    KC_F,    KC_P,  KC_B,   KC_TAB, KC_BSPC, KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN,
  KC_A,    KC_R,    KC_S,    KC_T,  KC_G,   KC_ESC, KC_QUOT, KC_M,   KC_N,    KC_E,    KC_I,    KC_O,
  KC_Z,    KC_X,    KC_C,    KC_D,  KC_V,   LSENT,  RSENT,   KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
  KC_LCTL, KC_LALT, KC_LGUI, DELFN, LOWSPC, KC_SPC, KC_SPC,  RAIENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   "  |   ,  |   .  |   P  |   Y  | Tab  | Bksp |   F  |   G  |   C  |   R  |   L  |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |   A  |   O  |   E  |   U  |   I  | Esc  |  /   |   D  |   H  |   T  |   N  |   S  |
 * |------+------+------+------+------|------|------+------+------+------+------+------|
 * |   ;  |   Q  |   J  |   K  |   X  | Shift|Enter |   B  |   M  |   W  |   V  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Func |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_CDVORAK] = LAYOUT_ortho_4x12(
  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_TAB, KC_BSPC, KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    
  KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_ESC, KC_SLSH, KC_D,   KC_H,    KC_T,    KC_N,    KC_S,    
  KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   LSENT,  RSENT,   KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,    
  KC_LCTL, KC_LALT, KC_LGUI, DELFN, LOWSPC, KC_SPC, KC_SPC,  RAIENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   "  |   ·  |   $  |   %  | Ins  | Bksp |  ºª  |  /\  |  -%  |  +*  |  =~  |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |  ç   |  ^$  |  !¡  |  ?¿  |  "'  |  #@  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  |&  |  ()  |  []  |  {}  |  ><  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Bcksp    |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md
 */

[_CLOWER] = LAYOUT_ortho_4x12(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_INS , KC_BSPC, TD(TD_ORA), TD(TD_SLA), TD(TD_LSP), TD(TD_PLM), TD(TD_REG),
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_BSLS, TD(TD_BE),  TD(TD_AD),  TD(TD_INT), TD(TD_QUO), TD(TD_NET),
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, TD(TD_AO),  TD(TD_PAR), TD(TD_BRC), TD(TD_BRK), TD(TD_ML), 
  _______, _______, _______, _______, _______, KC_BSPC, KC_BSPC, _______,    KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  | Ins  | Bksp |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+-------------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  | Del  |  Ç   |  F6  |   '  |   ¡  |   `  |   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |ISO # |ISO / |   {  |   }  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  Del |     Del     |      |Home  |Pg Dn |Pg Up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_INS,  KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,           KC_0,         
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_DEL,  KC_PIPE, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC,        KC_RBRC,      
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, _______, _______, KC_F12,  KC_NUHS, KC_NUBS, RALT(KC_QUOTE), RALT(KC_BSLS),
  _______, _______, _______, _______, KC_DEL, KC_DEL,  KC_DEL,  _______, KC_HOME, KC_PGDN, KC_PGUP,        KC_END
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |   \  |   |  |   @  |   #  |   ~  |   €  |  ¬   |Prtscr|      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |BLStep|      |      |      |      |Qwerty|Dvorak|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |AS_TGL|      |      |      |      |Colmak|Colmdh|      |Mouse1|Mouse2|Mouse3|Mouse4|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |     Del     |      |MouseL|MouseD|MouseU|MouseR|
 * `-----------------------------------------------------------------------------------'
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_audio.md
 */
[_CADJUST] = LAYOUT_ortho_4x12(
  RALT(KC_GRV), RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), KC_PSCR, KC_HOME, KC_UP,   KC_END,  KC_PGUP,
  BL_STEP,      _______,    _______,    _______,    _______,    QWERTY,     DVORAK,     _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
  KC_ASTG,      _______,    _______,    _______,    _______,    COLEMAK,    COLEMDH,    _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4,
  RESET,        _______,    _______,    _______,    _______,    KC_DEL,     KC_DEL,     _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
),

// DEFAULT

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  KC_LCTL, KC_LALT, KC_LGUI, DELFN, LOWSPC, KC_SPC, KC_SPC,  RAIENT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  KC_LCTL, KC_LALT, KC_LGUI, DELFN, LOWSPC, KC_SPC, KC_SPC,  RAIENT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P,   KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,   KC_U,   KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
  KC_LCTL, KC_LALT, KC_LGUI, DELFN,  LOWSPC, KC_SPC, KC_SPC,  RAIENT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Colemak DH
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SEnt |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |  Up  | SEnt |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |DelFN |Lower |    Space    |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMDH] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_Q,    KC_W,    KC_F,  KC_P,   KC_B,   KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_BSPC, 
  KC_TAB,  KC_A,    KC_R,    KC_S,  KC_T,   KC_G,   KC_M,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT, 
  LSENT,   KC_Z,    KC_X,    KC_C,  KC_D,   KC_V,   KC_K,   KC_H,   KC_COMM, KC_DOT,  KC_UP,   RSENT,   
  KC_LCTL, KC_LALT, KC_LGUI, DELFN, LOWSPC, KC_SPC, KC_SPC, RAIENT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Del  |Pg Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Ins  | Home |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, _______,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_DEL,  KC_PGUP, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_INS,     KC_HOME, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_DEL,  KC_PGUP, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|ColmDH|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |KC_AST|Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Shift + Ins |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  RESET,   DEBUG,   _______, _______, _______, _______,   _______,   TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______,  MU_MOD,  AU_ON,   AU_OFF,  AG_NORM,  AG_SWAP,   QWERTY,  COLEMAK, DVORAK,  COLEMDH, _______,
  KC_ASTG, MUV_DE,   MUV_IN,  MU_ON,   MU_OFF,  MI_ON,    MI_OFF,    _______, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,
  BL_TOGG, BL_STEP, _______, _______, _______, S(KC_INS), S(KC_INS), _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD
),

[_FUNCT] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN3, KC_BTN4, KC_BTN5,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
),	

[_FUNCT2] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN3, KC_BTN4, KC_BTN5,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_WH_U, KC_BTN2,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R
)
	
};

// Handle Tri layer (Lower + Raise) with LT support
// https://github.com/msandiford/qmk_firmware/commit/de5b55a6c5e14bf54d77db6ac5a7d8c5cb2c9d7c#diff-013b1ab0d16580ef9aaf2259776a78cd
#define LOWER_AND_RAISE ((1UL << _LOWER) | (1UL << _RAISE))
#define FUNCT_AND_LOWER ((1UL << _FUNCT) | (1UL << _LOWER))

uint32_t layer_state_set_kb(uint32_t state) {
  if ((state & LOWER_AND_RAISE) == LOWER_AND_RAISE) {
    state |= 1UL << _ADJUST;
  } else {
    state &= ~(1UL << _ADJUST);
  }
  if ((state & FUNCT_AND_LOWER) == FUNCT_AND_LOWER) {
    state |= 1UL << _FUNCT2;
  } else {
    state &= ~(1UL << _FUNCT2);
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string.\n");
        set_single_persistent_default_layer(_QWERTY);
        SEND_STRING("\nLayout changed to QWERTY.\n");
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
        SEND_STRING("\nLayout changed to COLEMAK.\n");
      }
      return false;
      break;
    case COLEMDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMDH);
        SEND_STRING("\nLayout changed to COLEMAK MOD DH.\n");
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
        SEND_STRING("\nLayout changed to DVORAK.\n");
      }
      return false;
      break;
  }
  return true;
}

