#include QMK_KEYBOARD_H

#include "defines.h"

#ifdef OLED_DRIVER_ENABLE
#   include "oled.c"
#endif

#include "functions.c"

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
   *                          |      |      |      | | Enter| Ins  |      |
   *                          `--------------------' `--------------------'
   */
  [_LO] = LAYOUT (
    KC_VOLU, KC_ESC,  COPY,    KC_WH_U, CUT,     PASTE,                     KC_PGUP, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_MNXT, \
    KC_VOLD, KC_TAB,  KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3,                   KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_END,  KC_MPRV, \
    KC_MUTE, KC_LCTL, KC_LSFT, KC_LGUI, KC_BTN1, KC_BTN2,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, \
                                        _______, _______, _______,  KC_ENT, KC_INS,  _______ \
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
