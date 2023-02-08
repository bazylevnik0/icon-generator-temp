<b>maybe naive but whole concept:</b><br>
main buffer and buffers for each element, when buffer of element changing then main buffer changing and redrawing<br> 

<b>/drawsvg</b><br>
i found this https://stackoverflow.com/questions/19452797/draw-a-svg-image-in-gtk3-from-svg-source-in-python/29118034#29118034 it is also about drawing but i not sure - this required or not<br>
i mean maybe we need draw svg from buffer maybe we can just draw svg as a regular png and get buffer after<br>
Gtk.image can draw from GdkPixbuf<br>
https://docs.gtk.org/gtk3/class.Image.html<br>
https://docs.gtk.org/gdk-pixbuf/class.Pixbuf.html<br>

<b>temp:</b><br>
adding png/svg to app:<br>

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
also not showing and got error(something about - widget is not root)<br>


or<br>

-something like a binding with ui template<br>
https://developer.gnome.org/documentation/tutorials/beginners/getting_started/content_view.html<br>
here something about binding but it is about how to set in xml and get it in code(as i understand)<br>
-----------------------------------------------------------------------------<br>
2:<br>
here https://stackoverflow.com/questions/57654275/i-added-a-gtk-widget-to-the-main-window-ui-file-but-it-doesnt-show-up<br>
example of adding image as a object to xml<br>
it is works with example from stackoverflow(folder 21)<br>

after this we maybe need this:<br>
binding object(same as a 5)(folder 22):<br>
https://developer.gnome.org/documentation/tutorials/beginners/getting_started/content_view.html<br>

and next this
here about adding functions as xml property and code(folder 212 and folder 222):<br>
https://developer.gnome.org/documentation/tutorials/beginners/getting_started/opening_files.html<br>
*this for next session - goal is change source of image to test.png

