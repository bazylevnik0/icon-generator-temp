/* icon_generator_temp_test_search-window.h
 *
 * Copyright 2023 nik0
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define ICON_GENERATOR_TEMP_TEST_SEARCH_TYPE_WINDOW (icon_generator_temp_test_search_window_get_type())

G_DECLARE_FINAL_TYPE (IconGeneratorTempTestSearchWindow, icon_generator_temp_test_search_window, ICON_GENERATOR_TEMP_TEST_SEARCH, WINDOW, GtkApplicationWindow)

G_END_DECLS
