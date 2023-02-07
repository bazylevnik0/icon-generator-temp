<b>maybe naive but whole concept:</b><br>
main buffer and buffer for each element, when element buffer changing then main buffer changing and redrawing<br> 

<b>draw svg</b><br>
i found this https://stackoverflow.com/questions/19452797/draw-a-svg-image-in-gtk3-from-svg-source-in-python/29118034#29118034 it is also about drawing but i not sure - this required or not<br>
i mean maybe we need draw svg from buffer maybe we can just draw svg as a regular png and get buffer after<br>
Gtk.image can draw from GdkPixbuf<br>
https://docs.gtk.org/gtk3/class.Image.html<br>
https://docs.gtk.org/gdk-pixbuf/class.Pixbuf.html<br>


temp:<br>
adding png/svg to frame to app:<br>
two ways what i found:<br>
1a)i tried use method from gtk when getting builder, get frame, creating image object and set it as child, but "child set" function is implicit<br>
1b)also i tried set image as element in xml, get this image from builder and use gtk_image_set_from_file but i got assertion 'GTK_IS_IMAGE (image)' failed<br>
https://developer.gnome.org/documentation/tutorials/menus.html<br>
https://github.com/bazylevnik0/learning/blob/main/system/guided/gtk/building/fullapplication/app.c<br>
2)gnome builder loaded ui as a templates with gtk_widget_class_set_template_from_resource i triedsomethin but with failure<br>
https://developer.gnome.org/documentation/tutorials/widget-templates.html<br>

-----------------------------------------------------------------------------<br>
for next session:<br>
try again and write notes about these ways, also make copy for failure variants<br>

