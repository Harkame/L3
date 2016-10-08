#include <glib.h>
#include <glib/gprintf.h>
#include <gtk/gtk.h>
#include <string.h>
#include "mm.h"

GtkTextBuffer *buffer;		/* global car modifié par callback */
GtkWidget *entree;		/* ligne de saisie */

mm jeu;				/* stocke le mot secret et le nb d'essais*/

/** callback appele lors d'un nouvel essai de l'utilisateur */
static void nouvelessai(GtkWidget *widget, gpointer data){
  gchar *essai;			/* les char saisis */
  gtk_text_buffer_insert_at_cursor(buffer,essai=(gchar *)gtk_entry_get_text(GTK_ENTRY(entree)),-1);
  int res=mm_test(jeu, essai);	// lien avec mm 
  //g_print("taille de essai : %d; essai: %s\n",strlen(essai),essai); /* DEBUG dans la console */
  if(res==-1)
    gtk_text_buffer_insert_at_cursor(buffer," : Erreur de saisie !\n",-1);
  else if (res==0)
    gtk_text_buffer_insert_at_cursor(buffer," : Aucune lettre correcte !\n",-1);
  else{
    char bien[10];
    sprintf(bien," : %d",res/(TAILLE+1));
    char mal[10];
    sprintf(mal,"%d",res%(TAILLE+1));
    gtk_text_buffer_insert_at_cursor(buffer,bien,-1);
    gtk_text_buffer_insert_at_cursor(buffer," lettres bien placees, ",-1);
    gtk_text_buffer_insert_at_cursor(buffer,mal,-1);
    gtk_text_buffer_insert_at_cursor(buffer," lettres mal placees !\n",-1);
    if(res/(TAILLE+1)==TAILLE){
      gtk_text_buffer_insert_at_cursor(buffer,"BRAVO ! Vous avez reussi en ",-1);
      sprintf(mal,"%d",mm_nbessais(jeu));
      gtk_text_buffer_insert_at_cursor(buffer,mal,-1);
      gtk_text_buffer_insert_at_cursor(buffer," essais !\n",-1);

      gtk_widget_set_sensitive (entree,FALSE); /* visible mais plus utilisable */
    }
  }
  gtk_entry_set_text(GTK_ENTRY(entree),"");
  /* effacement du precedent : A LA FIN car sinon efface la variable essai !*/
}
/** callback appelé par le bouton Nouveau Jeu */
static void nouveaujeu( GtkWidget *widget, gpointer data){
  mm_detruire(jeu);		/* désallouer */
  jeu= mm_creer();		/* nouveau */
  gtk_text_buffer_set_text(buffer,"",-1); /* effacer l'écran */
  //gtk_entry_set_editable(entree,TRUE);
  gtk_widget_set_sensitive (entree,TRUE); /* utilisable ! */
  gtk_widget_grab_focus(entree); /* focus */
}
/** callback appelé par le bouton Quitter */
static void quitter( GtkWidget *widget, gpointer data){
  gtk_text_buffer_insert_at_cursor(buffer,"Bye Bye !\n",-1);
  gtk_main_quit();
}
/** callback : fermeture par le windows manager de l'OS : appelle destroy*/
static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data){
  return FALSE;			/* si TRUE : ne ferme pas */
}

/* callback */
static void destroy( GtkWidget *widget, gpointer data){
  gtk_main_quit ();
}


int main(int argc, char *argv[]){ 
  gtk_init (&argc, &argv);	/* indispensable */
  
  /* create a new window */
  GtkWidget *window;
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "MasterMind");
  /* Set a decent default size for the window. */
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
   
  /* When the window is given the "delete-event" signal (this is given
   * by the window manager, usually by the "close" option, or on the
   * titlebar), we ask it to call the delete_event () function
   * as defined above. The data passed to the callback
   * function is NULL and is ignored in the callback function. */
  g_signal_connect (window, "delete-event",
		    G_CALLBACK (delete_event), NULL);
    
  /* Here we connect the "destroy" event to a signal handler.  
   * This event occurs when we call gtk_widget_destroy() on the window,
   * or if we return FALSE in the "delete-event" callback. */
  g_signal_connect (window, "destroy",
		    G_CALLBACK (destroy), NULL);
    
  /* Sets the border width of the window. */
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
  GtkWidget *vbox;
  
  vbox = gtk_vbox_new (FALSE, 2);
  gtk_container_add (GTK_CONTAINER (window), vbox);

  /* Create a multiline text widget. */
  GtkWidget *text_view;
  text_view = gtk_text_view_new ();
  gtk_box_pack_start (GTK_BOX (vbox), text_view, 1, 1, 0);// expand, fill, no pad

  /* Obtaining the buffer associated with the widget. */
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (text_view));
  gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);

  /* Aide initiale */
  gchar* aide=  g_strdup_printf("Trouvez la bonne combinaison de %d chiffres (0-9) en saisissant successivement vos essais sur %d chiffres !\n",TAILLE,TAILLE);
  gtk_text_buffer_set_text(buffer,aide,-1);


  entree=gtk_entry_new( ); /* entree interactive */
  gtk_box_pack_start (GTK_BOX (vbox), entree, 0, 0, 0); // expand, fill, no pad
  g_signal_connect (G_OBJECT (entree), "activate", 
		    G_CALLBACK (nouvelessai),
		    buffer);

  /* boite des boutons */
  GtkWidget *hbox;
  hbox = gtk_hbox_new (FALSE, 2);
  /* Create a close button. */
  GtkWidget *button_quitter;
  button_quitter = gtk_button_new_with_label ("Quitter");
  g_signal_connect (G_OBJECT (button_quitter), "clicked", 
		    G_CALLBACK (quitter), buffer);
  gtk_box_pack_start (GTK_BOX (hbox), button_quitter, 0, 0, 0); //taille mini

  /* Create a button. */
  GtkWidget *button_nouveaujeu;
  button_nouveaujeu = gtk_button_new_with_label ("Nouveau Jeu");
  gtk_box_pack_start (GTK_BOX (hbox), button_nouveaujeu, 0, 0, 0); //taille mini
  g_signal_connect (G_OBJECT (button_nouveaujeu), "clicked", 
		    G_CALLBACK (nouveaujeu), buffer);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, 0, 0, 0); //taille mini
  

  gtk_widget_grab_focus(entree); /* focus */
  gtk_widget_show_all (window);
    
  jeu=mm_creer();		/* init du jeu ! */
  //g_print("jeu : %s\n",jeu->secret); /* DEBUG dans la console */
  /* boucle principale */
  gtk_main ();
  return 0;
}
