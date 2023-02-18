/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define PLOOPY_DPI_OPTIONS { 800, 1200, 1600, 2400 }
#define PLOOPY_DPI_DEFAULT 1
#define PLOOPY_DRAGSCROLL_INVERT // This reverses the direction that the scroll is performed.
#define PLOOPY_DRAGSCROLL_MULTIPLIER 0.12 // Sets the DPI multiplier to use when drag scroll is enabled.
//#define PLOOPY_DRAGSCROLL_FIXED // Normally, when activating Drag Scroll, it uses a fraction of the current DPI. You can define this to use a specific, set DPI rather than a fraction of the current DPI.
//#define PLOOPY_DRAGSCROLL_DPI 100 // When the fixed DPI option is enabled, this sets the DPI to be used for Drag Scroll.
