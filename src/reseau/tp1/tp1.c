#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_BUFFER 255

#define MESSAGE_EXIT "exit"

#define MESSAGE_PROMPT "> "

#define MESSAGE_AIDE_EXIT "exit pour quitter\n\n"

#define MESSAGE_ERREURE_HOST     "Hote introuvable (%s)\n\n"
#define MESSAGE_ERREURE_ADDRESSE "Famille d'IP inconnue (%d)\n\n"

#define MESSAGE_DESCRIPTION_HOTE "Hote : %s\n\n"
#define MESSAGE_DESCRIPTION_NOM  "Nom  : %s\n"
#define MESSAGE_DESCRIPTION_IPV4 "IPV4 : %s\n"
#define MESSAGE_DESCRIPTION_IPV6 "IPV6 : %s\n"

/*
* Affiche les informations (hostname, IP, nom)  pour chaque addresses de l'hote.
*/
void print_infos(char* p_host_name)
{
	struct addrinfo  addrinfo_specifications; //Specification des resultats souhaitee
	struct addrinfo* addrinfo_resultat;       //Resultat de getaddrinfo, contenant les informations sur l'hote

	/*
	* Initialization des champs addrinfo_specifications.
	* memset est utile si on ne veux pas les remplires tous a la main.
	*/
	memset(&addrinfo_specifications, 0, sizeof addrinfo_specifications); //Met tous les champs de addrinfo_specifications a 0

	addrinfo_specifications.ai_family    = AF_UNSPEC;   //N'importe qu'elle famille d'addresse (IPV4, IPV6)
	addrinfo_specifications.ai_socktype  = SOCK_STREAM; //Socket connectee uniquement (TCP)
	addrinfo_specifications.ai_protocol  = 0;           //N'importe quel protocole (TCP, UDP)
	addrinfo_specifications.ai_flags     = 0;           //Pas d'option

	if(getaddrinfo(p_host_name, NULL, &addrinfo_specifications, &addrinfo_resultat) != 0)
	{
		fprintf(stderr, MESSAGE_ERREURE_HOST, p_host_name);
		return;
	}

	struct addrinfo* sauvegarde = addrinfo_resultat; //Sauvegarde du premier maillon pour freeaddrinfo

	fprintf(stdout, MESSAGE_DESCRIPTION_HOTE, p_host_name);

	char buffer_name[TAILLE_BUFFER];
	char buffer_addresse[TAILLE_BUFFER];

	for(sauvegarde = addrinfo_resultat; addrinfo_resultat != NULL; addrinfo_resultat = addrinfo_resultat->ai_next) //Pour chacune des addresses de l'hote
	{
		if(getnameinfo(addrinfo_resultat->ai_addr, addrinfo_resultat->ai_addrlen, //Recuperation du nom
		    buffer_name, TAILLE_BUFFER, NULL, 0, AI_CANONNAME) != 0)
				return;

		fprintf(stdout, MESSAGE_DESCRIPTION_NOM, buffer_name);

		if (getnameinfo(addrinfo_resultat->ai_addr, addrinfo_resultat->ai_addrlen, //Recuperation de l'addresse
		    buffer_addresse, TAILLE_BUFFER, NULL, 0, NI_NUMERICHOST) != 0)
				return;

		switch(addrinfo_resultat->ai_family) //Selon de le type d'IP, on affichera IPV4 ou IPV6
		{
			case AF_INET :
				fprintf(stdout, MESSAGE_DESCRIPTION_IPV4, buffer_addresse);
			break;

			case AF_INET6 :
				fprintf(stdout, MESSAGE_DESCRIPTION_IPV6, buffer_addresse);
			break;

			default :
				fprintf(stderr, MESSAGE_ERREURE_ADDRESSE, addrinfo_resultat->ai_family);
				return;
		}

		fprintf(stdout, "\n");
	}

	freeaddrinfo(sauvegarde);
}

/*
* Enleve le '\n' du string en parametre (Pour la saisie clavier).
*/
void remove_LF(char* p_string)
{
    char *t_string = p_string;

    while(*p_string != '\0')
        if(*p_string != '\t' && *p_string != '\n')
            *t_string++ = *p_string++;
				else
            ++p_string;

    *t_string = '\0';
}

/*
* Fonction utilisee si aucun parametre (hostname) n'est passe.
* Demande a l'utilisateur de saisir un hostname, jusqu'a ce que
* le mot saisie soit "exit" (MAJ ignorees).
* Affiche les informations de l'hostname demande.
*/
void foo_0()
{
	fprintf(stdout, MESSAGE_AIDE_EXIT);

	char hostname[TAILLE_BUFFER];

	while(1)
	{
		fprintf(stdout, MESSAGE_PROMPT);

		fgets(hostname, TAILLE_BUFFER, stdin);

		fprintf(stdout, "\n");

		remove_LF(hostname); //Supprime le '\n' de la touche "entree"

		if(strcasecmp(hostname, MESSAGE_EXIT) == 0) //Pour quitter proprement le programme (Ignore les majuscules)
			return;

		print_infos(hostname);
	}
}

/*
* Fonction utilisee si au moins un parametre (hostname) est passe.
* Affiche les informations concernant chacun des hotes en parametres.
*/
void foo_1(int p_nombre_arguments, char** p_arguments)
{
	for(int index = 1; index < p_nombre_arguments; index++)
	{
		print_infos(p_arguments[index]);
		fprintf(stdout, "\n\n");
	}
}

/*
* 2 utilisations possibles :
* - Sans parametre    : Demarre une saisie de l'hote, affiche ses informations (boucle), jusqu'a la saisie de "exit".
* - Avec parametre(s) : Affiche les informations de chacun des hotes en parametres.
*/
int main(int argc, char** argv)
{
	switch(argc)
	{
		case 1 :
			foo_0();
		break;

		default:
			foo_1(argc, argv);
		break;
	}

	return 0;
}
