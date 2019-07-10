#include <gtk/gtk.h>


static gboolean delete_event(GtkWidget * widget, GdkEvent * event, gpointer data)
{
  return FALSE;
}

static void destroy(GtkWidget * widget, gpointer data)
{
  gtk_main_quit();
}

int main(int argc, char ** argv)
{
  GtkWidget * window;
  GtkWidget * fixed_container;
  GtkWidget * button;
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Fixed Buttons Demo");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  fixed_container = gtk_fixed_new ();
  gtk_container_add(GTK_CONTAINER(window), fixed_container);
  button = gtk_button_new_with_label("Button1");
  gtk_fixed_put(GTK_FIXED(fixed_container), button, 5, 5);
  gtk_widget_show(button);
  button = gtk_button_new_with_label("Button2");
  gtk_fixed_put(GTK_FIXED(fixed_container), button, 25, 35);
  gtk_widget_show(button);
  button = gtk_button_new_with_label("Button3");
  gtk_fixed_put(GTK_FIXED(fixed_container), button, 45, 65);
  gtk_widget_show(button);
  gtk_widget_show(fixed_container);
  gtk_widget_show(window);
  gtk_main();
  return 0;
}
