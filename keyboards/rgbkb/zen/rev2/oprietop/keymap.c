// This is the Zen keyboard layout by oprietop

#include QMK_KEYBOARD_H

// Allow printing version info
#include "version.h"

extern keymap_config_t keymap_config;

// Timer for M_BSPC
static uint16_t timer;

enum layers {
  _MODDH,
  _QWERTY,
  _LOWER,
};

enum keycodes {
  // Layers
  MODDH = SAFE_RANGE,
  QWERTY,
  // Macros
  M_BSPC,
  M_VER,
  M_PULL,
  M_PUSH,
  M_LS,
  M_INCL,
};

// Cut/Paste shortcuts
#define COPY LCTL(KC_INS)
#define CUT LSFT(KC_DEL)
#define PASTE RSFT(KC_INS)

// Mod-Taps
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
#define LST(X) LSFT_T(X)
#define RST(X) RSFT_T(X)
#define AGT(X) RALT_T(X)

// Modifiers
#define S_SPC LSFT_T(KC_SPC)
#define LT_TAB LT(_LOWER, KC_TAB)
#define LT_DEL LT(_LOWER, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MODDH] = LAYOUT( \
    KC_ESC,  KC_1,      KC_2,    KC_3,   KC_4,   KC_5,                     KC_6,      KC_7,    KC_8,    KC_9,   KC_0,      KC_BSPC, \
    KC_LBRC, KC_Q,      KC_W,    KC_F,   KC_P,   AGT(KC_B),                AGT(KC_J), KC_L,    KC_U,    KC_Y,   KC_SCLN,   KC_RBRC, \
    KC_GRV,  LST(KC_A), KC_R,    KC_S,   KC_T,   KC_G,                     KC_M,      KC_N,    KC_E,    KC_I,   RST(KC_O), KC_QUOT, \
    KC_MINS, KC_Z,      KC_X,    KC_C,   KC_D,   KC_V,                     KC_K,      KC_H,    KC_COMM, KC_DOT, KC_SLSH,   KC_EQL,  \
    KC_LCTL, KC_LGUI,   KC_LALT, KC_INS, KC_ESC, S_SPC,    LT_TAB, LT_DEL, M_BSPC,    KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,   KC_BSLS  \
  ),

  [_QWERTY] = LAYOUT( \
    _______, _______,   _______, _______, _______, _______,                     _______,   _______, _______, _______, _______,      _______, \
    _______, KC_Q,      KC_W,    KC_E,    KC_R,    AGT(KC_T),                   AGT(KC_Y), KC_U,    KC_I,    KC_O,    KC_P,         _______, \
    _______, LST(KC_A), KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,      KC_J,    KC_K,    KC_L,    RST(KC_SCLN), _______, \
    _______, KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      _______, \
    _______, _______,   _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______,      _______  \
  ),

  [_LOWER] = LAYOUT( \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
    KC_PSCR, KC_ESC,  CUT,     KC_WH_U, PASTE,   KC_LBRC,                  KC_RBRC, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, M_PULL, \
    RGB_MOD, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_GRV,                   KC_QUOT, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP, M_PUSH, \
    RGB_TOG, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_MINS,                  KC_EQL,  KC_HOME, KC_END,  KC_UP,   KC_PGDN, M_LS,   \
    RESET,   MODDH,   QWERTY,  M_VER,   KC_CAPS, KC_ENT,  KC_SPC, KC_BSPC, KC_ENT,  KC_BSLS, KC_LEFT, KC_DOWN, KC_RGHT, M_INCL  \
  ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Our funky backspace key!
    case M_BSPC:
      if (record->event.pressed) {
        timer = timer_read();
        // Register Right Shift if we are not shifted
        if (! (get_mods() & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)))) {
          register_code(KC_RSFT);
        }
      } else {
        // Unregister Right Shift if registered
        if (get_mods() & MOD_BIT(KC_RSHIFT)) {
          unregister_code(KC_RSFT);
        }
        // Check if we are into the TAPPING_TERM threshold
        if (timer_elapsed(timer) < TAPPING_TERM) {
          // Tap Enter if left shifted, Backspace if not
          if (get_mods() & MOD_BIT(KC_LSHIFT)) {
            // Avoid sending Left Shift + Enter
            unregister_code(KC_LSFT);
            tap_code(KC_ENT);
            register_code(KC_LSFT);
          } else {
            tap_code(KC_BSPC);
          }
        }
      }
      return false;
    // Layers
    case MODDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MODDH);
        SEND_STRING("\nLayout changed to COLEMAK MOD-DH.\n");
      }
      return false;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
        SEND_STRING("\nLayout changed to QWERTY.\n");
      }
      return false;
    // Macros
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
        SEND_STRING("ls -la"SS_TAP(X_ENTER));
      }
      return false;
    case M_VER:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
      }
      return false;
  }
  return true;
}
