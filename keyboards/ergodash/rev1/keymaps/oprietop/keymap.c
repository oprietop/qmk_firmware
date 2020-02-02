#include QMK_KEYBOARD_H

// Allow printing version info
#include "version.h"

// Layers
#define _DH 0
#define _QW 1
#define _DV 2
#define _FN 3
#define _AD 4
#define _EM 5

enum custom_keycodes {
  MODDH = SAFE_RANGE,
  QWERTY,
  DVORAK,  
  // Macros
  M_WIPE,
  M_RAN64,
  M_VER,
  M_PULL,
  M_PUSH,
  M_LS,
  M_INCL,
  #ifdef UNICODE_ENABLE
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
    UC_LENY,
    UC_WHAT,
    UC_CRY,
    UC_SHR2,
    UC_HAPY,
    UC_STRG,
  #endif
};

// Shortcuts
#define COPY LCTL(KC_INS)
#define CUT LSFT(KC_DEL)
#define PASTE RSFT(KC_INS)
#define RGB_RMD RGB_RMOD
// Shift when held, Space when tapped
#define S_SPC LSFT_T(KC_SPC)
// Layer Toggle when held. Space when tapped
#define LT_SPC LT(_FN, KC_SPC)
// Shift when held, BackSpace when tapped
#define S_BSPC RSFT_T(KC_BSPC)
// Layet toggle when held, BackSpace when tapped
#define LT_BSPC LT(_FN, KC_BSPC)
// Shift Mod Taps
#define S_MINS LSFT_T(KC_MINS)
#define S_EQL RSFT_T(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DH] = LAYOUT( /* COLEMAK MOD-DH*/
    KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_HOME,           KC_END,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSLS, \
    KC_LBRC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, KC_PGDN,          KC_PGUP,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_RBRC, \
    KC_GRV,     KC_A,    KC_R,    KC_S,    KC_T,    KC_G, M_RAN64,           KC_INS,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, \
    S_MINS,     KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  KC_TAB,           KC_DEL,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,   S_EQL, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, KC_LSFT,  LT_SPC, XXXXXXX,          XXXXXXX, LT_BSPC, KC_RSFT, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT  \
  ),
  [_QW] = LAYOUT( /* QWERTY */
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,    KC_E,    KC_R,    KC_T, _______,          _______,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______, \
    _______, _______,    KC_S,    KC_D,    KC_F, _______, _______,          _______,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______, \
    _______, _______, _______, _______,    KC_V,    KC_B, _______,          _______,    KC_N,    KC_M, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, XXXXXXX,          XXXXXXX, _______, _______, _______, _______, _______, _______  \
  ),
  [_DV] = LAYOUT( /* DVORAK */
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_QUOT, KC_COMM,  KC_DOT, _______,    KC_Y, _______,          _______,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, _______, \
    _______, _______,    KC_O,    KC_E,    KC_U,    KC_I, _______,          _______,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_SLSH, \
    _______, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X, _______,          _______,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, _______, \
    _______, _______, _______, _______, _______, _______, XXXXXXX,          XXXXXXX, _______, _______, _______, _______, _______, _______  \
  ),
  [_FN] = LAYOUT( /* FUNCTION */
     KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_VOLD,          KC_MNXT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______,  KC_ESC,    COPY, KC_WH_U,     CUT,   PASTE, KC_MPRV,          KC_MNXT, KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, _______, \
    _______,  KC_TAB, KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3, KC_MUTE,          KC_MPLY, KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  _______, \
    _______, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2, TT(_EM),          TT(_EM), KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
    _______, _______, _______, _______, TT(_AD),  KC_ENT, XXXXXXX,          XXXXXXX, KC_ENT,  TT(_AD), KC_LEFT, KC_DOWN, KC_RGHT, _______  \
  ),
  [_AD] = LAYOUT( /* ADJUST */ 
      RESET,   MODDH,  QWERTY,  DVORAK,   DEBUG,  M_WIPE, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, \
      M_VER, RGB_M_G, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_K, _______,          _______, KC_PMNS,   KC_P7,   KC_P8,   KC_P9, KC_PSLS, KC_NLCK, \
    RGB_RMD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU, XXXXXXX, _______,          _______,   KC_P0,   KC_P4,   KC_P5,   KC_P6, KC_PDOT, KC_CAPS, \
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID, XXXXXXX, _______,          _______, KC_PPLS,   KC_P1,   KC_P2,   KC_P3, KC_PAST, KC_SLCK, \
    RGB_TOG, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,  KC_ENT, XXXXXXX,          XXXXXXX, KC_PENT, KC_BSPC, _______, _______, _______, _______  \
  ),
  [_EM] = LAYOUT( /* EMOJI */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,  M_PULL, M_PUSH,     M_LS,  M_INCL, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, UC_TABL, UC_FLIP, UC_RAGE, UC_NOOO, UC_LENY, UC_SHR2, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, UC_SCRE, UC_DISA, UC_WALL, UC_SOB,  UC_WHAT, UC_HAPY, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, UC_SALU, UC_DANC, UC_SHRG, UC_DEAL, UC_CRY,  UC_STRG, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Change default layer
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
    // Macros
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
    case M_INCL:
      if (record->event.pressed) {
        SEND_STRING("#include <>"SS_TAP(X_LEFT));
      }
      return false;
    case M_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull"SS_TAP(X_ENTER));
      }
      return false;
    case M_PUSH:
      if (record->event.pressed) {
        SEND_STRING("git push"SS_TAP(X_ENTER));
      }
      return false;
    case M_LS:
      if (record->event.pressed) {
        SEND_STRING("ls -latrg"SS_TAP(X_ENTER));
      }
      return false;
    case M_VER:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
      }
      return false;
    #ifdef UNICODE_ENABLE
      // Some Emojis
      // https://r12a.github.io/app-conversion/
      // https://gist.github.com/endolith/157796
      // case UC_: //
      //   if (record->event.pressed) {
      //     send_unicode_hex_string("");
      //   }
      //   return false;
      //   break;
      case UC_LENY: // ( ͡° ͜ʖ ͡°)
        if (record->event.pressed) {
          send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029");
        }
        return false;
        break;
      case UC_WHAT: // WHATщ(ﾟДﾟщ)
        if (record->event.pressed) {
          send_unicode_hex_string("0057 0048 0041 0054 0449 0028 FF9F 0414 FF9F 0449 0029");
        }
        return false;
        break;
      case UC_CRY: // ಥ_ಥ
        if (record->event.pressed) {
          send_unicode_hex_string("0CA5 005F 0CA5");
        }
        return false;
        break;
      case UC_SHR2: // ¯\(ºдಠ)/¯
        if (record->event.pressed) {
          send_unicode_hex_string("00AF 005C 0028 00BA 0434 0CA0 0029 002F 00AF");
        }
        return false;
        break;
      case UC_HAPY: // ✌.|•͡˘‿•͡˘|.✌
        if (record->event.pressed) {
          send_unicode_hex_string("270C 002E 007C 2022 0361 02D8 203F 2022 0361 02D8 007C 002E 270C");
        }
        return false;
        break;
      case UC_STRG: // ᕙ(⇀‸↼‶)ᕗ
        if (record->event.pressed) {
          send_unicode_hex_string("1559 0028 21C0 2038 21BC 2036 0029 1557 000A");
        }
        return false;
        break;
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
//#ifdef RGBLIGHT_ENABLE
//  uint32_t layer_state_set_user(uint32_t state) {
//    switch (biton32(state)) {
//      case _CO:
//        rgblight_sethsv_noeeprom(0,0,rgblight_get_val()); // White
//        break;
//      case _QW:
//        rgblight_sethsv_noeeprom(191,255,rgblight_get_val()); // Purple
//        break;
//      case _FN:
//        rgblight_sethsv_noeeprom(28,255,rgblight_get_val()); // Orange
//        break;
//      case _AD:
//        rgblight_sethsv_noeeprom(0,255,rgblight_get_val()); // Red
//        break;
//    }
//    return state;
//  };
//#endif
