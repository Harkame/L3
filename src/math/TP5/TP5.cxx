#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "TP5.h"

typedef int sommet;

using namespace std;

Graphe::Graphe(int p_nombre_sommets)
{
	nombre_sommets = p_nombre_sommets;

	int index = 0;

	distances = (int*)malloc(nombre_sommets * sizeof(int));
	for(index = 0; index < nombre_sommets; index++)
		distances[index] = new int[nombre_sommets];

	chemins = (int*)malloc(nombre_sommets * sizeof(int));
	for(index = 0; index < nombre_sommets; index++)
		chemins[index] = new int[nombre_sommets];
}

void Graphe::floyd_marshall()
{
	for(int i = 1; i < n; ++)
	{
		for(int j = 1; j < n; j++)
		{
			if()
		}
	}
}

int main()
{
	Graphe* graphe = new Graphe(5);

	graphe->floyd_warshall();

	return 42;
}
