two elements:<br>
search input and area with previews<br>

in widget gallery<br>
about search<br>
exist https://docs.gtk.org/gtk4/class.SearchEntry.html<br>
also it is possible attach to search entry to https://docs.gtk.org/gtk4/class.SearchBar.html<br>

1 - added search with handling changing input<br>

about prewievs:<br>

exist this https://docs.gtk.org/gtk4/class.IconView.html<br>
but recomended https://docs.gtk.org/gtk4/class.GridView.html<br>
*it's works with https://docs.gtk.org/gtk4/section-list-widget.html<br>
gtk_grid_view_new creating with GtkSelectionModel and GtkListItemFactory<br>
grid_view = gtk_grid_view_new (NULL, gtk_builder_list_item_factory_new_from_resource (NULL,"/icon/generator/temp/test/search/elements.ui"));<br>
it is using .ui maybe it's something like window.ui but list of templates - i am not sure<br>


exist this https://docs.gtk.org/gtk3/iface.FileChooser.html<br>
*in previous test(edit svg) i wrote about using gresource but if use FileChooser possible avoid it and use absolute paths and all system for searching and distribute library as a folder<br>
and we not need the separately search panel(2)<br>
**also as a default - file chooser not showing previews - sure in the prototype it is not required but it is an important feature<br>
!FileChooserWidget's inhereted FileChooser signals not works now and as i understand this way is deprecated soon - but maybe(as a last resort) it is possible to use source https://gitlab.gnome.org/GNOME/gtk/-/blob/main/gtk/gtkfilechooserwidget.c and default function of widget for finding path for selected file from list implementation<br>
