#include "tp1.h"

void get_infos(char* p_host_name, char* p_ip, char* p_complete_hostname)
{
	struct addrinfo* resultat;

	if(getaddrinfo(p_host_name, NULL, 0, &resultat) != 0)
	{
		fprintf(stderr, "Erreure : get_ip -> getaddrinfo\n");
		exit(EXIT_FAILURE);
	}

	char buff[TAILLE_BUFFER];
	struct addrinfo* resorig;

	getnameinfo(resultat->ai_addr, resultat->ai_addrlen,
	p_complete_hostname, TAILLE_BUFFER, NULL, 0, 0);

	/*
	* Evite un gros cast.
	*/
	struct sockaddr_in* t_sockaddr_in = (struct sockaddr_in*) resultat->ai_addr;
	struct in_addr t_in_addr = t_sockaddr_in->sin_addr;

	printf("Port : %d\n", ntohs(t_sockaddr_in->sin_port));
	strcpy(p_ip, inet_ntoa(t_in_addr));
}

void foo_1(char* p_host_name)
{
	char ip [TAILLE_BUFFER];
	char complete_hostname[TAILLE_BUFFER];

	get_infos(p_host_name, ip, complete_hostname);

	fprintf(stdout, "Hostname            : %s\n", p_host_name);
	fprintf(stdout, "Complete Hostname   : %s\n", complete_hostname);
	fprintf(stdout, "IP                  : %s\n", ip);
}

int main(int argc, char** argv)
{

	switch(argc)
	{
		case 1 :
			exit(1);

		default:
			foo_1(argv[1]);
		break;
	}

	return 0;
}
