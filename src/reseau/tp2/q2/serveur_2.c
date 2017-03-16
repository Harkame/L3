#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <features.h>

#define TAILLE_MESSAGE 255
#define PORT           6666

void foo()
{
  int sum = 0;
  int d_socket;
  struct sockaddr_in sockaddr_in_server;

  d_socket = socket(AF_INET, SOCK_DGRAM, 0);

  if(d_socket == -1)
  {
    perror("socket ");
    exit(EXIT_FAILURE);
  }

  sockaddr_in_server.sin_family      = AF_INET;
  sockaddr_in_server.sin_addr.s_addr = INADDR_ANY;
  sockaddr_in_server.sin_port        = htons(PORT);

  if(bind(d_socket, (struct sockaddr*) &sockaddr_in_server, sizeof(sockaddr_in_server)) < 0)
  {
    perror("bind ");
    exit(1);
  }

  char buffer[TAILLE_MESSAGE];

  socklen_t len = sizeof sockaddr_in_server;

  while(1)
    if(recvfrom(d_socket, buffer, TAILLE_MESSAGE, 0, (struct sockaddr*) &sockaddr_in_server, &len) == -1)
    {
      perror("recvfrom ");
      exit(1);
    }
    else
    {
      //sum += atoi(buffer);
      fprintf(stdout, "%s\n", buffer);
    }

  close(d_socket);
}

int main(int argc , char** argv)
{
  foo(argv[1]);

  return 0;
}
