#include <stdio.h>

int factorielle(int n)
{
	if(n == 1)
		return 1;
	else
		return n * factorielle(n - 1);
}

int main()
{
	printf("%i\n", factorielle(3));
}
