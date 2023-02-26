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
  
  //build path
  const gchar *username = g_get_user_name();
  gchar *path_home = "home";
                        //must be localized
  gchar *path_pictures = "Pictures";
  gchar *path_symbol = "/";     // /home/username/Pictures/
  gchar *path_library = g_strconcat(path_symbol,path_home,path_symbol,username,path_symbol,path_pictures,path_symbol, NULL);
  
  //build dir
  GDir *dir;
  dir = g_dir_open(path_library,0,NULL);
  //read dir
  const gchar *filename;
  GRegex *regex;
  GMatchInfo *match_info;
  regex = g_regex_new ("svg", G_REGEX_DEFAULT, G_REGEX_MATCH_DEFAULT, NULL);
               //maybe possible use dynamic string of chars i mean store paths not like a array but as a long string
  char *elements[100];
  gint  elements_last_index = 0;
  while ((filename = g_dir_read_name(dir)))
  {
   //check type of file 
   g_regex_match (regex, filename, 0, &match_info);
   if(g_match_info_matches (match_info))
   {
     //store in elements
     elements[elements_last_index] = g_strconcat(path_library,filename,NULL);    
     elements_last_index++;
   }  
  }  
  
  //show in grid_view
  GtkWidget *elements_widgets[100];
  //place 0 element
  gtk_grid_insert_row (self->grid_view,1);
  elements_widgets[0] = gtk_image_new_from_file ( elements[0] );
  gtk_grid_attach ( self->grid_view,elements_widgets[0],0,1,300,300);
  //place others
  for(int i = 1; i < elements_last_index; i++)
  {
      elements_widgets[i] = gtk_image_new_from_file ( elements[i] );
      gtk_grid_attach_next_to (self->grid_view,elements_widgets[i],elements_widgets[i-1],GTK_POS_RIGHT,300,300);
      gtk_widget_set_visible (elements_widgets[i], TRUE);
  }
}
