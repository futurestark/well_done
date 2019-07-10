#include <gtk/gtk.h>


void
on_toolbutton1_clicked                 (GtkToolButton   *toolbutton,
                                        gpointer         user_data);

void
on_toolbutton2_clicked                 (GtkToolButton   *toolbutton,
                                        gpointer         user_data);

gboolean
on_window1_destroy_event               (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_window1_destroy                     (GtkObject       *object,
                                        gpointer         user_data);
