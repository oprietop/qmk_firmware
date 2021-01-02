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
    case MODDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DH);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DV);
      }
      return false;
    case M_WIPE: // Wipe the eeprom and reset the board
      if (record->event.pressed) {
        eeconfig_init();
        reset_keyboard();
      }
      return false;
    case M_RGBRS:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      return false;
    case M_RAN64:
      if (record->event.pressed) {
        tap_random_base64();
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
      case UC_WHAT: // WHATщ(ﾟДﾟщ)
        if (record->event.pressed) {
          send_unicode_hex_string("0057 0048 0041 0054 0449 0028 FF9F 0414 FF9F 0449 0029");
        }
        return false;
      case UC_CRY: // ಥ_ಥ
        if (record->event.pressed) {
          send_unicode_hex_string("0CA5 005F 0CA5");
        }
        return false;
      case UC_SHR2: // ¯\(ºдಠ)/¯
        if (record->event.pressed) {
          send_unicode_hex_string("00AF 005C 0028 00BA 0434 0CA0 0029 002F 00AF");
        }
        return false;
      case UC_HAPY: // ✌.|•͡˘‿•͡˘|.✌
        if (record->event.pressed) {
          send_unicode_hex_string("270C 002E 007C 2022 0361 02D8 203F 2022 0361 02D8 007C 002E 270C");
        }
        return false;
      case UC_STRG: // ᕙ(⇀‸↼‶)ᕗ
        if (record->event.pressed) {
          send_unicode_hex_string("1559 0028 21C0 2038 21BC 2036 0029 1557 000A");
        }
        return false;
      case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
        if (record->event.pressed) {
          send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
        }
        return false;
      case UC_TABL: // ┬─┬ノ( º _ ºノ)
        if (record->event.pressed) {
          send_unicode_hex_string("252C 2500 252C 30CE 0028 0020 00BA 0020 005F 0020 00BA 30CE 0029");
        }
        return false;
      case UC_SHRG: // ¯\_(ツ)_/¯
        if (record->event.pressed) {
          send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        }
        return false;
      case UC_DISA: // ಠ_ಠ
        if (record->event.pressed) {
          send_unicode_hex_string("0CA0 005F 0CA0");
        }
        return false;
      case UC_DANC: // (〜￣△￣)〜
        if (record->event.pressed) {
          send_unicode_hex_string("0028 301C FFE3 25B3 FFE3 0029 301C");
        }
        return false;
      case UC_SCRE: // ヽ(ﾟДﾟ)ﾉ
        if (record->event.pressed) {
          send_unicode_hex_string("30FD 0028 FF9F 0414 FF9F 0029 FF89");
        }
        return false;
      case UC_WALL: // ┬┴┬┴┤(･_├┬┴┬┴
        if (record->event.pressed) {
          send_unicode_hex_string("252C 2534 252C 2534 2524 0028 FF65 005F 251C 252C 2534 252C 2534");
        }
        return false;
      case UC_SOB: // (ಢ⊱ಢ ｡)
        if (record->event.pressed) {
          send_unicode_hex_string("0028 0CA2 22B1 0CA2 0020 FF61 0029");
        }
        return false;
      case UC_DEAL: // ( ∙_∙) ( ∙_∙)>⌐■-■ (⌐■_■)
        if (record->event.pressed) {
          send_unicode_hex_string("0028 0020 2219 005F 2219 0029 0020 0028 0020 2219 005F 2219 0029 003E 2310 25A0 002D 25A0 0020 0028 2310 25A0 005F 25A0 0029");
        }
        return false;
      case UC_RAGE: // （╬ಠ益ಠ)
        if (record->event.pressed) {
          send_unicode_hex_string("FF08 256C 0CA0 76CA 0CA0 0029");
        }
        return false;
      case UC_NOOO: // (」ﾟﾛﾟ)｣NOOOooooo━
        if (record->event.pressed) {
          send_unicode_hex_string("0028 300D FF9F FF9B FF9F 0029 FF63 004E 004F 004F 004F 006F 006F 006F 006F 006F 2501");
        }
        return false;
      case UC_SALU: // (￣^￣)ゞ
        if (record->event.pressed) {
          send_unicode_hex_string("0028 FFE3 005E FFE3 0029 309E");
        }
        return false;
    #endif
  }
  return true;
};
