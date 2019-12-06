#include QMK_KEYBOARD_H

// Layers
#define _CO 0
#define _QW 1
#define _FN 2
#define _AD 3

enum custom_keycodes {
  M_WIPE = SAFE_RANGE,
  M_RAN64,
  UC_FLIP,
  UC_TABL,
  UC_SHRG,
  UC_DISA,
  UC_DANC,
  UC_SCRE,
  UC_WALL,
  UC_SOB,
  UC_DEAL,
  UC_RAGE,
  UC_NOOO,
  UC_SALU,
};

// Shortening RGB_RMOB
#define RGB_RMD RGB_RMOD
// Shift when held, Enter when tapped
#define LSEN LSFT_T(KC_ENT)
#define RSEN RSFT_T(KC_ENT)
// Shift when held, BackSpace when tapped
#define S_BSPC RSFT_T(KC_BSPC)
// Layer Toggle when held. BackSpade when tapped
#define LT_SPC LT(_FN, KC_SPC)
// Shift when held, Space when tapped
#define LSSP LSFT_T(KC_SPC)
// ALTGR when held, Space when tapped
#define RALSPC RALT_T(KC_SPC)
// Shift Mod Taps
#define S_MINS LSFT_T(KC_MINS)
#define S_EQL RSFT_T(KC_EQL)
// Cut/Paste shortcuts
#define PASTE RSFT(KC_INS)
#define CUT LSFT(KC_DEL)
#define COPY LCTL(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CO] = LAYOUT( /* COLEMAK MOD-DH*/
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,         KC_END,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    KC_LBRC, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_PGDN,         KC_PGUP, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_RBRC, \
    KC_GRV,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    M_RAN64,         KC_INS,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
    S_MINS,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_TAB,          KC_DEL,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, S_EQL,   \
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, TT(_FN), LT_SPC,  XXXXXXX,         XXXXXXX, S_BSPC,  TT(_FN), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),
  [_QW] = LAYOUT( /* QWERTY */
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_E,    KC_R,    KC_T,    _______,         _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
    _______, _______, KC_S,    KC_D,    KC_F,    _______, _______,         _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
    _______, _______, _______, _______, KC_V,    KC_B,    _______,         _______, KC_N,    KC_M,    _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, XXXXXXX,         XXXXXXX, _______, _______, _______, _______, _______, _______  \
  ),
  [_FN] = LAYOUT( /* FUNCTION */
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_VOLU,         KC_MNXT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,   KC_VOLD,         KC_MPRV, KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, _______, \
    _______, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3, KC_MUTE,         KC_MPLY, KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  _______, \
    _______, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2, M_RAN64,         KC_INS,  KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
    _______, _______, _______, _______, TT(_AD), KC_ENT,  XXXXXXX,         XXXXXXX, KC_ENT,  TT(_AD), KC_LEFT, KC_DOWN, KC_RGHT, _______  \
  ),
  [_AD] = LAYOUT( /* ADJUST */
    RESET,   M_WIPE,  DEBUG,   KC_ACL0, KC_ACL1, KC_ACL2, M_RAN64,         M_RAN64, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS, KC_PSCR, \
    RGB_M_G, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_K, XXXXXXX, XXXXXXX,         XXXXXXX, UC_TABL, UC_FLIP, UC_RAGE, UC_NOOO, XXXXXXX, KC_NLCK, \
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, UC_SCRE, UC_DISA, UC_WALL, UC_SOB,  XXXXXXX, KC_SLCK, \
    RGB_RMD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, UC_SALU, UC_DANC, UC_SHRG, UC_DEAL, XXXXXXX, KC_CAPS, \
    TG(_QW), RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, TG(_QW), XXXXXXX,         XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

void matrix_init_user(void) { // Runs boot tasks for keyboard
  #ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_LNX);
  #endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_enable();
    //rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
    //rgblight_mode(rgblight_get_mode());
    //rgblight_sethsv(276,255,170); // Purple
    rgblight_sethsv(0,0,10); // White
    //00000ght_sethsv(240,255,50); // blue
    //rgblight_sethsv(43,100,50); // Goldenrod
    //rgblight_sethsv(236, 96, 100); // Goldenrod
    rgblight_mode(21);
    //rgblight_sethsv(0,0,rgblight_get_val()); // White
  #endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
    #ifdef UNICODE_ENABLE
      case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
        if (record->event.pressed) {
          send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
        }
        return false;
        break;
      case UC_TABL: // ┬─┬ノ( º _ ºノ)
        if (record->event.pressed) {
          send_unicode_hex_string("252C 2500 252C 30CE 0028 0020 00BA 0020 005F 0020 00BA 30CE 0029");
        }
        return false;
        break;
      case UC_SHRG: // ¯\_(ツ)_/¯
        if (record->event.pressed) {
          send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        }
        return false;
        break;
      case UC_DISA: // ಠ_ಠ
        if (record->event.pressed) {
          send_unicode_hex_string("0CA0 005F 0CA0");
        }
        return false;
        break;
      case UC_DANC: // (〜￣△￣)〜
        if (record->event.pressed) {
          send_unicode_hex_string("0028 301C FFE3 25B3 FFE3 0029 301C");
        }
        return false;
        break;
      case UC_SCRE: // ヽ(ﾟДﾟ)ﾉ
        if (record->event.pressed) {
          send_unicode_hex_string("30FD 0028 FF9F 0414 FF9F 0029 FF89");
        }
        return false;
        break;
      case UC_WALL: // ┬┴┬┴┤(･_├┬┴┬┴
        if (record->event.pressed) {
          send_unicode_hex_string("252C 2534 252C 2534 2524 0028 FF65 005F 251C 252C 2534 252C 2534");
        }
        return false;
        break;
      case UC_SOB: // (ಢ⊱ಢ ｡)
        if (record->event.pressed) {
          send_unicode_hex_string("0028 0CA2 22B1 0CA2 0020 FF61 0029");
        }
        return false;
        break;
      case UC_DEAL: // ( ∙_∙) ( ∙_∙)>⌐■-■ (⌐■_■)
        if (record->event.pressed) {
          send_unicode_hex_string("0028 0020 2219 005F 2219 0029 0020 0028 0020 2219 005F 2219 0029 003E 2310 25A0 002D 25A0 0020 0028 2310 25A0 005F 25A0 0029");
        }
        return false;
        break;
      case UC_RAGE: // （╬ಠ益ಠ)
        if (record->event.pressed) {
          send_unicode_hex_string("FF08 256C 0CA0 76CA 0CA0 0029");
        }
        return false;
        break;
      case UC_NOOO: // (」ﾟﾛﾟ)｣NOOOooooo━
        if (record->event.pressed) {
          send_unicode_hex_string("0028 300D FF9F FF9B FF9F 0029 FF63 004E 004F 004F 004F 006F 006F 006F 006F 006F 2501");
        }
        return false;
        break;
      case UC_SALU: // (￣^￣)ゞ
        if (record->event.pressed) {
          send_unicode_hex_string("0028 FFE3 005E FFE3 0029 309E");
        }
        return false;
        break;
    #endif
  }
  return true;
};

// Change LED colors depending on the layer.
// https://github.com/qmk/qmk_firmware/blob/master/quantum/rgblight_list.h
#ifdef RGBLIGHT_ENABLE
  uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
      case _CO:
        rgblight_sethsv_noeeprom(0,0,rgblight_get_val()); // White
        break;
      case _QW:
        rgblight_sethsv_noeeprom(191,255,rgblight_get_val()); // Purple
        break;
      case _FN:
        rgblight_sethsv_noeeprom(28,255,rgblight_get_val()); // Orange
        break;
      case _AD:
        rgblight_sethsv_noeeprom(0,255,rgblight_get_val()); // Red
        break;
    }
    return state;
  };
#endif
