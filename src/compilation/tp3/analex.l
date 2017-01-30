%{
  #include "afd.h"
%}

digit         [0-9]
letter        [a-zA-Z]

%%
(.|\n)               { return yytext[0]; }

"("                  { return 12;       }
")"                  { return 13;       }

"+"                  { return 14;       }
"-"                  { return 15;       }

{digit*}               { return 300;      }

( |\t|\n)            { return 301;    }

%%

int yywrap(void){return 1;}
