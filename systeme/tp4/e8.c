#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void copie(char* p_source, char* p_destination)
{
	int fichier_source 			= open(p_source, O_RDONLY);
	int fichier_destination = open(p_destination, O_CREAT | O_WRONLY);

	char buffer [128] = "";
	int nread = read(fichier_source, buffer, 128);

	if(nread == -1)
		exit(1);

	while(nread > 0)
	{
		write(fichier_destination, buffer, 128);
		nread = read(fichier_source, buffer, 128);
	}
	close(fichier_source);
	close(fichier_destination);
}

int main(int argc, char* argv[])
{
	copie(argv[1], argv[2]);
}
