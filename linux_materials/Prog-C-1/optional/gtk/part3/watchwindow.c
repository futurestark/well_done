#include <gtk/gtk.h>

gint on_window_state(GtkLabel * label, GdkEventWindowState * window_state, gpointer callback_data )
{
  //if (window_state->new_window_state & (GDK_WINDOW_STATE_MAXIMIZED | GDK_WINDOW_STATE_ICONIFIED)) {
  if (window_state->new_window_state & GDK_WINDOW_STATE_ICONIFIED) {
    g_print("Window is iconified\n");
    return 0;
  }
  if (window_state->new_window_state & GDK_WINDOW_STATE_MAXIMIZED) {
    gtk_label_set_text(label, "Window is maximized");
    return 0;
  }
  gtk_label_set_text(label, "Window is in normal state");
  return 0;
}

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
  GtkWidget * label;
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "WatchWindow");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  label = gtk_label_new("Starting");
  gtk_container_add(GTK_CONTAINER(window), label);
  g_signal_connect_swapped(G_OBJECT(window), "window_state_event", G_CALLBACK(on_window_state), G_OBJECT(label));
  gtk_widget_show(label);
  gtk_widget_show(window);
  gtk_main();
  return 0;
}
