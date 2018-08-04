#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void rm(char* p_nom_fichier)
{
	if(unlink(p_nom_fichier) < 0)
			printf("%s", strerror(errno));
}

int main(int argc, char** argv)
{
	rm(argv[1]);
}
