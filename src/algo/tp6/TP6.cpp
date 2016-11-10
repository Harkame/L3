/**
 * Louis Daviaud, L3 Informatique, Groupe C
 */

#include "TP6.h"

using namespace std;

Sommet::Sommet(valeur p_valeur)
{
    racine      = p_valeur;
    pere        = NULL;
    FGP         = false;
    fils_gauche = NULL;
    fils_droit  = NULL;
}

Sommet::Sommet(Sommet& p_sommet)
{
    racine = p_sommet.racine;
    pere   = p_sommet.pere;
    FGP    = p_sommet.FGP;
    if(p_sommet.fils_gauche != NULL && p_sommet.fils_droit == NULL)
        fils_gauche = new Sommet(*p_sommet.fils_gauche);
    else if(p_sommet.fils_gauche == NULL && p_sommet.fils_droit != NULL)
        fils_droit = new Sommet(*p_sommet.fils_droit);
    else if(!p_sommet.est_feuille())
    {
        fils_gauche = new Sommet(*p_sommet.fils_gauche);
        fils_droit  = new Sommet(*p_sommet.fils_droit);
    }
}

bool Sommet::est_feuille()
{
    return fils_gauche == NULL && fils_droit == NULL;
}

void Sommet::replace_pere(AB p_nouvelle_arborescence)
{
    p_nouvelle_arborescence->pere = pere;
    if(p_nouvelle_arborescence->pere->FGP == true)
        p_nouvelle_arborescence->pere->fils_gauche = p_nouvelle_arborescence;
    else
        p_nouvelle_arborescence->pere->fils_droit = p_nouvelle_arborescence;
    pere = NULL;
}

bool Sommet::get_FGP()
{
    return FGP;
}

AB Sommet::get_pere()
{
    return pere;
};

void Sommet::print()
{
    print_aux();
    cout << endl;
}

void Sommet::print_aux()
{
    if(est_feuille())
    {
        cout << racine << " ( ) ";
        return;
    }
    else if(fils_gauche == NULL && fils_droit != NULL)
    {
        cout << racine << " ( ";
        fils_droit->print_aux();
    }
    else if(fils_gauche != NULL && fils_droit == NULL)
    {
        cout << racine << " ( ";
        fils_gauche->print_aux();
    }
    else
    {
        cout << racine << " ( ";
        fils_gauche->print_aux();
        fils_droit->print_aux();
    }
    cout << " ) ";
}

AB Sommet::plus_petit()
{
  if(fils_gauche == NULL)
    return this;
  else
    return fils_gauche->plus_petit();
}

AB Sommet::rechercher_valeur(valeur p_valeur)
{
  if(racine == p_valeur)
    return this;
  else if(racine < p_valeur)
    return fils_gauche->rechercher_valeur(p_valeur);
  else
    return fils_droit->rechercher_valeur(p_valeur);
}

void Sommet::inserer_valeur(valeur p_valeur)
{
  if()
}

/**
 * Pour une sortie lateX, decommenter les lignes //SortieLatex(...);
 *
 * g++ -c SortieLatex.cpp -o SortieLatex; g++ TP5.cpp SortieLatex -o tp5; ./tp5;
 */
int main()
{

    return 42;
}
