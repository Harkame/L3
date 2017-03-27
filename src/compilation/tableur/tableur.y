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
  using namespace modele;

%}
%union
{
  char c;
  int i;
  Binaire* b;
}

%type<b> expression;

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

expression : expression '+' expression {$$ = new Binaire('+', $1, $3); cout << "Expr :" << $$->toString() << endl;}
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
