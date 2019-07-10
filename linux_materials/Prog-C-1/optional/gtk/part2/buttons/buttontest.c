#include <gtk/gtk.h>

static void button_clicked(GtkWidget * widget, gpointer data)
{
  gint i = * (gint *) data;
  g_print("Button #%i is pressed!\n", i);
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
  GtkWidget * button1;
  GtkWidget * button2;
  GtkWidget * box;
  gint i1, i2;
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Buttons");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  box = gtk_hbox_new(TRUE, 2);
  gtk_container_add(GTK_CONTAINER(window), box);
  button1 = gtk_button_new_with_label("Выход");
  i1 = 1;
  g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(button_clicked), &i1);
  g_signal_connect_swapped(G_OBJECT(button1), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));
  gtk_box_pack_start(GTK_BOX(box), button1, TRUE, TRUE, 0);
  button2 = gtk_button_new_with_label("Кнопка 2");
  i2 = 2;
  g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(button_clicked), &i2);
  gtk_box_pack_start(GTK_BOX(box), button2, TRUE, TRUE, 0);
  gtk_widget_show(button1);
  gtk_widget_show(button2);
  gtk_widget_show(box);
  gtk_widget_show(window);
  gtk_main();
  return 0;
}
