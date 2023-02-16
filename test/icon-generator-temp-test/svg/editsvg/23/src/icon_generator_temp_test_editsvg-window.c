/* icon_generator_temp_test_editsvg-window.c
 *
 * Copyright 2023 bazylevnik0
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

#include "icon_generator_temp_test_editsvg-config.h"
#include "icon_generator_temp_test_editsvg-window.h"

struct _IconGeneratorTempTestEditsvgWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkHeaderBar        *header_bar;
  GtkImage            *image;
};

G_DEFINE_TYPE (IconGeneratorTempTestEditsvgWindow, icon_generator_temp_test_editsvg_window, GTK_TYPE_APPLICATION_WINDOW)

static void
icon_generator_temp_test_editsvg_window_class_init (IconGeneratorTempTestEditsvgWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/org/example/App/icon_generator_temp_test_editsvg-window.ui");
  gtk_widget_class_bind_template_child (widget_class, IconGeneratorTempTestEditsvgWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, IconGeneratorTempTestEditsvgWindow, image);
}

static GtkImage *temp;
static void
show_function(){
  gtk_image_set_from_resource(temp,"/org/example/App/test.svg");
}
static void
change_function(){
  //read
  GInputStream *gistream = g_resources_open_stream("/org/example/App/test.svg", G_RESOURCE_LOOKUP_FLAGS_NONE , NULL);
  gchar *buffer;
  gssize red;
  red = g_input_stream_read (gistream, buffer, 10, NULL, NULL);
  buffer[9] = '\0';
  g_print("read: %s\n",buffer);
  //write
  gssize wrote;                       //it can be temporary folder with cleanup after
  GFile *temp_i = g_file_new_for_path ("/home/nik0/Projects/icon-generator-temp-test-editsvg/src/test_temp.svg");
  GFileOutputStream *gfostream = g_file_create (temp_i, G_FILE_CREATE_NONE, NULL, NULL);
  buffer[0] = '!';
  g_print("write: %s\n",buffer);
  wrote = g_output_stream_write (gfostream, buffer, 10, NULL, NULL);
  //read
  GFile *temp_o = g_file_new_for_path ("/home/nik0/Projects/icon-generator-temp-test-editsvg/src/test_temp.svg");
  GFileInputStream *gfistream = g_file_read (temp_o, NULL, NULL);
  red = g_input_stream_read (gfistream, buffer, 10, NULL, NULL);
  buffer[0]='<';
  g_print("read: %s\n",buffer);
  //write
  GFile *temp_i_2 = g_file_new_for_path ("/home/nik0/Projects/icon-generator-temp-test-editsvg/src/test_temp_2.svg");
  GFileOutputStream *gfostream_2 = g_file_create (temp_i_2, G_FILE_CREATE_NONE, NULL, NULL);
  buffer[9] = '\0';
  wrote = g_output_stream_write (gfostream_2, buffer, 10, NULL, NULL);
}

static void
icon_generator_temp_test_editsvg_window_init (IconGeneratorTempTestEditsvgWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  temp = self->image;
  show_function();
  change_function();
}
