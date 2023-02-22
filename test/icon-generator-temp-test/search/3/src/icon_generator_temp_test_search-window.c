/* icon_generator_temp_test_search-window.c
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

#include "icon_generator_temp_test_search-config.h"
#include "icon_generator_temp_test_search-window.h"

struct _IconGeneratorTempTestSearchWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkGrid             *grid;
  GtkSearchEntry      *search_entry;
};

G_DEFINE_TYPE (IconGeneratorTempTestSearchWindow, icon_generator_temp_test_search_window, GTK_TYPE_APPLICATION_WINDOW)

static void
search_text_changed (GtkEntry *entry)
{
  g_print("%s\n","changed");
}

static void
icon_generator_temp_test_search_window_class_init (IconGeneratorTempTestSearchWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/icon/generator/temp/test/search/icon_generator_temp_test_search-window.ui");
  gtk_widget_class_bind_template_child    (widget_class, IconGeneratorTempTestSearchWindow, grid);
  gtk_widget_class_bind_template_child    (widget_class, IconGeneratorTempTestSearchWindow, search_entry);
  gtk_widget_class_bind_template_callback (widget_class, search_text_changed);
}

GtkWidget* grid_view;
static void
icon_generator_temp_test_search_window_init (IconGeneratorTempTestSearchWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  
  //grid_view = gtk_grid_view_new (model, factory);
  GtkListItemFactory* factory = gtk_builder_list_item_factory_new_from_resource (NULL,"/icon/generator/temp/test/search/element.ui");
  grid_view = gtk_grid_view_new (NULL, factory);
  gtk_grid_insert_row (self->grid,1);
  gtk_grid_attach (self->grid,grid_view,0,1,300,300);
  gtk_widget_set_visible(GTK_WIDGET(grid_view),TRUE);
}
