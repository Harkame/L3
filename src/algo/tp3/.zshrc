#include <iostream>

void imprimer(int n, int T[])
{
  for(int index = 0; index < n; index++)
    std::cout << T[i] << " ";
}


void genererRandom(int n, int Max, int[] T)
{//rempli le tableau T de n nombres al�atoires, tous enttre 0 et Max
  for(int index = 0; index < n; index++)
    T[i]=rand() % (Max + 1);
}
