%option noyywrap

%{
    #include "afd.h"
    double yylval;
%}

%%
[0-9]+\.[0-9]*|\.[0-9]+|[0-9]+    {char *ptr;yylval= strtod(yytext,&ptr); return 300;}
[\t] {}
.|\n {return yytext[0];}

%%

/*
* Union
*/
Arbin U()
{
  return Ru(C());
}

/*
* Reste Union
*/
Arbin Ru(Arbin g)
{
  if(jeton == '|')
  {
    AVANCER;
    return Ru(ab_construire('|', g, C()));
  }
  else if(jeton == '\n' || jeton == ')')
    return g;
  else
    ERREUR_SYNTAXE;
}

/*
* Concatenation
*/
Arbin C()
{
  return Rc(E());
}

/*
* Reste Concatenation
*/
Arbin Rc(Arbin g)
{
  if(suivant(jeton) == premier())
  {
    return Rc(E());
  }
  else
    ERREUR_SYNTAXE;
}

/*
*
*/
Arbin E()
{
  return Re(F());
}

/*
*
*/
Arbin Re()
{

}

/*
*
*/
Arbin F()
{
  iif(jeton == SYMB)
    return ab_construire(c, NULL, NULL);
}

int main()
{
    Arbin arbin = U();
    ab_afficher(arbin);
}
