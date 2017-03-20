%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <ctype.h>

  #include "arbin.h"

  int yyparse();
  int yylex();
  int yyerror(char* s);
%}

%union
{
  Arbin a;
  int i;
}

%type<a> expression
%token<i> SYMB QUIT

%left '|'
%left CONCAT SYMB '('
%left '*'

%%

liste : liste ligne {}
      |             {}

ligne : expression '\n' {ab_afficher($1);}
      ;

expression : expression '|' expression {$$ = ab_construire('|', $1, $3);}
           | expression expression %prec CONCAT      {$$ = ab_construire('.', $1, $2);}
           | expression '*'                {$$ = ab_construire('*', $1, NULL);}
           | '(' expression ')'            {$$ = $2;}
           | SYMB                          {$$ = ab_construire($1, NULL, NULL);}
           ;

%%

int yyerror(char* s)
{
  fprintf(stderr,"%s\n",s);
}

int main()
{
  if (!yyparse())
    printf("\nexpression reconnue\n");
  else
    printf("\nexpression non reconnue\n");

  return 0;
}
