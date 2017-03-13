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
%token<i> SYMB

%left '|'
%left '*'

%%

liste : liste ligne {}
      |             {}
      ;

ligne : expression '\n' {Arbin a = ab_construire($1, NULL, NULL); ab_afficher(a);}
      |                 {}
      ;

expression : '(' expression '|' expression {$$ = ab_construire('|', $2, $4);}
           | expression expression         {$$ = ab_construire('.', $1, $2);}
           | expression '*'                {$$ = ab_construire('*', $1, NULL);}
           | '(' expression ')'            {$$ = $2;}
           |                               {}
           ;

%%

int yylex()
{
  int c;
  c = getchar();
  while(c == ’ ’ || c == ’\t’);
    return c;
}

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
