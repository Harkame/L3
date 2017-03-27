%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <ctype.h>

  #include "Argument.h"
  #include "Expression.h"
  #include "Cellule.h"
  #include "Binaire.h"

  int yyparse();
  int yylex();
  int yyerror(char* s);
%}

%union
{
  char c;
  int i;
  modele::Cellule* cel;
  modele::Binaire* b;
}

%type<b> expression;
%type<cel> cellule

%token<c> LIGNE
%token<i> COLONNE
%token<i> VALEUR
%token<i> CELLULE
%token<c> OPERATEUR

%%

liste : liste ligne {}
      |             {}
      ;

ligne : expression '\n' {cout << $1->toString();}
      ;

expression : expression OPERATEUR expression {$$ = new modele::Binaire($2, $1, $3); cout << $$->toString() << endl;}
           ;
%%

int yyerror(char* s)
{
  fprintf(stderr,"%s\n",s);
}

int main()
{
  if (!yyparse())
    printf("\n:)\n");
  else
    printf("\n:(\n");

  return 0;
}
