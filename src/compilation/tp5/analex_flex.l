%option noyywrap

%{
#include "y.tab.h"
%}

%%
[a-z0@] {yylval = yytext[0]; return SYMB;}

[\t]+ {}
.|\n {return yytext[0];}
%%
