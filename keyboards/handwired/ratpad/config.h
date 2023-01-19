 /* Copyright 2023 Harley Laue <losinggeneration@gmail.com>
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 7

/* pin-out */
#define MATRIX_ROW_PINS { GP4 , GP5 , GP6 , GP7 , GP8 , GP9 }
#define MATRIX_COL_PINS { GP28, GP27, GP26, GP22, GP20, GP23, GP21 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
