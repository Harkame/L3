#include <stdio.h>
#include <stdlib.h>

#define taille 10

//int [] tab; //global non init
//int tab [taille] = {1}; //global init

void f1_valeur()
{
	int tab1 [taille] = {12,23,34,45,56,67,78,89,90,01};
	for(int index = 0; index < taille; index++)
		printf("%i\n", tab1[index]);
}

void f2_valeur()
{
	int tab2 [taille];
	for(int index = 0; index < taille; index++)
		printf("%i\n", tab2[index]);
}

int main()
{
	int tab1 [taille] = {12,23,34,45,56,67,78,89,90,01};
	for(int index = 0; index < taille; index++)
		printf("Valeur1 : %i | Adresse1 : %p\n", tab1[index], &(tab1[index]));

	int tab2 [taille];
	for(int index = 0; index < taille; index++)
		printf("Valeur2 : %i | Adresse2 : %p\n", tab2[index], &(tab2[index]));
	//Au lieu de "recycler" les adresses, la pile a continuer de grandire
}
