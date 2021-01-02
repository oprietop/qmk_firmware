#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
extern uint8_t is_master;

#ifdef OLED_DRIVER_ENABLE
static char     keylog_str[6] = {};
static uint16_t log_timer = 0;
static const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
#endif

// Layers
#define _DH 0
#define _QW 1
#define _DV 2
#define _LO 3
#define _RA 4
#define _AD 5
#define _EM 6

enum keycodes {
  MODDH = SAFE_RANGE,
  QWERTY,
  DVORAK,
  M_BSPC,
  M_WIPE,
  M_RGBRS,
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
  UC_LENY,
  UC_WHAT,
  UC_CRY,
  UC_SHR2,
  UC_HAPY,
  UC_STRG
};

// Shortcuts
#define COPY LCTL(KC_INS)
#define CUT LSFT(KC_DEL)
#define PASTE RSFT(KC_INS)
#define EMOJI TT(_EM)

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
   * ,-----------------------------------------.         ,-----------------------------------------.
   * | [    |   Q  |   W  |   F  |   P  |B/RALT|         |J/RALT|   L  |   U  |   Y  |   ;  | ]    |
   * |------+------+------+------+------+------|         |------+------+------+------+------+------|
   * | `/SFT|   A  |   R  |   S  |   T  |   G  |         |   M  |   N  |   E  |   I  |   O  | '/SFT|
   * |------+------+------+------+------+------|         |------+------+------+------+------+------|
   * |-/LCTR|Z/LGUI|X/LALT|   C  |   D  |   V  |         |   K  |   H  |   ,  |./LALT|/_RGUI|=/RCTR|
   * `------+------+------+------+------+------+---. ,---+------+------+------+------+------+------'
   *                          |Esc/AD|Tab/SH|Spc/Lo| |Bks/Up|Del/SH|   \  |
   *                          `--------------------' `--------------------'
   */
  [_DH] = LAYOUT (
    KC_LBRC,      KC_Q,      KC_W,      KC_F, KC_P,   AGT(KC_B),                  AGT(KC_J), KC_L,   KC_U,    KC_Y,        KC_SCLN,      KC_RBRC,      \
    LST(KC_GRV),  KC_A,      KC_R,      KC_S, KC_T,   KC_G,                       KC_M,      KC_N,   KC_E,    KC_I,        KC_O,         RST(KC_QUOT), \
    LCT(KC_MINS), LGT(KC_Z), TAT(KC_X), KC_C, KC_D,   KC_V,                       KC_K,      KC_H,   KC_COMM, TAT(KC_DOT), RGT(KC_SLSH), RCT(KC_EQL),  \
                                              LT_ESC, S_TAB,     LT_SPC, LT_BSPC, S_DEL,     KC_BSLS \
  ),
  /* Qwerty
   * ,-----------------------------------------.         ,-----------------------------------------.
   * | [    |   Q  |   W  |   E  |   R  |T/RALT|         |Y/RALT|   U  |   I  |   O  |   P  | ]    |
   * |------+------+------+------+------+------|         |------+------+------+------+------+------|
   * | `/SFT|   A  |   S  |   D  |   F  |   G  |         |   H  |   J  |   K  |   L  |   ;  | '/SFT|
   * |------+------+------+------+------+------|         |------+------+------+------+------+------|
   * |-/LCTR|Z/LGUI|X/LALT|   C  |   V  |   B  |         |   N  |   M  |   ,  |./LALT|/_RGUI|=/RCTR|
   * `------+------+------+------+------+------+---. ,---+------+------+------+------+------+------'
   *                          |Esc/AD|Tab/SH|Spc/Lo| |Bks/Up|Del/SH|   \  |
   *                          `--------------------' `--------------------'
   */
  [_QW] = LAYOUT (
    _______, _______, _______, KC_E,    KC_R,    AGT(KC_T),                   AGT(KC_Y), KC_U,   KC_I,    KC_O,    KC_P,    _______, \
    _______, _______, KC_S,    KC_D,    KC_F,    _______,                          KC_H, KC_J,   KC_K,    KC_L,    KC_SCLN, _______, \
    _______, _______, _______, _______, KC_V,    KC_B,                             KC_N, KC_M,   _______, _______, _______, _______, \
                                        _______, _______,   _______, _______,   _______, _______ \
  ),
  /* Dvorak
   * ,-----------------------------------------.         ,-----------------------------------------.
   * | [    |   '  |   ,  |   .  |   P  |Y/RALT|         |F/RALT|   G  |   C  |   R  |   L  | ]    |
   * |------+------+------+------+------+------|         |------+------+------+------+------+------|
   * | `/SFT|   A  |   O  |   E  |   U  |   I  |         |   D  |   H  |   T  |   N  |   S  | /    |
   * |------+------+------+------+------+------|         |------+------+------+------+------+------|
   * |-/LCTR|;/LGUI|Q/LALT|   J  |   K  |   X  |         |   B  |   M  |   W  |V/LALT|Z/RGUI|=/RCTR|
   * `------+------+------+------+------+------+---. ,---+------+------+------+------+------+------'
   *                          |Esc/AD|Tab/SH|Spc/Lo| |Bks/Up|Del/SH|   \  |
   *                          `--------------------' `--------------------'
   */
  [_DV] = LAYOUT (
    _______, KC_QUOT,      KC_COMM,   KC_DOT,  KC_P,    AGT(KC_Y),                   AGT(KC_F),    KC_G, KC_C, KC_R,      KC_L,      _______, \
    _______, KC_A,         KC_O,      KC_E,    KC_U,    KC_I,                             KC_D,    KC_H, KC_T, KC_N,      KC_S,      RST(KC_SLSH), \
    _______, LGT(KC_SCLN), TAT(KC_Q), KC_J,    KC_K,    KC_X,                             KC_B,    KC_M, KC_W, TAT(KC_V), RGT(KC_Z), _______, \
                                            _______, _______,      _______, _______,   _______, _______ \
  ),
  /* Lower
   * ,-----------------------------------------.         ,-----------------------------------------.
   * |Vol Up|  Esc | Copy | W_Up |  CUT | PASTE|         | PgUp |M_Btn1| M_Up |M_Btn2|M_Btn3| Next |
   * |------+------+------+------+------+------|         |-------------+------+------+------+------|
   * |Vol Do|  Tab | W_Le | W_Do | W_Ri |M_Btn3|         | Home | M_Le | M_Do | M_Ri | End  | Prev |
   * |------+------+------+------+------+------|         |-------------+------+------+------+------|
   * | Mute | Ctrl | Shift| Gui  |M_Btn1|M_Btn2|         | PgDN | Left | Down |  Up  | Rght | Play |
   * `------+------+------+------+------+------+---. ,---+------+------+------+------+------+------'
   *                          |      |      |      | | Enter|      |      |
   *                          `--------------------' `--------------------'
   */
  [_LO] = LAYOUT (
    KC_VOLU, KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,                     KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_MNXT, \
    KC_VOLD, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3,                   KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  KC_MPRV, \
    KC_MUTE, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, \
                                        _______, _______, _______,  KC_ENT, _______, _______ \
  ),
  /* Raise
   * ,-----------------------------------------.         ,-----------------------------------------.
   * |   |  |   !  |   @  |   #  |   $  |   %  |         |   ^  |   &  |   *  |   (  |   )  |   \  |
   * |-------------+------+------+------+------|         |------+------+------+------+------+------|
   * |   .  |   1  |   2  |   3  |   4  |   5  |         |   6  |   7  |   8  |   9  |   0  |   ,  |
   * |-------------+------+------+------+------|         |------+------+------+------+------+------|
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |         |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * `------+------+------+------+------+------+---. ,---+------+------+------+------+------+------'
   *                          |      |      |Enter | |      |      |      |
   *                          `--------------------' `--------------------'
   */
  [_RA] = LAYOUT (
    KC_PIPE, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_DOT,  KC_1,    KC_2,  KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_COMM, \
    KC_F11,  KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
                                      _______, _______, KC_ENT, _______, _______, _______ \
  ),
  /* Adjust
   * ,-----------------------------------------.         ,-----------------------------------------.
   * | Reset|CoMoDH|Qwerty|Dvorak|      |PrtScr|         | Minus|  P7  |  P8  |  P9  | Slash|NumLck|
   * |-------------+------+------+------+------|         |------+------+------+------+------+------|
   * | Wipe |RgbRMo|RgbHui|RgbSai|RgbVai|BrghUp|         |  P0  |  P4  |  P5  |  P6  | Dot  |CapLck|
   * |-------------+------+------+------+------|         |------+------+------+------+------+------|
   * |RbgTog|RgbMod|RbgHud|RgbSad|RgbVad|BrghDo|         | Plus |  P1  |  P2  |  P3  | Ast  |ScrLck|
   * `------+------+------+------+------+------+---. ,---+------+------+------+------+------+------'
   *                          |      |Random| Emoji| |BckSpc|  Del |PEnter|
   *                          `--------------------' `--------------------'
   */
  [_AD] = LAYOUT (
     M_WIPE,  MODDH,    QWERTY,  DVORAK,  _______, KC_PSCR,                   KC_PMNS, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_NLCK, \
     M_RGBRS, RGB_RMOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU,                   KC_P0,   KC_P4, KC_P5, KC_P6, KC_PDOT, KC_CAPS, \
     RGB_TOG, RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID,                   KC_PPLS, KC_P1, KC_P2, KC_P3, KC_PAST, KC_SLCK, \
                                          XXXXXXX, M_RAN64, EMOJI,  KC_BSPC, KC_DEL,  KC_PENT \
  ),

  // Emoji
  [_EM] = LAYOUT (
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   UC_TABL, UC_FLIP, UC_RAGE, UC_NOOO, UC_LENY, UC_SHR2, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   UC_SCRE, UC_DISA, UC_WALL, UC_SOB,  UC_WHAT, UC_HAPY, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   UC_SALU, UC_DANC, UC_SHRG, UC_DEAL, UC_CRY,  UC_STRG, \
                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_270;
  } else {
    return rotation;
  }
}

void add_keylog(uint16_t keycode) {
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode = keycode & 0xFF;
  }

  for (uint8_t i = 4; i > 0; --i) {
    keylog_str[i] = keylog_str[i - 1];
  }

  if (keycode < 60) {
    keylog_str[0] = code_to_name[keycode];
  }

  log_timer = timer_read();
}

void update_log(void) {
  if (timer_elapsed(log_timer) > 750) {
    add_keylog(0);
  }
}

void render_bootmagic_status(void) {
  if (keymap_config.swap_lalt_lgui) {
    oled_write_P(PSTR("<Mac>"), false);
  } else {
    oled_write_P(PSTR("<Lin>"), false);
  }
}

void render_default_layer_state(void) {
  oled_write_P(PSTR("Base:"), false);
  switch (biton32(default_layer_state)) {
    case _QW:
      oled_write_P(PSTR(" QRTY"), false);
      break;
    case _DH:
      oled_write_P(PSTR(" COLE"), false);
      break;
    case _DV:
      oled_write_P(PSTR(" DVRK"), false);
      break;
  }
}

void render_layer_state(void) {
  oled_write_P(PSTR("Layr:"), false);
  switch (biton32(layer_state)) {
    case 0:
      oled_write_P(PSTR(" DEF "), false);
      break;
    case _RA:
      oled_write_P(PSTR(" RAI "), false);
      break;
    case _LO:
      oled_write_P(PSTR(" LOW "), false);
      break;
    case _AD:
      oled_write_P(PSTR(" ADJ "), false);
      break;
    case _EM:
      oled_write_P(PSTR(" EMO "), false);
      break;
    default:
      oled_write_P(PSTR(" UNK "), false);
      break;
  }
}

void render_keylock_status(uint8_t led_usb_state) {
  oled_write_P(PSTR("Lock:"), false);
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("NUM "), led_usb_state & (1 << USB_LED_NUM_LOCK));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("CAPS"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("SCRL"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
  oled_write_P(PSTR("Mods:"), false);
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("GUI "), (modifiers & MOD_MASK_GUI));
  oled_write_P(PSTR(" "), false);
  oled_write_P(PSTR("ALT "), (modifiers & MOD_MASK_ALT));
}

void render_keylogger_status(void) {
  oled_write_P(PSTR("Log: "), false);
  oled_write(keylog_str, false);
}

void render_crkbd_logo(void) {
  oled_write_P(crkbd_logo, false);
}

void render_status_main(void) {
  render_bootmagic_status();
  render_default_layer_state();
  render_layer_state();
  render_keylock_status(host_keyboard_leds());
  render_mod_status(get_mods()|get_oneshot_mods());
  render_keylogger_status();
}

void render_status_secondary(void) {
  render_crkbd_logo();
  oled_scroll_left(); // Turns on scrolling
}

void oled_task_user(void) {
  update_log();
  if (is_master) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_status_secondary();
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {  add_keylog(keycode); }
  #endif
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
    case M_RGBRS:
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
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
