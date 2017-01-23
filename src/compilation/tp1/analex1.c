#include <stdio.h>
#include <string.h>
#include "afd.h"
#include "analex1.h"

int main()
{
  int j;			/* jeton retourné par analex() */
  char* invite = "Mots : ";
  creerAfd();
  printf("%s",invite);
  printf("\n");

  while((j = analex()))
  {
    printf("\nRésultat : Jeton = %d ; Lexeme = %s\n%s",j,lexeme,invite);
  }

  return 0;
}
