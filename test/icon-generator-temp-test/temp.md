<b>maybe naive but whole concept:</b><br>
main buffer and buffers for each element, when buffer of element changing then main buffer changing and redrawing<br> 

i found this https://stackoverflow.com/questions/19452797/draw-a-svg-image-in-gtk3-from-svg-source-in-python/29118034#29118034 it is also about drawing but i not sure - this required or not<br>
i mean maybe we need draw svg from buffer maybe we can just draw svg as a regular png and get buffer after<br>
Gtk.image can draw from GdkPixbuf<br>
https://docs.gtk.org/gtk3/class.Image.html<br>
https://docs.gtk.org/gdk-pixbuf/class.Pixbuf.html<br>

<b>/drawsvg</b><br>

<b>adding png/svg to app:</b><br>
maybe these ways:<br>
1)Add image as in gnome tutorial and find method for add it to ui<br> 
2)Add image to xml, with property of object(child) "action" and make connection between images with these functions<br>
3)Add frame to xml, get frame in code,creating image object(as in 1) and set it as child<br>
4)Add image(empty) to xml, get this widget from builder and use gtk_image_set_from_file <br>
https://developer.gnome.org/documentation/tutorials/menus.html<br>
https://github.com/bazylevnik0/learning/blob/main/system/guided/gtk/building/fullapplication/app.c<br>
5)Add image as a template<br>
https://developer.gnome.org/documentation/tutorials/widget-templates.html<br>
https://developer.gnome.org/documentation/tutorials/beginners/getting_started/content_view.html<br>
-----------------------------------------------------------------------------<br>
1:<br>
https://developer.gnome.org/documentation/tutorials/beginners/components/image.html<br>
it is regular gtk request for creating widget<br>
it is awesome but it is not showing in app(maybe it is will be usefull in future for loading as a buffer)<br>

in gtk tutorial was used method like a https://docs.gtk.org/gtk4/method.Window.set_child.html to adding widget to window<br>
i added these functions to application activate(compiled without errors) but image not showing:<br>
<i>GtkWidget *image = gtk_picture_new_for_filename ("test.png");<br>
gtk_window_set_child ( window, image );</i>

maybe new widget need:<br>
-extra properties<br> 
https://stackoverflow.com/questions/58322059/set-property-of-a-child-of-a-gtk-container<br>
maybe this property <property name="visible">True</property><br>
i tried <i> gtk_widget_set_visible (image, TRUE);</i> but image not showing<br>
also i tried:<br>
<i>gtk_widget_set_parent( image , GTK_WIDGET(window));<br>
gtk_widget_set_child_visible(GTK_WIDGET(window), TRUE);</i><br>
also not showing and got the error(something about - widget is not root)<br>
-----------------------------------------------------------------------------<br>
2:<br>
here https://stackoverflow.com/questions/57654275/i-added-a-gtk-widget-to-the-main-window-ui-file-but-it-doesnt-show-up<br>
example of adding an image as a object to xml<br>
it is works with example from stackoverflow(folder 21)<br>

after this we maybe need this:<br>
binding object(same as a 5)(folder 22):<br>
https://developer.gnome.org/documentation/tutorials/beginners/getting_started/content_view.html<br>

and next this
here about adding functions as xml property and code:<br>
https://developer.gnome.org/documentation/tutorials/beginners/getting_started/opening_files.html not sure about it<br>
but i found working method, something like this https://developer.gnome.org/documentation/tutorials/beginners/getting_started/cursor_position.html<br>
it s works (folder 221)<br>
*in 221 i use two methods for loading:<br>
-absolute path<br>
-gresource path - recomended but for my case i think this method needed generate a gresource file when building the app(i mean it is more question about structure of an app and maybe it is must be realized in future)<br>

<b>/editsvg</b>
<b>change position, size, rotate</b><br>
1)in previous test(/drawsvg) used gtk_image_set_from_resource it is works with:<br> 
gtk_image_set_from_resource https://gitlab.gnome.org/GNOME/gtk/-/blob/main/gtk/gtkimage.c<br>
it is using gdk_paintable_new_from_resource_scaled<br>
Paintable<br>
https://docs.gtk.org/gdk4/iface.Paintable.html<br>
https://gitlab.gnome.org/GNOME/gtk/-/blob/main/gdk/gdkpaintable.c<br>
but i not can find gdk_paintable_new_from_resource_scaled<br>
*i mean maybe in under the hood of Image possible work with data of image

2)
for edit in svg possible using just transform attribute: https://developer.mozilla.org/en-US/docs/Web/SVG/Attribute/transform<br>
found this:<br>
https://stackoverflow.com/questions/9848101/how-can-i-dynamically-change-the-color-of-an-element-in-an-svg-image-in-gtk<br>

*i used resource for file path in the previous test - but next methods is using GFile and GFile is using absolute path<br>
21)<br>
g_file_new_for_path - GFile from a path<br>
g_file_create_readwrite - from GFile to GFileIOStream<br>
*maybe it is possible working with GSeekable with g_seekable_seek() and  g_seekable_truncate()<br>
with seekable(temp):<br>
<i>
GFile *file = g_file_new_for_path("/home/nik0/Projects/icon-generator-temp-test-editsvg/src/test.svg");<br>
GFileIOStream *iostream = g_file_create_readwrite(file, G_FILE_CREATE_NONE, NULL, NULL);<br>
g_seekable_seek(G_SEEKABLE(iostream), '<', G_SEEK_CUR, NULL, NULL );</i><br>
*it is not works for me - the compilator writing something about: iostream not a seekable<br>
*maybe g_seekable_seek called before succesfull creating stream and i must use async creating stream<br>
22)<br>
also exist input and output streams:<br>
g_io_stream_get_input_stream - get input stream from GIOStream(GFileIOStream part of GIOStream)<br>
g_io_stream_get_output_stream - get input stream from GIOStream(GFileIOStream part of GIOStream)<br>
g_input_stream_read but it is works with an input stream<br>
g_output_stream_write works with an output stream<br>
*but i tried use GFileIOStream in get stream functions and get error about GFileIOStream not a GIOStream<br>
23)read with gresource (exist method for create a read stream) then we create a temp file in the temp folder and working with the copy<br>
231)same(23) but using g_file_new_tmp(really temporary file)<br>

/transform<br>
0,1,2 - transform scale, rotation, position(translate)<br>
3 - all atributes<br>

/combine<br>
i think it is possible to have an one main svg clear file and copy to this file objects from <g> of an elements files
*for the prototype will be trouble with selecting elements because in element file they not have a groups and when they will copying to main file they will lost belonging to a "group" and now i don't know how possible to realize selecting paths,circles etc of selected elements in main file, maybe something like label or tags, id's when copying elements to main<br>
https://www.w3.org/TR/SVG/struct.html<br>
**also <g> it is groups and possible combine g elements - i mean just read struct and try all examples, and make notes about it<br>

