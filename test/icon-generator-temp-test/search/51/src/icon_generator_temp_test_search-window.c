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
  GtkSearchEntry      *search_entry;
  GtkGrid             *grid_view;
};

static void
search_text_changed (GtkEntry *entry)
{
  g_print("%s\n","changed");
}

G_DEFINE_TYPE (IconGeneratorTempTestSearchWindow, icon_generator_temp_test_search_window, GTK_TYPE_APPLICATION_WINDOW)

static void
icon_generator_temp_test_search_window_class_init (IconGeneratorTempTestSearchWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/icon/generator/temp/test/search/icon_generator_temp_test_search-window.ui");
  gtk_widget_class_bind_template_child    (widget_class, IconGeneratorTempTestSearchWindow, search_entry);
  gtk_widget_class_bind_template_callback (widget_class, search_text_changed);
  gtk_widget_class_bind_template_child    (widget_class, IconGeneratorTempTestSearchWindow, grid_view);
}

static void
icon_generator_temp_test_search_window_init (IconGeneratorTempTestSearchWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  //create image element
  GtkWidget* image = gtk_image_new_from_resource ( "/icon/generator/temp/test/search/test.svg" );
  //add new row in grid and add image to grid
  gtk_grid_insert_row (self->grid_view,1);
  gtk_grid_attach ( self->grid_view,image,0,1,300,300);
  gtk_widget_set_visible (image, TRUE);
  //repeat
  gtk_grid_insert_column (self->grid_view,1);
  gtk_grid_insert_column (self->grid_view,2);
  GtkWidget* image1 = gtk_image_new_from_resource ( "/icon/generator/temp/test/search/test1.svg" );
  GtkWidget* image2 = gtk_image_new_from_resource ( "/icon/generator/temp/test/search/test2.svg" );
  gtk_grid_attach_next_to (self->grid_view,image1,image,GTK_POS_RIGHT,300,300);
  gtk_grid_attach_next_to (self->grid_view,image2,image1,GTK_POS_RIGHT,300,300);
  gtk_widget_set_visible (image1, TRUE);
  gtk_widget_set_visible (image2, TRUE);
}
