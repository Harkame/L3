%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arbin.h"

/* les macros sont des blocs : pas de ';' apres */
#define AVANCER {numcar+=yyleng; jeton = yylex();}
#define TEST_AVANCE(prevu) {if (jeton==(prevu)) AVANCER else ERREUR_SYNTAXE}
#define ERREUR_SYNTAXE {printf("\nMot non reconnu : erreur de syntaxe \
au caractère numéro %d \n",numcar); exit(1);}
#define SYMB 300

Arbin U(void);Arbin Ru(Arbin);Arbin C(void);Arbin Rc(Arbin);Arbin E(void); Arbin Re(Arbin); Arbin F(void);  /* déclars */

int jeton;                       /* caractère courant du flot d'entrée */
int numcar=0;                    /* numero du caractère courant (jeton) */
int c;
%}


/* ZONE DES REGLES apres le Arbin pourcent (OBLIGATOIRE) */
%%
[a-z0@] {return SYMB;}
[\t]+ {}
.|\n {return yytext[0];}
%%

/* ZONE DES FONCTIONS C (OPTIONNELLE) */
Arbin U(void){
    return Ru(C());                        /* regle : U->C Ru */
}

Arbin Ru(Arbin gauche){
    if (jeton=='|') {             /* regle : Ru-> '|'C Ru */
        AVANCER
        return Ru(ab_construire('|',gauche,C()));
    }
    else if (jeton=='\n'||jeton==')') {
        return gauche;
    }
    else ERREUR_SYNTAXE
}

Arbin C(void){
    return Rc(E());                          /* regle : C->E Rc */
}

Arbin Rc(Arbin gauche){
    if (jeton==SYMB||jeton=='(') {             /* regle : Rc->E Rc */
        return Rc(ab_construire('.',gauche,E()));
    }
    else if (jeton=='\n'||jeton==')'||jeton=='|') {
        return gauche;
    }
    else ERREUR_SYNTAXE
}

Arbin E(void) {
    return Re(F());                /* regle : E->F Re */
}

Arbin Re(Arbin gauche) {
    if(jeton == '*') {                /* regle : Re->*Re */
        AVANCER
        return Re(ab_construire('*',gauche,NULL));
    }
    else if (jeton=='\n'||jeton==')'||jeton=='('||jeton==SYMB||jeton=='|') {
        return gauche;
    }
    else ERREUR_SYNTAXE
}

Arbin F(void)
{
    if (jeton=='(') {             /* regle : F->(U) */
        AVANCER
        Arbin r = U();
        TEST_AVANCE(')')
        return r;
    }
    else if (jeton==SYMB) {        /* regle : F->SYMB */
        int ch = yytext[0];
        AVANCER
        return ab_construire(ch,NULL,NULL);
    }
    else ERREUR_SYNTAXE
}

int main(void)
{
    AVANCER            /* initialiser jeton sur le premier car */
    Arbin r = U();                          /* axiome */

    if(jeton=='\n')
        ab_afficher(r);
    else
      ERREUR_SYNTAXE

    return 0;
}
