#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef int indice;
typedef int valeur;

class ArbreComplet
{
  private:
    indice indice_premier_sommet_libre;
    int nombre_maximal_sommets;
    valeur contenu [];

  public:
    ArbreComplet(int p_nombre_maximal_sommet)
    {
      indice_premier_sommet_libre = 1;
      nombre_maximal_sommets = p_nombre_maximal_sommet;
      contenu [nombre_maximal_sommets + 1]; //Pas de case 0
    }

    void add(valeur p_valeur)
    {
      if (indice_premier_sommet_libre <= nombre_maximal_sommets)
      {
        contenu[indice_premier_sommet_libre] = p_valeur;
        indice_premier_sommet_libre++;
      }
    }

    void remove(indice p_sommet)
    {
      if(0 <= p_sommet && p_sommet <= indice_premier_sommet_libre)
      {
        contenu[p_sommet] = contenu[indice_premier_sommet_libre - 1];
        indice_premier_sommet_libre--;
      }
    }

    valeur racine()
    {
      return contenu[1];
    }

    valeur getValeur(indice p_sommet)
    {
      return contenu[p_sommet];
    }

    void setValeur(indice p_sommet, valeur p_valeur)
    {
      contenu[p_sommet] = p_valeur;
    }

    indice pere(indice p_sommet)
    {
      return contenu[p_sommet / 2];
    }

    indice filsGauche(indice p_sommet)
    {
      return contenu[p_sommet * 2];
    }

    indice filsDroit(indice p_sommet)
    {
      return contenu[p_sommet * 2 + 1];
    }

    bool possedeFilsDroit(indice p_sommet)
    {
      return (p_sommet * 2 <= nombre_maximal_sommets);
    }

    bool possedeFilsGauche(indice p_sommet)
    {
      return ((p_sommet * 2 + 1) <= nombre_maximal_sommets);
    }

    void print()
    {
      printf("\r\n");
      for(int index = 1; index < indice_premier_sommet_libre; index++)
        printf("%d ", contenu[index]);
      printf("\r\n\r\n");
    }
};

class Tas : ArbreComplet
{
  private:

  public:
    void add(valeur p_valeur)
    {

    }

    void remove(indice p_indice)
    {

    }

    void remonter(indice p_indice)
    {
      if(getValeur(pere(p_indice)) <= getValeur(p_indice))
        return;
      else
      {
        valeur temp = getValeur(pere(p_indice));
        setValeur(pere(p_indice), getValeur(p_indice));
        setValeur(p_indice, temp);
        remonter(pere(p_indice));
      }
    }

    void descendre(indice p_indice)
    {

    }

    void retirerMin()
    {

    }
};

int main()
{
  ArbreComplet arbre_parfait(5);
  arbre_parfait.add(42);
  arbre_parfait.add(12);
  arbre_parfait.add(13);
  arbre_parfait.add(5);
  arbre_parfait.print();
  arbre_parfait.remove(1);
  arbre_parfait.print();
  Tas tas(5);
  return 0;
}
