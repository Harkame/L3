#include "mm.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/** Fonction principale de la version console du jeu Mastermind
 */

mm mm_creer()
{
	mm new = (mm) malloc(sizeof(mm));
	for(int index = 0; index < TAILLE; index++)
		new->secret[index] = rand() % 9 + '0';
	new->nbessais = 0;
	return (mm) new;
}

void mm_detruire(mm jeu)
{
	free(jeu);
}

int mm_test(mm jeu, char* essai)
{
	int compteur = 0;
	if(strlen(essai) != TAILLE)
		return -1;
	else
	{
		int compteur = 0;
		for(int index = 0; index < TAILLE; index++)
			if(jeu->secret[index] == essai[index])
				compteur++;

		for(int i = 0; i < TAILLE; i++)
			for(int j = 0; j < TAILLE; j++)
				if(jeu->secret[j] == essai[i] &&
				i != j)
				compteur++;
	}
	return compteur;
}

int mm_nbessais(mm jeu)
{
	return 1; //jeu->nbessais;
}

int main()
{
// printf("taillé"e mm : %d; taille struct mm : %d\n", sizeof(mm), sizeof(struct mm));
	mm j = mm_creer();		// printf("%s\n",j->secret);
	char saisie[1024];
	int res, CONTINUER=1;
	printf("Jeu a :  %d chiffres [0-9]\r\n", TAILLE);
	do
	{
		printf("? : ");
		scanf("%s",saisie);
		res=mm_test(j,saisie);
		if (res==-1)
			printf("Erreur de saisie !\n");
		else if (res==0)
			printf("Aucune lettre correcte !\n");
		else
		{
			printf("%d lettres bien placées, %d lettres mal placées !\n", res/(TAILLE+1),res%(TAILLE+1));
			if(res/(TAILLE+1)==TAILLE)
			{
				printf("BRAVO ! Vous avez réussi en %d  essais !\n",mm_nbessais(j));
				CONTINUER=0;
			}
		}
	}
	while(CONTINUER);
	exit(0);
}
