#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{
	struct stat fichier_stat;
	stat(argv[1], &fichier_stat);
	printf("%s", fichier_stat.st_mode);
	
}
