#ifndef AFD_H
#define AFD_H

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "arbin.h"

#define  SYMB 300
#define AVANCER {c = getchar(); if(islower(c) || c == '@' || c == '0'){jeton = SYMB;}else{jeton = c;}}
#define TEST_AVANCE(prevu) {if (jeton==(prevu)) AVANCER else ERREUR_SYNTAXE}
#define ERREUR_SYNTAXE {printf("\nFail (%d)\n",numcar); exit(1);}
#define ESTPREMIER

int c      = 0;
int jeton  = 0;
int numcar = 0;

Arbin U();
Arbin Ru(Arbin);

Arbin C();
Arbin Rc(Arbin);

Arbin E();
Arbin Re();

#endif
