// oprietop's xd75 keymap
#include QMK_KEYBOARD_H

// Layers
#define _CO 0
#define _QW 1
#define _FN 2
#define _AD 3

// Shortcuts
#define PASTE RSFT(KC_INS)
#define CUT LSFT(KC_DEL)
#define CPY LCTL(KC_INS)
#define RGB_RMD RGB_RMOD
// Shift when held, Enter when tapped
#define LSEN LSFT_T(KC_ENT)
#define RSEN RSFT_T(KC_ENT)
// Shift when held, Space when tapped
#define LSSP LSFT_T(KC_SPC)

enum custom_keycodes {
  M_RAN64 = SAFE_RANGE,
  M_WIPE,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* COLEMAK MOD-DH
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | ESC    | 1      | 2      | 3      | 4      | 5      | HOME   | PG UP  | END    | 6      | 7      | 8      | 9      | 0      | BACKSP |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
  * | TAB    | Q      | W      | F      | P      | B      | [      | PG DN  | ]      | J      | L      | U      | Y      | ;      |  \     |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * | BACKSP | A      | R      | S      | T      | G      | DEL    | INS    | `      | M      | N      | E      | I      | O      |  '     |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
  * | LSHENT | Z      | X      | C      | D      | V      | -      | UP     | =      | K      | H      | ,      | .      | /      | RSHENT |
  * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
  * | LCTRL  | LGUI   | LALT   | MENU   | FUNCT  | RALSPC | LEFT   | DOWN   | LEFT   | RSHENT | FUNCT  | CAPSL  | RALT   | RGUI   | RCTL   |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */
  [_CO] = LAYOUT_ortho_5x15( /* COLEMAK MOD-DH*/
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME, KC_PGUP, KC_END,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_LBRC, KC_PGDN, KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_DEL,  KC_INS,  KC_GRV,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    LSEN,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_MINS, KC_UP,   KC_EQL,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, RSEN   ,
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, TT(_FN), LSSP,    KC_LEFT, KC_DOWN, KC_RGHT, RSEN,    TT(_FN), KC_RALT, KC_LALT, KC_RGUI, KC_RCTL
  ),
  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    _______, _______, _______, _______, KC_V,    KC_B,    _______, _______, _______, KC_N,    KC_M,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
 /* FUNCTION
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | F11    | F1     | F2     | F3     | F4     | F5     | P/     | P*     | P-     | F6     | F7     | F8     | F9     | F10    | F12    |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        | ESC    | CUT    | WH_UP  | PASTE  | COPY   | P7     | P8     | P9     | PGUP   | MOU_B1 | MOU_UP | MOU_B2 | MOU_B3 |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        | TAB    | WH_LE  | WH_DO  | WH_RG  | RANDOM | P4     | P5     | P6     | HOME   | MOU_LE | MOU_DO | MOU_RG | END    |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        | LCTL   | LSFT   | LGUI   | MOU_B1 | MOU_B2 | P1     | P2     | P3     | PGDN   | LEFT   | DOWN   | UP     | RIGHT  |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        |        |        |        | ADJUST | SPACE  | P0     | P.     | P+     | PENT   | ADJUST |        |        |        |        |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */
  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PSLS, KC_PAST, KC_PMNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12 ,
    _______, KC_ESC,  CUT,     KC_WH_U, PASTE,   CPY,     KC_P7,   KC_P8,   KC_P9,   KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_BTN4,
    _______, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, M_RAN64, KC_P4,   KC_P5,   KC_P6,   KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  _______,
    _______, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2, KC_P1,   KC_P2,   KC_P3,   KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, MO(_AD), KC_SPC,  KC_P0,   KC_PDOT, KC_PPLS, KC_PENT, MO(_AD), _______, _______, _______, _______
  ),
 /* ADJUST
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | RESET  | M_WIPE | M ACL0 | M ACL1 | M ACL2 | AGSWAP | NUMLCK | SCRLCK | CAPS   | PAUSE  |        |        |        |        | PRSCR  |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        | STATIC | BREATH | RAINBO | KNIGHT |        |        |        |        |   E    |    M   |   O    |   J    |   I    |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * |        | MODEUP | HUE UP | SAT UP | VAL UP | BRI UP | MEDIA  | NUMLCK | COMP   |   E    |    M   |   O    |   J    |   I    |        |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * | CAPS   | MODEDN | HUE DN | SAT UP | VAL DN | BRI DN | PLAY   | VOL +  | MUTE   |   E    |    M   |   O    |   J    |   I    | CAPS   |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * | RGBTOG |        |        |        |        | RGBTOG | PREV   | VOL -  | NEXT   | COL/QW |        |        |        |        | COL/QW |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */
  [_AD] = LAYOUT_ortho_5x15( /* ADJUST */
    RESET,   M_WIPE,  KC_ACL0, KC_ACL1, KC_ACL2, AG_SWAP, KC_NLCK, KC_SLCK, KC_CAPS, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
    DEBUG,   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_K, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UC_TABL, UC_FLIP, UC_RAGE, UC_NOOO, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU, KC_MSEL, KC_NLCK, KC_MYCM, UC_SCRE, UC_DISA, UC_WALL, UC_SOB,  XXXXXXX, XXXXXXX,
    KC_CAPS, RGB_RMD, RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID, KC_MPLY, KC_VOLU, KC_MUTE, UC_SALU, UC_DANC, UC_SHRG, UC_DEAL, XXXXXXX, KC_CAPS,
    RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, KC_MPRV, KC_VOLD, KC_MNXT, TG(_QW), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_QW)
  )
};

void matrix_init_user(void) { // Runs boot tasks for keyboard
  #ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_LNX);
  #endif
  #ifdef RGBLIGHT_ENABLE
  //  rgblight_enable();
    //rgblight_sethsv(25, 255, 255); // Carbon Orange
    rgblight_sethsv(138, 100, 215); // Pulse Blue
    //rgblight_mode(13); // Swirling rainbow
  //  rgblight_mode(3);
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
