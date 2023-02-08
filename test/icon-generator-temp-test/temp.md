<b>maybe naive but whole concept:</b><br>
main buffer and buffers for each element, when buffer of element changing then main buffer changing and redrawing<br> 

<b>draw svg</b><br>
i found this https://stackoverflow.com/questions/19452797/draw-a-svg-image-in-gtk3-from-svg-source-in-python/29118034#29118034 it is also about drawing but i not sure - this required or not<br>
i mean maybe we need draw svg from buffer maybe we can just draw svg as a regular png and get buffer after<br>
Gtk.image can draw from GdkPixbuf<br>
https://docs.gtk.org/gtk3/class.Image.html<br>
https://docs.gtk.org/gdk-pixbuf/class.Pixbuf.html<br>

<b>temp:</b><br>
adding png/svg to app:<br>

maybe these ways:<br>
1)Add image as in gnome tutorial: https://developer.gnome.org/documentation/tutorials/beginners/components/image.html and find method for add it to ui<br> 
2)Add image to xml, with property of object(child) "action"(like this https://developer.gnome.org/documentation/tutorials/beginners/getting_started/opening_files.html ) and make connection between images with these functions<br>
3)Add frame to xml, get frame in code,creating image object(as in 1) and set it as child<br>
4)Add image(empty) to xml, get this widget from builder and use gtk_image_set_from_file <br>
https://developer.gnome.org/documentation/tutorials/menus.html<br>
https://github.com/bazylevnik0/learning/blob/main/system/guided/gtk/building/fullapplication/app.c<br>
5)Add image as a template<br>
https://developer.gnome.org/documentation/tutorials/widget-templates.html<br>
https://developer.gnome.org/documentation/tutorials/beginners/getting_started/content_view.html<br>
-----------------------------------------------------------------------------<br>

