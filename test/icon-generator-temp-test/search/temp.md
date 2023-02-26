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
"GtkListItemFactory creates widgets for the items taken from a GListModel."<br>
possible create GtkListItemFactory with .ui https://docs.gtk.org/gtk4/class.BuilderListItemFactory.html<br>
*not sure about need or not need but signals https://docs.gtk.org/gtk4/class.SignalListItemFactory.html<br>

i am tried something(3) but i not really understand how it works and not can found examples and not understood docs about gridview<br>
i asked in GTK chat and gtk-demos have this:<br>
https://gitlab.gnome.org/GNOME/gtk/-/blob/main/demos/gtk-demo/listview_filebrowser.c<br>
https://gitlab.gnome.org/GNOME/gtk/-/blob/main/demos/gtk-demo/listview_filebrowser.ui<br>
*(4)

c)grid with creating elements from array and array will scaning current folder<br>
before i can write pseudo code for this:<br>
create grid in ui<br>
create array "elements" with URI(paths of svg files) and copy to elements_temp, /usr/local/lib/image-generator/ or /lib/image-generator/<br>
loop for place elements in grid (box with(name(label), preview(image))<br>
if it possible handle click on grid and get element from grid, if not possible handle box of element(worse case)<br>
search - search input, handle changes and filter array to temp array and rebuild grid<br>
*also it is will not work good with > 100 elements(i mean memory) and maybe possible realize something like conveyer for scrolling, i mean load only few elements in screen<br>

**first test , just adding hardcoded elements through .c to gridview(51)<br>
**make uploading of all files in Pictures and viewing(52) - really with some conventions(not dynamic "elements", not localized "Pictures")<br>

next to do:<br>
make dynamic scrolling and searching<br>
