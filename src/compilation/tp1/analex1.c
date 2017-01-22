#include <stdio.h>
#include <string.h>
#include "afd.h"
#include "analex1.h"

int main()
{
  int j;			/* jeton retourné par analex() */
  char* invite = "Saisissez un(des) mot(s) matchant a(b+c)?|bd, (les bd sont considérés comme des commentaires donc sont filtrés) suivi de EOF (CTRL-D) SVP : ";
  creerAfd();
  printf("%s",invite);

  while((j = analex()))
  {
    printf("\nRésultat : Jeton = %d ; Lexeme = %s\n%s",j,lexeme,invite);
  }

  return 0;
}
