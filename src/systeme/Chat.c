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

void exit(int p_signal)
{
  printf("Exit\r\n");
  exit(1);
}

void chat1(char* p_fichier_entrant, char* p_fichier_sortant)
{
  struct sigaction sig;
  sig.sa_handler = exit;

  mkfifo(p_fichier_sortant, 0666);

  int d_fichier_entrant = open(p_fichier_entrant, DROITS);
  int d_fichier_sortant = open(p_fichier_sortant, DROITS);

  char message_entrant [TAILLE_MESSAGE];
  char message_sortant [TAILLE_MESSAGE];

  while(strcmp(message_entrant, MESSAGE_EXIT) != 0)
  {
    printf(">");
    if(read(d_fichier_entrant, message_entrant, TAILLE_MESSAGE) == -1)
      return;
    else
      printf("%s\r\n", message_entrant);

    scanf("%s", message_sortant);
    if(write(d_fichier_sortant, message_sortant, strlen(p_fichier_sortant)) == -1)
      return;
  printf("\r\n");
  }
}

void chat2(char* p_fichier_entrant, char* p_fichier_sortant)
{
  struct sigaction sig;
  sig.sa_handler = exit;

  mkfifo(p_fichier_sortant, 0666);

  int d_fichier_entrant = open(p_fichier_entrant, DROITS);
  int d_fichier_sortant = open(p_fichier_sortant, DROITS);

  char message_entrant [TAILLE_MESSAGE];
  char message_sortant [TAILLE_MESSAGE];

  while(strcmp(message_entrant, MESSAGE_EXIT) != 0)
  {
    printf(">");
    scanf("%s", message_sortant);
    if(write(d_fichier_sortant, message_sortant, strlen(p_fichier_sortant)) == -1)
      return;

    if(read(d_fichier_entrant, message_entrant, TAILLE_MESSAGE) == -1)
      return;
    else
      printf("%s\r\n", message_entrant);
  printf("\r\n");
  }
}

int main(int argc, char** argv)
{
  if(strcmp(argv[3], "1"))
    chat1(argv[1], argv[2]);
  else
    chat2(argv[1], argv[2]);

  return 42;
}
