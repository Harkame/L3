#include <stdio.h>

char* s;

void g()
{
	printf("%c\n", s[0]);
}

void f()
{
	g();
}

int main()
{
	f();
}
