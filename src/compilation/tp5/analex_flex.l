%option noyywrap

%{
  #include "arbin.h"
  #include "y.tab.h"
%}

%%
[A-z0@] {yylval.i = yytext[0]; return SYMB;}

[\t]+ {}
.|\n {return yytext[0];}
%%
