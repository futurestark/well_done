/*
  GTK+ Demo by Andrei Borovsky, <borovsky@tochka.ru>
  compile command:
  gcc -Wall helloworld.c -o helloworld `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
*/

#include <gtk/gtk.h>
#include <libintl.h>

#define _(String) gettext (String)
#define gettext_noop(String) String
#define N_(String) gettext_noop (String)

#define GETTEXT_PACKAGE "helloworld"
#define LOCALEDIR "./locale"

static void button_clicked(GtkWidget * widget, gpointer data)
{
 g_print("Button pressed!\n");
}

static gboolean delete_event(GtkWidget * widget, GdkEvent * event, gpointer data)
{
  g_print("Delete event occurred\n");
  return FALSE;
}

static void destroy(GtkWidget * widget, gpointer data)
{
  g_print("Destroy signal sent\n");
  gtk_main_quit();
}

int main(int argc, char ** argv)
{
  GtkWidget * window;
  GtkWidget * button;

  bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), _("Hello World!"));
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  button = gtk_button_new_with_label(_("Quit"));
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_clicked), NULL);
  g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));
  gtk_container_add(GTK_CONTAINER(window), button);
  gtk_widget_show(button);
  gtk_widget_show(window);
  gtk_main();
  return 0;
}
