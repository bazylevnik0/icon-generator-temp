two elements:<br>
search input and area with previews<br>

<b>about search:</b><br>
exist https://docs.gtk.org/gtk4/class.SearchEntry.html<br>
also it is possible attach to search entry to https://docs.gtk.org/gtk4/class.SearchBar.html<br>
1 - added search with handling changing input<br>

<b>about prewievs:</b><br>
a)exist this https://docs.gtk.org/gtk3/iface.FileChooser.html deprecated soon<br>
*in previous test(edit svg) i wrote about using gresource but if use FileChooser possible avoid it and use absolute paths and all system for searching and distribute library as a folder<br>
it is very easy with https://docs.gtk.org/gtk4/class.FileChooserWidget.html deprecated soon<br>
and we not need the separately search panel(2)<br>
**also as a default - file chooser widget not showing previews - sure in the prototype it is not required but it is an important feature<br>
!FileChooserWidget's inhereted FileChooser signals not works now and this way is deprecated soon - but maybe(as a last resort) it is possible to use source https://gitlab.gnome.org/GNOME/gtk/-/blob/main/gtk/gtkfilechooserwidget.c and default function of widget for finding path for selected file from list implementation<br>

b)exist this https://docs.gtk.org/gtk4/class.IconView.html deprecated soon<br>
but recomended https://docs.gtk.org/gtk4/class.GridView.html<br>
grid view creating with:<br>
grid_view = gtk_grid_view_new(GtkSelectionModel* model,GtkListItemFactory* factory)<br>
*possible use source for factory it is detailed here https://docs.gtk.org/gtk4/ctor.GridView.new.html<br>

https://docs.gtk.org/gtk4/iface.SelectionModel.html<br>
not sure but as i understand this is just type of selection not about content and for this case possible use https://docs.gtk.org/gtk4/class.SingleSelection.html<br>

https://docs.gtk.org/gtk4/class.ListItemFactory.html<br>
as i understand - factory is something like list of Gobjects with defined type<br>
"GtkListItemFactory creates widgets for the items taken from a GListModel."
possible create GtkListItemFactory with .ui https://docs.gtk.org/gtk4/class.BuilderListItemFactory.html<br>
*not sure about need or not need but signals https://docs.gtk.org/gtk4/class.SignalListItemFactory.html<br>
