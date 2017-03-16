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

#define TAILLE_MESSAGE 255
#define PORT           6666
#define IP             "127.0.0.1"

void foo(char* p_n)
{
  int d_socket;

  struct sockaddr_in sockaddr_in_client;

  d_socket = socket(AF_INET, SOCK_DGRAM , 0);

  if(d_socket == -1)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  sockaddr_in_client.sin_addr.s_addr = inet_addr(IP);
  sockaddr_in_client.sin_family      = AF_INET;
  sockaddr_in_client.sin_port        = htons(PORT);

  if(d_socket == -1)
  {
    perror("socket ");
    exit(EXIT_FAILURE);
  }

  char buffer[TAILLE_MESSAGE];
  strcpy(buffer, p_n);

  if(sendto(d_socket, buffer, strlen(buffer)
  , 0,
        (struct sockaddr*) &sockaddr_in_client, sizeof sockaddr_in_client) == -1)
  {
    perror("sendto ");
    exit(1);
  }

  close(d_socket);
}

int main(int argc , char** argv)
{
  foo(argv[1]);

  return 0;
}
