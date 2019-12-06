/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define CONFIG_USER_H

/* Mouse Settings */
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_MAX_SPEED 2
#define MOUSEKEY_WHEEL_TIME_TO_MAX 6

/* RGB LED */
#define RGBLIGHT_ANIMATIONS

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
//#undef TAPPING_TERM
//#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
//#undef PERMISSIVE_HOLD
//#define TAPPING_FORCE_HOLD
//#define RETRO_TAPPING

// Disable the command automation
#undef IS_COMMAND

// Got the leds soldered the old way
// https://github.com/omkbd/ErgoDash/blob/master/Doc/build-en.md#12-firmware
#undef RGBLIGHT_SPLIT
#undef RGBLED_SPLIT
