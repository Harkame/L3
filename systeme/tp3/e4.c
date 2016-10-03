#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int nombre_caractere(char* p_nom_fichier)
{
	int fichier = open(p_nom_fichier, O_RDONLY);
	if(fichier == -1)
	{
		exit(1);
	}
	int occurences [256] = {0};
	char buffer [128] = "";
	int compteur = 0;
	int nread = read(fichier, buffer, 128);
    
	if(nread == -1)
		exit(1);

     	int index;
		printf("buffer : %s\r\n", buffer);
	for(index = 0; index < sizeof(buffer) / sizeof(char); index++)
	{
		if(buffer[index] >= 61 && buffer[index] <= 122)
		{		
			occurences[buffer[index]]++;
		}	
	}

	for(index = 61; index <= 122; index++)
		if(occurences[index] > 0)
			compteur++;

	return compteur;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
		exit(1);

	printf("%s : %d\r\n", argv[1], nombre_caractere(argv[1]));

	exit(0);
}
