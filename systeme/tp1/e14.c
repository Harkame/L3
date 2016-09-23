#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define stringa "TestYolo - Test"
#define stringb "Yol"

int main(int argc, char** argv)
{
	char* buf;
	char* current_path;

	long size = pathconf(".", _PC_PATH_MAX);

	if ((buf = (char *)malloc((size_t)size)) != NULL)
	    current_path = getcwd(buf, (size_t)size);
	
	char* path = argv[1];
	printf("PATH : %s\n", path);
	char* cutted_path = strstr(path, current_path);
	if(cutted_path == NULL)
	{
		printf("CUTTED PATH : %s\n", cutted_path);
		printf("--- NOPE. ---\n");	
		exit(1);
	}
	else
	{	
		printf("CUTTED PATH : %s\n", cutted_path);
		printf("--- YEP. ---\n");
		exit(0);	
	}
}
