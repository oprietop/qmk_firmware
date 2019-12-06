#pragma once

#define CONFIG_USER_H

/* RGB LED */
#define RGB_DI_PIN D3
#undef RGBLED_NUM
#define RGBLED_NUM 10   // Number of LEDs in the board
#define RGBLIGHT_ANIMATIONS

/* Mouse Settings */
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_MAX_SPEED 2
#define MOUSEKEY_WHEEL_TIME_TO_MAX 6

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#   undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#   undef LOCKING_RESYNC_ENABLE
#endif

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
//#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
//#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM 175
