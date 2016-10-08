#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int file_size(const char *filename)
{
   struct stat s;

   if  (stat(filename,&s) != 0) {
      printf("error!\n" );
      return 0;
   }
   return s.st_size;
}

int recherche_dicho_aux(char* p_buffer, char p_caractere, char p_indice)
{
  if((int)p_buffer[p_indice] > (int)p_caractere)
    recherche_dicho_aux(p_buffer, p_caractere, p_indice - (p_indice / 2));
  else if((int)p_buffer[p_indice] < (int)p_caractere)
    recherche_dicho_aux(p_buffer, p_caractere, p_indice + (p_indice / 2));
  else
    return p_indice;
}

int recherche_dicho(char* p_fichier, char p_caractere)
{
  int fichier = open(p_fichier, O_RDONLY);
  int taille_fichier = 0;
  taille_fichier = file_size(p_fichier);
  char buffer [taille_fichier];
  read(fichier, buffer, taille_fichier);
  close(fichier);
  return recherche_dicho_aux(buffer, p_caractere, (sizeof(buffer) / sizeof(char)) / 2);
}

int main(int argc, char* argv[])
{
  printf("Le caractere %c est a la position %d\r\n", argv[2][0], recherche_dicho(argv[1], argv[2][0]));
}
