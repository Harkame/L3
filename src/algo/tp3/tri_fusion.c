#include <stdlib.h>
#include <stdio.h>
#include "Tri_Fusion.h"

/*
Premier appel
*/
void tri_fusion(int* p_tableau, int p_taille_tableau)
{
  if (0 < p_taille_tableau)
  {
    tri_fusion_aux(p_tableau, 0, p_taille_tableau - 1);
  }
}

/*
Appel reccursif
*/
void tri_fusion_aux(int* p_tableau, int p_debut, int p_fin)
{
  if (p_debut != p_fin)
  {
    int milieu = (p_fin + p_debut) / 2;
    tri_fusion_aux(p_tableau, p_debut, milieu);
    tri_fusion_aux(p_tableau, milieu + 1, p_fin);
    fusion(p_tableau, p_debut, milieu, p_fin);
  }
}

/*
Fusionne les tableau
*/
void fusion(int* p_tableau, int p_debut, int p_fin1, int p_fin2)
{
  int deb2 = p_fin1 + 1;

  //on recopie les éléments du début du tableau
  int table1 [p_fin1-p_debut+1];
  for(int i=p_debut;i<=p_fin1;i++)
    table1[i-p_debut]=p_tableau[i];
  int compt1 = p_debut;
  int compt2 = deb2;
  for(int index = p_debut; index <= p_fin2; index++)
  {
    if (compt1 == deb2) //c'est que tous les éléments du premier tableau ont été utilisés
    {
      break; //tous les éléments ont donc été classés
    }
    else if (compt2 == (p_fin2 + 1)) //c'est que tous les éléments du second tableau ont été utilisés
    {
      p_tableau[index] = table1[compt1 - p_debut]; //on ajoute les éléments restants du premier tableau
      compt1++;
    }
    else if (table1[compt1-p_debut] < p_tableau[compt2])
    {
      p_tableau[index]=table1[compt1 - p_debut]; //on ajoute un élément du premier tableau
      compt1++;
    }
    else
    {
      p_tableau[index]=p_tableau[compt2]; //on ajoute un élément du second tableau
      compt2++;
    }
  }
}

void aff_tableau(int* p_tableau, int p_taille_tableau)
{
  for(int index = 0; index < p_taille_tableau; index++)
    printf("%d ", p_tableau[index]);
  printf("\r\n");
}

void main()
{
  int tableau[6] = {8, 4, 6, 3, 1, 9};
  int taille_tableau = sizeof(tableau) / sizeof(int);
  aff_tableau(tableau, taille_tableau);
  tri_fusion(tableau, taille_tableau);
  aff_tableau(tableau, taille_tableau);
}
