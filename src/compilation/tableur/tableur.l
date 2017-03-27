%option noyywrap

%{
  #include "y.tab.h"

  #include "Argument.h"
  #include "Expression.h"
  #include "Cellule.h"
  #include "Binaire.h"
%}

%%

[A-z0@][0-9] {return CELLULE;}
'+'|'-'|'*'  {return OPERATEUR;}

%%
