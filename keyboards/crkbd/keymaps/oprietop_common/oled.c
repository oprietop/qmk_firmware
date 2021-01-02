static char     keylog_str[6] = {};
static uint16_t log_timer = 0;
static const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

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
