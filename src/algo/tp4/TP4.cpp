/* Daviaud Louis, groupe C */

#include <stdio.h>
#include <stdlib.h>
#include "TP4.h"
#include <iostream>

using namespace std;

ArbreComplet::ArbreComplet(int p_nombre_maximal_sommet)
{
  indice_premier_sommet_libre = 1;
  nombre_maximal_sommets      = p_nombre_maximal_sommet;
  contenu = new int[nombre_maximal_sommets];//(int*)malloc(nombre_maximal_sommetfs * sizeof(int)); //Pas de case 0
}

void ArbreComplet::add(valeur p_valeur)
{
  if (indice_premier_sommet_libre <= nombre_maximal_sommets)
  {
    contenu[indice_premier_sommet_libre] = p_valeur;
    indice_premier_sommet_libre++;
  }
}

void ArbreComplet::remove(indice p_sommet)
{
  if(1 <= p_sommet && p_sommet < indice_premier_sommet_libre)
  {
    contenu[p_sommet] = contenu[indice_premier_sommet_libre - 1];
    indice_premier_sommet_libre--;
  }
}

indice ArbreComplet::racine()
{
  return 1;
}

valeur ArbreComplet::getValeur(indice p_sommet)
{
  return contenu[p_sommet];
}

void ArbreComplet::setValeur(indice p_sommet, valeur p_valeur)
{
  contenu[p_sommet] = p_valeur;
}

indice ArbreComplet::pere(indice p_sommet)
{
  if(p_sommet == racine())
  return p_sommet;
  return p_sommet / 2;
}

bool ArbreComplet::possedeFilsDroit(indice p_sommet)
{
  return (p_sommet * 2) < dernierSommet();
}

bool ArbreComplet::possedeFilsGauche(indice p_sommet)
{
  return (p_sommet * 2 + 1) < dernierSommet();
}

indice ArbreComplet::filsGauche(indice p_sommet)
{
  return p_sommet * 2;
}

indice ArbreComplet::filsDroit(indice p_sommet)
{
  return p_sommet * 2 + 1;
}

indice ArbreComplet::filsMin(indice p_sommet)
{
  if(!possedeFilsGauche(p_sommet) && !possedeFilsDroit(p_sommet))
    return p_sommet;
  else if(!possedeFilsDroit(p_sommet) && (getValeur(filsGauche(p_sommet) < getValeur(p_sommet))))
    return filsGauche(p_sommet);
  else if(getValeur(filsGauche(p_sommet)) <= getValeur(filsDroit(p_sommet)))
    return filsGauche(p_sommet);
  else if(getValeur(filsDroit(p_sommet)) < getValeur(filsGauche(p_sommet)))
    return filsDroit(p_sommet);
  else
    return p_sommet;
}

indice ArbreComplet::dernierSommet()
{
  return indice_premier_sommet_libre - 1;
}

int ArbreComplet::taille()
{
  return indice_premier_sommet_libre;
}

void ArbreComplet::print()
{
  for(int index = 1; index < indice_premier_sommet_libre; index++)
    cout << contenu[index] << " ";
    cout << endl;
}

void ArbreComplet::deleteAll()
{
  delete contenu;
}

Tas::Tas(int p_nombre_maximal_sommet) : ArbreComplet(p_nombre_maximal_sommet)
{

}

void Tas::add(valeur p_valeur)
{
  ArbreComplet::add(p_valeur);
  remonter(dernierSommet());
}

void Tas::remove(indice p_indice)
{
  ArbreComplet::remove(p_indice);
  descendre(p_indice);
}

void Tas::removeDetails(indice p_indice)
{
  ArbreComplet::remove(p_indice);
  descendreDetails(p_indice);
}

void Tas::remonter(indice p_indice)
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

void Tas::descendre(indice p_indice)
{
  indice fils_min = filsMin(p_indice);
  if(fils_min == p_indice)
    return;
  else
  {
    valeur temp = getValeur(fils_min);
    setValeur(fils_min, getValeur(p_indice));
    setValeur(p_indice, temp);
    descendre(fils_min);
  }
}

void Tas::descendreDetails(indice p_indice)
{
  indice fils_min = filsMin(p_indice);
  if(fils_min == p_indice)
  {
    cout << "   [Descendre] " << endl;
    cout << "      Pas de fils plus petit" << endl;
    return;
  }
  else
  {
    valeur temp = getValeur(fils_min);
    cout << "   [Descendre] " << endl;
    cout << "      " << getValeur(p_indice) << " <--> " << temp << endl;
    setValeur(fils_min, getValeur(p_indice));
    setValeur(p_indice, temp);
    descendreDetails(fils_min);
  }
}

valeur Tas::retirerMin()
{
  valeur valeur_racine = getValeur(racine());
  remove(racine());
  return valeur_racine;
}

valeur Tas::retirerMinDetails()
{
  valeur valeur_racine = getValeur(racine());
  cout << "   [retirerMin]" << endl;
  cout << "      Retirer minimum : " << valeur_racine << endl;
  cout << "      Remplacer par :" << getValeur(dernierSommet()) << endl;
  removeDetails(racine());
  return valeur_racine;
}

void Tas::print()
{
  ArbreComplet::print();
}

int Tas::taille()
{
  return ArbreComplet::taille();
}

int* Tas::triParTas()
{
  int* tableau_trie = new int[taille()];
  int taille_tas = taille();
  for(int index = 0; index < taille_tas; index++)
  {
    tableau_trie[index] = retirerMin();
  }
  return tableau_trie;
}

int* Tas::triParTasDetails()
{
  int* tableau_trie = new int[taille()];
  int taille_tas = taille() - 1;
  for(int index = 0; index < taille_tas; index++)
  {
    cout << endl << "[Iteration : " << index << "]" << endl;
    cout << "   Tas : ";
    print();
    cout << "   Minimum : " << getValeur(1) << endl;
    tableau_trie[index] = retirerMinDetails();
    print_tableau(tableau_trie, index + 1);
  }
  return tableau_trie;
}

void Tas::remplireRandom()
{
  for(int index = 0; index < tailleMax(); index++)
    add(rand() % 10000);
}

void Tas::add(int* p_tableau, int p_taille_tableau)
{
  for(int index = 0; index < p_taille_tableau; index++)
    add(p_tableau[index]);
}

void Tas::deleteAll()
{
  ArbreComplet::deleteAll();
}

void print_tableau(int* p_tableau, int p_taille)
{
  cout << "Tableau trie" << endl;
  for(int index = 0; index < p_taille; index++)
    cout << p_tableau[index] << " ";
  cout << endl;
}


int main()
{
  /*
  //Test sur un arbre
  ArbreComplet arbre_complet(5);
  arbre_complet.add(42);
  arbre_complet.add(12);
  arbre_complet.add(13);
  arbre_complet.add(5);
  arbre_complet.add(1);
  arbre_complet.print();
  arbre_complet.remove(1);
  arbre_complet.print();;
  arbre_complet.deleteAll();
  */

  /*
  //Test sur un tas
  Tas tas(20);
  tas.add(41);
  tas.add(3);
  tas.add(13);
  tas.add(7);
  tas.add(59);
  tas.add(26);
  tas.add(99);
  tas.add(2);
  tas.add(1);
  tas.print();
  tas.retirerMin();
  tas.print();
  */

  /*
  //triParTasDetails
  cout << endl << "--- triParTasDetails ---" << endl;
  int tableau [10]{26, 12, 99, 55, 78, 2, 9, 8, 13, 42};
  Tas tas(20);
  tas.add(tableau, sizeof(tableau) / sizeof(int));
  int* tableau_trie = tas.triParTasDetails();
  delete tableau_trie;
  tas.deleteAll();
  */

  /*
  //Taille a partir de laquelle on sent un ralentissement (environ)
  int nombre_maximal_sommets = 1000000; //Gros ralentissements a partire de 10000000
  Tas tas(nombre_maximal_sommets);
  cout << "--- triparTas ---" << endl;
  tas.remplireRandom();
  int* tableau_trie = tas.triParTas();
  free(tableau_trie);
  cout << "Tri fini : avec " << nombre_maximal_sommets << " sommets" << endl;
  tas.deleteAll();
  */

  return 0;
}
