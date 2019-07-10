#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_toolbutton1_clicked                 (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
	GtkWidget * file_chooser_dialog;
	file_chooser_dialog = gtk_file_chooser_dialog_new("Открыть", NULL,
        	GTK_FILE_CHOOSER_ACTION_OPEN, 
		GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
		GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
		NULL);
	if (gtk_dialog_run(GTK_DIALOG (file_chooser_dialog)) == GTK_RESPONSE_ACCEPT)
	{
		GtkWidget * toplevel;
		GtkWidget * image;
		char *filename;
		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser_dialog));
		toplevel = gtk_widget_get_toplevel(GTK_WIDGET(toolbutton));
		image = lookup_widget(GTK_WIDGET(toplevel), "image1");
		gtk_image_set_from_file(GTK_IMAGE(image), filename);
		gtk_window_set_title(GTK_WINDOW(toplevel), filename);
		g_free (filename);
	}
	gtk_widget_destroy (file_chooser_dialog);
	
}


void
on_toolbutton2_clicked                 (GtkToolButton   *toolbutton,
                                        gpointer         user_data)
{
	GtkWidget * about_dialog;
	about_dialog = create_aboutdialog1();
	gtk_widget_show(about_dialog);
}

void
on_window1_destroy                     (GtkObject       *object,
                                        gpointer         user_data)
{
	gtk_main_quit();
}

