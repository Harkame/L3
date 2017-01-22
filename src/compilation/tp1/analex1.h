/**
* @file analex.h
* @author Michel Meynard
* @brief DÃ©finition de la fon analex() qui retourne un entier positif si OK,
* 0 si fin de fichier. Le filtrage est permis gÃ¢ce aux jetons nÃ©gatifs.
*/
#include <string.h>
char lexeme[1024];		/* lexÃ¨me courant de taille maxi 1024 */
int DEBUG=0;			/* dÃ©bogage */
/**
* lit dans l'entrÃ©e standard le mot le plus long se terminant en un Ã©tat final
* de l'automate dÃ©fini par TRANS, puis retourne le JETON correspondant.
* @returns le JETON entier correspondant Ã  l'Ã©tat final de l'AFD
*/
int analex()
{			/* reconnaÃ®t un mot sur l'entrÃ©e standard */
	int  etat=EINIT;		/* unique Ã©tat initial */
	int efinal=-1;		/* pas d'Ã©tat final dÃ©jÃ  vu */
	int lfinal=0;			/* longueur du lexÃ¨me final */
	int c;char sc[2];int i;	/* caractÃ¨re courant */
	lexeme[0]='\0';		/* lexeme en var globale (pour le main)*/
		while ((c=getchar())!=EOF && TRANS[etat][c]!=-1)
		{ /* Tq on peut avancer */
			sprintf(sc,"%c",c);		/* transforme le char c en chaine sc */
			strcat(lexeme,sc);		/* concatÃ©nation */
			if (DEBUG) printf("%i -- %c --> %i ;",etat,c,TRANS[etat][c]);
				etat=TRANS[etat][c];	/* Avancer */
			if (JETON[etat])
			{		/* si Ã©tat final */
				efinal=etat;		/* s'en souvenir */
				lfinal=strlen(lexeme);	/* longueur du lexeme egalement */
			} /* fin si */
		} /* fin while */
	if (JETON[etat]){		/* Ã©tat final */
	ungetc(c,stdin);		/* rejeter le car non utilisÃ© */
	return (JETON[etat]<0 ? analex() : JETON[etat]);/* ret le jeton ou boucle*/
	}
	else if (efinal>-1){		/* on en avait vu 1 */
	ungetc(c,stdin);		/* rejeter le car non utilisÃ© */
	for(i=strlen(lexeme)-1;i>=lfinal;i--)
	ungetc(lexeme[i],stdin);	/* rejeter les car en trop */
	lexeme[lfinal]='\0';	/* voici le lexeme reconnu */
	return (JETON[efinal]<0 ? analex() : JETON[efinal]);/* ret jeton ou boucle*/
	}
	else if (strlen(lexeme)==0 && c==EOF)
	return 0;			/* cas particulier */
	else if (strlen(lexeme)==0){
	lexeme[0]=c;lexeme[1]='\0';	/* retourner (c,c) */
	return c;
	}
		else
		{
			ungetc(c,stdin);		/* rejeter le car non utilisÃ© */
			for(i=strlen(lexeme)-1;i>=1;i--)
				ungetc(lexeme[i],stdin);	/* rejeter les car en trop */
	return lexeme[0];
	}
}
