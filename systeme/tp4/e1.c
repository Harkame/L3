#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
  printf("PID : %d\r\nPPID : %d\r\n   ---   \r\n", getpid(), getppid());
  fork();
  printf("PID : %d\r\nPPID : %d\r\n   ---   \r\n", getpid(), getppid());
}
