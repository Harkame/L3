/**
 * @file analex.c  
 * @author Michel Meynard
 * @brief Prog principal appelant analex()
 */
#include <stdio.h>
#include <string.h>
#include "afd.h"		/* DÃ©finition de l'AFD et des JETONS */
#include "analex1.h"		/* DÃ©finition de la fon : int analex() */

int main(){			/* Construction de l'AFD */
  int j;			/* jeton retournÃ© par analex() */
  char *invite="Saisissez un(des) mot(s) matchant a(b+c)?|bd, (les bd sont considÃ©rÃ©s comme des commentaires donc sont filtrÃ©s) suivi de EOF (CTRL-D) SVP : ";
  creerAfd();			/* Construction de l'AFD Ã  jeton */
  printf("%s",invite);		/* prompt */
  while((j=analex())){		/* analyser tq pas jeton 0 */
    printf("\nRÃ©sultat : Jeton = %d ; Lexeme = %s\n%s",j,lexeme,invite);
  }
  return 0;
}
