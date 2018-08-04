#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>

#define DROITS         0666
#define TAILLE_MESSAGE 255
#define MESSAGE_EXIT   "exit"
#define NOM_JETON      "JetonDuChat"

void exit(int p_signal)
{
  printf("Exit\r\n");
  exit(1);
}

void init()
{
  mkfifo(NOM_JETON, DROITS);
}

void set_jeton()
{
  int d_jeton = open(NOM_JETON, DROITS);

  if(d_jeton == -1)
    return;

  if(write(d_jeton, "Yolo", TAILLE_MESSAGE) == -1)
    return;
}

int lire_jeton()
{
  char message_entrant [TAILLE_MESSAGE];

  int d_jeton = open(NOM_JETON, DROITS);

  read(d_jeton, message_entrant, TAILLE_MESSAGE);

  if(strcmp(message_entrant, "Yolo") != 0)
    return 1;
  else
    return 0;
}

void ecrire(int p_fichier_sortant)
{
  set_jeton();

  char message_sortant [TAILLE_MESSAGE];

  scanf("%s", message_sortant);

  if(write(p_fichier_sortant, message_sortant, strlen(message_sortant)) == -1)
    return ;
}

void lire(int p_fichier_entrant)
{
  char message_entrant [TAILLE_MESSAGE];

  if(read(p_fichier_entrant, message_entrant, TAILLE_MESSAGE) != -1)
    printf("%s\r\n", message_entrant);

  printf("\r\n");
}

void chat(char* p_fichier_entrant, char* p_fichier_sortant)
{
  struct sigaction sig;
  sig.sa_handler = exit;

  mkfifo(p_fichier_sortant, DROITS);

  int jeton = 0;

  int d_fichier_entrant = open(p_fichier_entrant, DROITS);
  int d_fichier_sortant = open(p_fichier_sortant, DROITS);

  while(1)
  {
    jeton = lire_jeton();

    printf(">");

    if(jeton == 1)
    {
      ecrire(d_fichier_sortant);
      jeton = 0;
    }
    else
      lire(d_fichier_entrant);
  }
}

int main(int argc, char** argv)
{
  init();

  set_jeton();

  chat(argv[1], argv[2]);

  return 42;
}
