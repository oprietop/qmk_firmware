/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

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

/* Mouse Settings */
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

/* RGB LED */
#define RGB_DI_PIN D3
#define RGBLED_NUM 18 // Number of LEDs in he board
#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 1

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
//#undef PERMISSIVE_HOLD
//#define TAPPING_FORCE_HOLD
//#define RETRO_TAPPING

// Disable the command automation
#undef IS_COMMAND
