#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

void foo()
{
  int tube [2];
  int compteur = 0;

  if(pipe(tube) == -1)
    return;

  while(write(tube[1], "a", 1))
  {
      compteur++;
      printf("%d\r\n", compteur);
  }
}

int main()
{
  foo();

  return 42;
}
