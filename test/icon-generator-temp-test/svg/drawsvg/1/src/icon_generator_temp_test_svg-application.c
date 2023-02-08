/* icon_generator_temp_test_svg-application.c
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

#include "icon_generator_temp_test_svg-application.h"
#include "icon_generator_temp_test_svg-window.h"

struct _IconGeneratorTempTestSvgApplication
{
  GtkApplication parent_instance;
};

G_DEFINE_TYPE (IconGeneratorTempTestSvgApplication, icon_generator_temp_test_svg_application, ADW_TYPE_APPLICATION)

IconGeneratorTempTestSvgApplication *
icon_generator_temp_test_svg_application_new (gchar *application_id,
                                              GApplicationFlags  flags)
{
  return g_object_new (ICON_GENERATOR_TEMP_TEST_SVG_TYPE_APPLICATION,
                       "application-id", application_id,
                       "flags", flags,
                       NULL);
}

static void
icon_generator_temp_test_svg_application_finalize (GObject *object)
{
  IconGeneratorTempTestSvgApplication *self = (IconGeneratorTempTestSvgApplication *)object;

  G_OBJECT_CLASS (icon_generator_temp_test_svg_application_parent_class)->finalize (object);
}

static void
icon_generator_temp_test_svg_application_activate (GApplication *app)
{
  GtkWindow *window;

  /* It's good practice to check your parameters at the beginning of the
   * function. It helps catch errors early and in development instead of
   * by your users.
   */
  g_assert (GTK_IS_APPLICATION (app));

  /* Get the current window or create one if necessary. */
  window = gtk_application_get_active_window (GTK_APPLICATION (app));
  if (window == NULL)
    window = g_object_new (ICON_GENERATOR_TEMP_TEST_SVG_TYPE_WINDOW,
                           "application", app,
                           NULL);
  
  GtkWidget *image = gtk_picture_new_for_filename ("test.png");
  //first method
  gtk_window_set_child ( window, image );
  gtk_widget_set_visible (image, TRUE);
  //second method
  //gtk_widget_set_parent( image , GTK_WIDGET(window));
  //gtk_widget_set_child_visible(GTK_WIDGET(window), TRUE);

  /* Ask the window manager/compositor to present the window. */
  gtk_window_present (window);
}


static void
icon_generator_temp_test_svg_application_class_init (IconGeneratorTempTestSvgApplicationClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

  object_class->finalize = icon_generator_temp_test_svg_application_finalize;

  /*
   * We connect to the activate callback to create a window when the application
   * has been launched. Additionally, this callback notifies us when the user
   * tries to launch a "second instance" of the application. When they try
   * to do that, we'll just present any existing window.
   */
  app_class->activate = icon_generator_temp_test_svg_application_activate;
}

static void
icon_generator_temp_test_svg_application_show_about (GSimpleAction *action,
                                                     GVariant      *parameter,
                                                     gpointer       user_data)
{
  IconGeneratorTempTestSvgApplication *self = ICON_GENERATOR_TEMP_TEST_SVG_APPLICATION (user_data);
  GtkWindow *window = NULL;
  const gchar *authors[] = {"nik0", NULL};

  g_return_if_fail (ICON_GENERATOR_TEMP_TEST_SVG_IS_APPLICATION (self));

  window = gtk_application_get_active_window (GTK_APPLICATION (self));

  gtk_show_about_dialog (window,
                         "program-name", "icon-generator-temp-test-svg",
                         "authors", authors,
                         "version", "0.1.0",
                         NULL);
}


static void
icon_generator_temp_test_svg_application_init (IconGeneratorTempTestSvgApplication *self)
{
  g_autoptr (GSimpleAction) quit_action = g_simple_action_new ("quit", NULL);
  g_signal_connect_swapped (quit_action, "activate", G_CALLBACK (g_application_quit), self);
  g_action_map_add_action (G_ACTION_MAP (self), G_ACTION (quit_action));

  g_autoptr (GSimpleAction) about_action = g_simple_action_new ("about", NULL);
  g_signal_connect (about_action, "activate", G_CALLBACK (icon_generator_temp_test_svg_application_show_about), self);
  g_action_map_add_action (G_ACTION_MAP (self), G_ACTION (about_action));

  gtk_application_set_accels_for_action (GTK_APPLICATION (self),
                                         "app.quit",
                                         (const char *[]) {
                                           "<primary>q",
                                           NULL,
                                         });
}
