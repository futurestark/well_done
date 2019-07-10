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
  GtkWidget * font_selection;
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Font Selection");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  font_selection = gtk_font_selection_new ();
  gtk_container_add(GTK_CONTAINER(window), font_selection);
  gtk_widget_show(font_selection);
  gtk_widget_show(window);
  gtk_main();
  return 0;
}
