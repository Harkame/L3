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

void f1_adresse()
{
	int tab1 [taille] = {12,23,34,45,56,67,78,89,90,01};
	for(int index = 0; index < taille; index++)
		printf("%p\n", &(tab1[index]));
}

void f2_adresse()
{
	int tab2 [taille];
	for(int index = 0; index < taille; index++)
		printf("%p\n", &(tab2[index]));
}


int main()
{
	printf("--- Valeurs ---\r\n");
	printf("--- Valeurs : f1 ---\r\n");
	f1_valeur();
	printf("\r\n--- Valeurs : f2 ---\r\n");
	f2_valeur();
	printf("\r\nLes valeurs sont les memes, si pas d'instructions au milieu\r\n");
	printf("\r\n--- Adresses ---\r\n");
	printf("--- Adresses : f1 ---\r\n");
	f1_adresse();
	printf("\r\n--- Adresses : f2 ---\r\n");
	f2_adresse();
	printf("\r\nLes adresses sont les memes, la pile est reutilisee\r\n");
}
