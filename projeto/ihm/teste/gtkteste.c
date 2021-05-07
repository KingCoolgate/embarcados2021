#include <gtk/gtk.h>

static void
activate (GtkApplication* teste,
          gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (teste);
  gtk_window_set_title (GTK_WINDOW (window), "GTK teste");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *teste;
  int status;

  teste = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (teste, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (teste), argc, argv);
  g_object_unref (teste);

  return status;
}
