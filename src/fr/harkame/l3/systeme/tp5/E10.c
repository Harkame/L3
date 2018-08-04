#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

/*
void run()
{
  char commande [100];
  while(strcmp(commandes, "exit") != 0)
  {
    scanf("%s", &commande);
    if(0 == fork())
    {
      char** commande_decompose = decompose_commandes(commande);
      exectl("/bin/bash", commande_decompose, NULL);
      free_commande(commande_decompose);
    }
  }
}

char** decompose_commandes(char* p_commande)
{
  char** commande = malloc(sizeof(char));
  int compteur_parametres;
  int index;
  for(index = 0; index < strlen(p_commande); index++)
    if(p_commande[index] == '-')
      compteur_parametres++;
  const char separateur[1] = " ";
  char* token;
  token = strtok(commande, p_commande);
  strcpy(commande[0], token);
  for(index = 1; index < compteur_parametres; index++)
  {
    commande[index] = malloc(200 * sizeof(char));
    token = strtok(NULL, p_commande);
    strcpy(commande, token);
    return(0);
  }
  }
  return commande;
}

void free_commande(char** p_commande)
{
  for(int index = 0; index < strlen(p_commande); index ++)
    free(p_commande[index]);
  free(p_commande);
}
*/

int main(int argc, char** argv)
{
  //run(argv);
  execl("/bin/pwd", argv[1], NULL);
}
