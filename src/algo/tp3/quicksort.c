#include <stdlib.h>
#include <stdio.h>
#include "quicksort.h"

void swap(int p_tableau[], int a, int b)
{
  int temp     = p_tableau[a];
  p_tableau[a] = p_tableau[b];
  p_tableau[b] = temp;
}

void quick_sort(int p_tableau[], int p_debut, int p_fin)
{
  int gauche = p_debut - 1;
  int droite = p_fin + 1;
  const int pivot = p_tableau[p_debut];
  if(p_debut >= p_fin)
    return;
  while(1)
  {
    do droite--;
      while(p_tableau[droite] > pivot);
    do gauche++;
      while(p_tableau[gauche] < pivot);
    if(gauche < droite)
      swap(p_tableau, gauche, droite);
    else
      break;
  }
  quick_sort(p_tableau, p_debut, droite);
  quick_sort(p_tableau, droite + 1, p_fin);
}

void aff_p_p_tableau(int* p_p_p_tableau, int p_taille_p_p_tableau)
{
  for(int index = 0; index < p_taille_p_p_tableau; index++)
    printf("%d ", p_p_p_tableau[index]);
  printf("\r\n");
}

void main()
{
  int p_tableau[6] = {8, 4, 6, 3, 1, 9};
  int taille_tableau = sizeof(p_tableau) / sizeof(int);
  aff_p_p_tableau(p_tableau, taille_tableau);
  quick_sort(p_tableau,0 ,taille_tableau);
  aff_p_p_tableau(p_tableau, taille_tableau);
}
