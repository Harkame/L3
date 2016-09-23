//#include "mm.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define TAILLE 4

/** Type pointeur sur une structure de jeu
 */
typedef struct mm* mm;

/** Structure de jeu contenant le mot secret ainsi que le nombre d'essais 
 * effectués
 */
struct mm
{
  char secret[TAILLE+1];  // mot secret stocké dans une chaine de char
  int nbessais;		/* nombre d'essai */
};

/**
 * Crèe un nouveau jeu en générant aléatoirement un nouveau mot secret
 * composé de TAILLE lettres comprises entre 0 et 9.
 * @return un pointeur sur le jeu créé dans le tas (donc à detruire !)
 */
struct mm mm_creer()
{
	struct mm jeu;
	for(int index = 0; index < 4; index++)
		jeu.secret[index] = (rand() % (10 - 1) + 1);
	jeu.nbessais = 0;
	return jeu;
}

/**
 * Supprime un jeu en désallouant la mémoire
 * @param mm un pointeur sur la structure de jeu
 */
void mm_detruire(mm jeu)
{
	return;
}

/**
 * teste un mot essai face au mot secret stocké dans le jeu
 * @param jeu un pointeur sur la structure de jeu
 * @param essai la chaîne de caractères proposée par le joueur humain
 * @returns un entier contenant (TAILLE+1)*nb lettres bien placées + nb lettres
 * mal placées; -1 si l'essai est erroné (nb lettres, ...)
 */
int mm_test(struct mm jeu, char* essai)
{
	printf("essai : %s\n", essai);
	int compteur_ok = 0;
	int compteur_mal_place = 0;
	for(int index = 0; index < sizeof(jeu.secret); index++)
		if(strcmp(jeu.secret[index], essai) == 0)
			compteur_ok++;
	jeu.nbessais++;
	return 1;
}

/** Retourne le nb d'essais déjà effectués 
 * @param jeu un pointeur sur la structure de jeu
 * @returns le nombre d'essais
 */
int mm_nbessais(struct mm jeu)
{
	return jeu.nbessais;
}

int main()
{
	struct mm jeu = mm_creer();
	char* test = 0;
	while(1)
	{
		fgets(test, sizeof(jeu.secret), stdin);
		mm_test(jeu, test);
	}
}
