#include <gtk/gtk.h>
#include "exemploapp.h"

int main (int argc, char *argv[])
{
	return g_application_run (G_APPLICATION (example_app_new ()), argc, argv);
}
