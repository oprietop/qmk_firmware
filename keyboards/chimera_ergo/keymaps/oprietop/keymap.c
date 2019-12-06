#include "chimera_ergo.h"

// Allow printing version info
#include "version.h"

// Layers
#define _DH 0
#define _QW 1
#define _DV 2
#define _LO 3
#define _RA 4
// Aliases
#define KC_     KC_TRNS
#define KC_XXXX KC_NO
#define KC_RST  RESET
// Shift when held, Backspace  when tapped
#define KC_RSBS RSFT_T(KC_BSPC)
// Lower when held, Space when tapped
#define KC_LOSP LT(_LO, KC_SPC)
// RAlt when held, Tab when tapped
#define KC_RATA RALT_T(KC_TAB)
// Raise when held, Delete when tapped
#define KC_RADE LT(_RA, KC_DEL)
// Cut/Paste shortcuts
#define KC_CPY LCTL(KC_INS)
#define KC_PST RSFT(KC_INS)
#define KC_CUT LSFT(KC_DEL)

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
// Left
#define KC_GUES LGT(KC_ESC)
#define KC_TALB TAT(KC_LBRC)
#define KC_LSGR LST(KC_GRV)
#define KC_CTMI LCT(KC_MINS)
#define KC_GUIZ LGT(KC_Z)
#define KC_TATX TAT(KC_X)
#define KC_GSCL LGT(KC_SCLN)
#define KC_TATQ TAT(KC_Q)
// Right
#define KC_GUBS RGT(KC_BSLS)
#define KC_TARB TAT(KC_RBRC)
#define KC_RSQU RST(KC_QUOT)
#define KC_CTEQ RCT(KC_EQL)
#define KC_GUSL RGT(KC_SLSH)
#define KC_TADO TAT(KC_DOT)
#define KC_RGUZ RGT(KC_Z)
#define KC_TATV TAT(KC_V)

enum custom_keycodes {
  KC_CODH  = SAFE_RANGE,
  KC_QWER,
  KC_DVOR,
  KC_VER,
  KC_PULL,
  KC_PUSH,
  KC_LS,
  KC_INCL
};

// Layouts
// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes_basic.md
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DH] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GUES, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,GUBS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TALB, Q  , W  , F  , P  , B  ,                J  , L  , U  , Y  ,SCLN,TARB,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSGR, A  , R  , S  , T  , G  ,                M  , N  , E  , I  , O  ,RSQU,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CTMI,GUIZ,TATX, C  , D  , V  ,                K  , H  ,COMM,TADO,GUSL,CTEQ,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                         RATA,LOSP,               RSBS,RADE
  //                    `----+----'              `----+----'
  ),
  [_QW] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    , E  , R  , T  ,                Y  , U  , I  , O  , P  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    , S  , D  , F  ,    ,                H  , J  , K  , L  ,SCLN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    , C  , V  , B  ,                N  , M  ,    ,    ,    ,    ,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                             ,    ,                   ,
  //                    `----+----'              `----+----'
  ),
  [_DV] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,GSCL,TATQ, J  , K  , X  ,                B  ,    , W  ,TATV,RGUZ,    ,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                             ,    ,                   ,
  //                    `----+----'              `----+----'
  ),
  [_LO] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,F11 ,F12 ,WH_U,PST ,CUT ,               PGUP,BTN1,MS_U,BTN2,BTN3,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,TAB ,WH_L,WH_D,WH_R,INS ,               HOME,MS_L,MS_D,MS_R,END ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LCTL,LSFT,LGUI,BTN1,DEL ,               PGDN,LEFT,DOWN, UP ,RGHT,    ,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                             ,    ,               ENT ,LALT
  //                    `----+----'              `----+----'
  ),
  [_RA] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     RST , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     VER ,F11 ,F12 ,MPRV,MNXT,VOLU,               TILD,UNDS,PLUS,LCBR,RCBR,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPS,MPRV,MNXT,MSTP,MPLY,VOLD,               GRV ,MINS,EQL ,LBRC,RBRC,CAPS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     QWER,CODH,DVOR,PULL,PUSH, LS ,               BSLS,PIPE,    ,    ,    ,    ,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                             ,ENT ,               ENT ,
  //                    `----+----'              `----+----'
  )
};

// Macros
// https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case KC_QWER:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_QW);
        }
        return false;
        break;
      case KC_CODH:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_DH);
        }
        return false;
        break;
      case KC_DVOR:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_DV);
        }
        return false;
        break;
      case KC_INCL:
        SEND_STRING("#include <>"SS_TAP(X_LEFT));
        return false;
        break;
      case KC_PULL:
        SEND_STRING("git pull"SS_TAP(X_ENTER));
        return false;
        break;
      case KC_PUSH:
        SEND_STRING("git push"SS_TAP(X_ENTER));
        return false;
        break;
      case KC_LS:
        SEND_STRING("ls -la"SS_TAP(X_ENTER));
        return false;
        break;
      case KC_VER:
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
        return false;
        break;
    }
  }
  return true;
};

// Change the receiver led
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  switch (layer) {
    case _DH:
      set_led_green;
      break;
    case _QW:
      set_led_green;
      break;
    case _LO:
      set_led_blue;
      break;
    case _RA:
      set_led_red;
      break;
  }
};
