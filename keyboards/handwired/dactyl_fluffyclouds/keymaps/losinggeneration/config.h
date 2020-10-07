/*
Copyright 2017 Danny Nguyen <danny@hexwire.com>
Copyright 2018 Harley Laue <losinggeneration@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
long with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H

#define MANUFACTURER    losinggeneration
#define USE_DACTYL_LAYOUT
#define LAYOUT LAYOUT_6x6

/* Use I2C or Serial, not both */
#define USE_SERIAL
/* #define USE_I2C */

/* Select hand configuration */
#define MASTER_LEFT
/* #define _MASTER_RIGHT */
/* #define EE_HANDS */

#define TAPPING_TERM 250

#define MOUSEKEY_INTERVAL          10
#define MOUSEKEY_MAX_SPEED         30
#define MOUSEKEY_TIME_TO_MAX       200

#define NO_MUSIC_MODE
#define AUDIO_CLICKY

#define AUDIO_CLICKY_FREQ_DEFAULT 261.63f
//#define AUDIO_CLICKY_FREQ_DEFAULT 1500.0f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.025f
//#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.0f

#endif
