#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _MODDH 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _MOVE 4
#define _ADJUST 16

enum custom_keycodes {
  MODDH = SAFE_RANGE,
  QWERTY,
};

// Shortcuts
#define ADJUST MO(_ADJUST)
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
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

// Thumbs
#define CTLESC CTL_T(KC_ESC)
#define LOWTAB LT(_LOWER, KC_TAB)
#define MOVESPC LT(_MOVE, KC_SPC)
#define SFTBSPC SFT_T(KC_BSPC)
#define RAIDEL LT(_RAISE, KC_DEL)
#define GUIQUO RGUI_T(KC_QUOT)

// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak Mod-DH
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  | B/AGR|           | J/AGR|   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | A/SFT|   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  | O/SFT|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Z/CTR| X/GUI| C/ALT|   D  |   V  |           |   K  |   H  | ,/ALT| ./GUI| /-CTR|
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.   ,-------,-------------.
 *                  |CTLESC|LOWTAB|       |   |       |RAIDEL|GUIQUO|
 *                  `-------------|MOVESPC|   |SFTBSPC|------+------.
 *                                |       |   |       |
 *                                `-------'   `-------'
 */
[_MODDH] = LAYOUT( \
  KC_Q,      KC_W,      KC_F,      KC_P,   AGT(KC_B),    AGT(KC_J), KC_L,   KC_U,         KC_Y,        KC_SCLN,      \
  LST(KC_A), KC_R,      KC_S,      KC_T,   KC_G,         KC_M,      KC_N,   KC_E,         KC_I,        RST(KC_O),    \
  LCT(KC_Z), LGT(KC_X), TAT(KC_C), KC_D,   KC_V,         KC_K,      KC_H,   TAT(KC_COMM), RGT(KC_DOT), RCT(KC_SLSH), \
                        CTLESC,    LOWTAB, MOVESPC,      SFTBSPC,   RAIDEL, GUIQUO                                   \
),

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  | T/AGR|           | Y/AGR|   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | A/SFT|   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  | ;/SFT|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Z/CTR| X/GUI| C/ALT|   V  |   B  |           |   N  |   M  | ,/ALT| ./GUI| /-CTR|
 * `----------------------------------'           `----------------------------------'
 *                  ,---------------------.   ,-------,-------------.
 *                  |CTLESC|LOWTAB|       |   |       |RAIDEL|GUIQUO|
 *                  `-------------|MOVESPC|   |SFTBSPC|------+------.
 *                                |       |   |       |
 *                                `-------'   `-------'
 */
[_QWERTY] = LAYOUT( \
  _______, _______, KC_E,    KC_R,    AGT(KC_T),          AGT(KC_Y), KC_U,    KC_I,    KC_O,    KC_P,         \
  _______, KC_S,    KC_D,    KC_F,    _______,            KC_H,      KC_J,    KC_K,    KC_L,    RST(KC_SCLN), \
  _______, _______, _______, KC_V,    KC_B,               KC_N,      KC_M,    _______, _______, _______,      \
                    _______, _______, _______,            _______,   _______, _______                         \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |   -  |   =  |   +  |   *  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |           |  F12 |   _  |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |ADJUST|      |    |      |      |      |
 *                  `-------------| ENTER|    |BCKSPC|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT( \
  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_MINS, KC_EQL,  KC_PLUS, KC_ASTR, \
  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,       KC_F12,  KC_UNDS, _______, _______, _______, \
                   _______, ADJUST,  KC_ENT,       KC_BSPC, _______, _______                    \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Caps | PLAY | PREV | NEXT | STOP |           |  `   |   '  |   "  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | PRSCR| MUTE | VOL- | VOL+ | MEDIA|           |   ~  |   \  |   |  |   {  |   }  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |ADJUST|      |
 *                  `-------------|      |    | ENTER|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_CAPS, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP,      KC_GRV,  KC_QUOT, KC_DQT,  KC_LCBR, KC_RCBR, \
  KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU, KC_MSEL,      KC_TILD, KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, \
                    _______, _______, _______,      KC_ENT,  ADJUST,  _______                    \
),

/* Movement
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  Esc | Copy | WH_U | Cut  | Paste|           |  M_1 |  M_U |  M_2 |  M_3 | PGUP |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | WH_L | WH_D | WH_R |  Ins |           |  M_L |  M_D |  M_R |  UP  | PGDN |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Ctrl | Shift| GUI  | M_1  |  Del |           | HOME |  END | LEFT | DOWN | RGTH |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |SPACE |      |
 *                  `-------------|      |    | ENTER|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_MOVE] = LAYOUT( \
  KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,        KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_PGUP, \
  KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_INS,       KC_MS_L, KC_MS_D, KC_MS_R, KC_UP,   KC_PGDN, \
  KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_DEL,       KC_HOME, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, \
                    _______, _______, _______,      KC_ENT,  KC_SPC,  _______                    \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |RGBHUI|RGBSAI|RGBVAI|           |M_ACL0|M_ACL1|M_ACL2|Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |RGBTOG|RGBMOD|RGBHUD|RGBSAD|RGBVAD|           |      |      |      |MODDH |QWERTY|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |RESET |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
  KC_F11,  KC_F12,  RGB_HUI, RGB_SAI, RGB_VAI,      KC_ACL0, KC_ACL1, KC_ACL2, TSKMGR,  CALTDEL, \
  RGB_TOG, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,      _______, _______, _______, MODDH,   QWERTY,  \
                    RESET,   _______, _______,      _______, _______, _______                    \
)
};

void matrix_init_user(void) { // Runs boot tasks for keyboard
    rgblight_enable();
    //rgblight_sethsv(340, 255, 255); // Red Magenta
    rgblight_sethsv(276,255,170); // Purple
    rgblight_mode(3);
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MODDH:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_MODDH);
        SEND_STRING("\nLayout changed to COLEMAK MOD-DH.\n");
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
        SEND_STRING("\nLayout changed to QWERTY.\n");
      }
      return false;
      break;
  }
  return true;
};
