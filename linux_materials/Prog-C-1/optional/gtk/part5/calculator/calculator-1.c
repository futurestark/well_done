#include <stdlib.h>
#include <stdio.h>

#include <gtk/gtk.h>
#include <glade/glade.h>



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

    gtk_main();

    return 0;
}
