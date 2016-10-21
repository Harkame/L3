#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void foo(int p_nombre_fils)
{
  int pid = getppid();
  for(int index = 0; index < p_nombre_fils; index++)
  {
    printf("Yolo : %d\r\n", index);
    if(pid == getpid())
      fork();
  }
}

int main(int argc, char** argv)
{
  foo(atoi(argv[1]));
  return 0;
}
