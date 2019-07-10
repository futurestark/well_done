#include <stdlib.h>
#include <stdio.h>

#include <gtk/gtk.h>
#include <glade/glade.h>

#define INPUT_MODE 1
#define COPY_MODE 2

#define OP_NONE 0
#define OP_PLUS 1
#define OP_MINUS 2

static signed long int fgvalue;
static signed long int bgvalue;
static char screen[32];
static int mode;
static int op_state;


void on_numeric_button_clicked(gpointer user_data, GtkButton *button)
{
  int i = atoi(gtk_button_get_label(button));
  if (mode == COPY_MODE) {
    bgvalue = fgvalue;
    fgvalue = 0;
    mode = INPUT_MODE;
  }
  fgvalue = fgvalue*10 + i;
  sprintf(screen, "%li\0", fgvalue);
  gtk_entry_set_text(GTK_ENTRY(user_data), screen);
}

void on_operation_button_plus_clicked(GtkButton *button)
{
  mode = COPY_MODE;
  op_state = OP_PLUS;
}

void on_operation_button_minus_clicked(GtkButton *button)
{
  mode = COPY_MODE;
  op_state = OP_MINUS;

}

void on_operation_button_equal_clicked(gpointer user_data, GtkButton *button)
{
  switch (op_state) {
    case OP_PLUS:
      fgvalue += bgvalue;
      break;
    case OP_MINUS:
      fgvalue = bgvalue - fgvalue;
    default:;
  }
  sprintf(screen, "%li\0", fgvalue);
  gtk_entry_set_text(GTK_ENTRY(user_data), screen);
  mode = COPY_MODE;
}

void on_operation_button_cancel_clicked(gpointer user_data, GtkButton *button)
{
  bgvalue = fgvalue = 0; 
  mode = COPY_MODE;
  op_state = OP_NONE;
  sprintf(screen, "%li\0", fgvalue);
  gtk_entry_set_text(GTK_ENTRY(user_data), screen);
}

int main (int argc, char **argv)
{
    GladeXML *xml;
    gtk_init(&argc, &argv);
    glade_init();

    xml = glade_xml_new("calculator.glade", "rootwnd", NULL);
    if (!xml) {
	g_warning("Failed to create the interface");
	return 1;
    }
    glade_xml_signal_connect(xml, "gtk_main_quit", G_CALLBACK(gtk_main_quit));
    glade_xml_signal_connect(xml, "on_numeric_button_clicked", G_CALLBACK(on_numeric_button_clicked));
    glade_xml_signal_connect(xml, "on_operation_button_plus_clicked", G_CALLBACK(on_operation_button_plus_clicked));
    glade_xml_signal_connect(xml, "on_operation_button_minus_clicked", G_CALLBACK(on_operation_button_minus_clicked));
    glade_xml_signal_connect(xml, "on_operation_button_equal_clicked", G_CALLBACK(on_operation_button_equal_clicked));
    glade_xml_signal_connect(xml, "on_operation_button_cancel_clicked", G_CALLBACK(on_operation_button_cancel_clicked));
    mode = COPY_MODE;
    op_state = OP_NONE;
    fgvalue = 0;
    bgvalue = 0;
    gtk_main();

    return 0;
}
