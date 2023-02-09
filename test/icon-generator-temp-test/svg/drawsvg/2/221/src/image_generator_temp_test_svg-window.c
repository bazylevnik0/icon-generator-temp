/* image_generator_temp_test_svg-window.c
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

#include "image_generator_temp_test_svg-config.h"
#include "image_generator_temp_test_svg-window.h"

struct _ImageGeneratorTempTestSvgWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkGrid             *grid;
  GtkHeaderBar        *header_bar;
  GtkLabel            *label;
  GtkImage            *image;
  GtkButton           *button;
};


G_DEFINE_TYPE (ImageGeneratorTempTestSvgWindow, image_generator_temp_test_svg_window, GTK_TYPE_APPLICATION_WINDOW)

static void
image_generator_temp_test_svg_window_class_init (ImageGeneratorTempTestSvgWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/image/generator/temp/test/svg/image_generator_temp_test_svg-window.ui");
  gtk_widget_class_bind_template_child (widget_class, ImageGeneratorTempTestSvgWindow, grid);
  gtk_widget_class_bind_template_child (widget_class, ImageGeneratorTempTestSvgWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, ImageGeneratorTempTestSvgWindow, label);
  gtk_widget_class_bind_template_child (widget_class, ImageGeneratorTempTestSvgWindow, image);
  gtk_widget_class_bind_template_child (widget_class, ImageGeneratorTempTestSvgWindow, button);
}
static GtkImage *temp;
static void
show_function(GtkImage *self){
  gtk_image_set_from_resource (self,"/image/generator/temp/test/svg/test1.svg");
}

static void
reshow_function(GtkImage *self){
  //gtk_image_set_from_file (GTK_IMAGE(self), "/home/nik0/Projects/221/src/test2.svg");
  gtk_image_set_from_file (temp, "/home/nik0/Projects/221/src/test2.svg");
}

static void
image_generator_temp_test_svg_window_init (ImageGeneratorTempTestSvgWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  show_function(self->image);
  temp = self->image;
  g_signal_connect (GTK_BUTTON(self->button), "clicked", G_CALLBACK (reshow_function), NULL);
}
