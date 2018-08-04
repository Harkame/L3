%option noyywrap

%{
  #include "Argument.h"
  #include "Expression.h"
  #include "Cellule.h"
  #include "Binaire.h"

  using namespace modele;

  #include "y.tab.h"
%}

%%

[A-z0@][0-9] {return CELLULE;}
'+'|'-'|'*'  {return OPERATEUR;}

%%
