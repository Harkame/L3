#include <stdio.h>
#include <stdlib.h>

#define taille 99999999

int* tab1; //global non init
int tab2 [taille] = {1}; //global init

int main()
{
	int tab3 [taille] = {1}; //pile
	void* p1 = malloc(sizeof(int) * taille); //tas
}
