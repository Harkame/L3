#include <string.h>

char lexeme[1024];		/* lexème courant de taille maxi 1024 */
int DEBUG = 0;			/* débogage */

/**
* lit dans l'entrée standard le mot le plus long se terminant en un état final
* de l'automate défini par TRANS, puis retourne le JETON correspondant.
* @returns le JETON entier correspondant à l'état final de l'AFD
*/
int analex()
{			/* reconnaît un mot sur l'entrée standard */
	int etat   = EINIT;		/* unique état initial */
	int efinal = -1;		/* pas d'état final déjà vu */
	int lfinal = 0;			/* longueur du lexème final */
	int c;
	char sc[2];
	int i;	/* caractère courant */

	lexeme[0]='\0';		/* lexeme en var globale (pour le main)*/

	while ((c = getchar()) != EOF && TRANS[etat][c] != -1)
	{
		sprintf(sc,"%c",c);		/* transforme le char c en chaine sc */
		strcat(lexeme,sc);		/* concaténation */

		//if(DEBUG)
			printf("%i -- %c --> %i ;", etat, c, TRANS[etat][c]);

		etat = TRANS[etat][c];	/* Avancer */

		if(JETON[etat])
		{		/* si état final */
			efinal = etat;		/* s'en souvenir */
			lfinal = strlen(lexeme);	/* longueur du lexeme egalement */
		}
	}

	if(JETON[etat])
	{
		ungetc(c,stdin);		/* rejeter le car non utilisé */
		return (JETON[etat] < 0 ? analex() : JETON[etat]);/* ret le jeton ou boucle*/
	}
	else if (efinal > -1)
	{		/* on en avait vu 1 */
		ungetc(c,stdin);		/* rejeter le car non utilisé */

		for(i = strlen(lexeme) - 1; i >= lfinal; i--)
			ungetc(lexeme[i],stdin);	/* rejeter les car en trop */

		lexeme[lfinal] = '\0';	/* voici le lexeme reconnu */

		return (JETON[efinal] < 0 ? analex() : JETON[efinal]);/* ret jeton ou boucle*/
	}
	else if(strlen(lexeme) == 0 && c == EOF)
		return 0;			/* cas particulier */
	else if(strlen(lexeme) == 0)
	{
		lexeme[0] = c;
		lexeme[1] = '\0';	/* retourner (c,c) */
		return c;
	}
	else
	{
		ungetc(c,stdin);		/* rejeter le car non utilisé */

		for(i=strlen(lexeme) - 1; i >= 1; i--)
			ungetc(lexeme[i],stdin);	/* rejeter les car en trop */

			return lexeme[0];
	}
}
