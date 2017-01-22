#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<getopt.h>
#include<stdlib.h>

#define TAILLE_MESSAGE 255

void* lire(int p_socket)
{
  char buffer[255];
  while(1)
  {
    recv(p_socket, buffer, TAILLE_MESSAGE, 0);
    printf("%s\n", buffer);
  }
}

void* ecrire(int p_socket)
{
  char buffer[TAILLE_MESSAGE];
  while(1)
  {
    fgets(buffer, sizeof(buffer), stdin);
    send(p_socket, buffer, strlen(buffer), 0);
  }
}

int main(int argc , char** argv)
{
  char* pseudo = malloc(255 * sizeof(char));

  if(argc < 2)
  {
    perror("Pas de pseudo");
    exit(1);
  }

  pseudo = argv[1];
  int c;

  int sock;
  struct sockaddr_in server;
  char message[1000] , server_reply[2000];

  //Create socket
  sock = socket(AF_INET , SOCK_STREAM , 0);
  if (sock == -1)
  {
    perror("socket");
    exit(1);
  }

  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons( 8888 );

  if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
  {
    perror("connect");
    exit(1);
  }

  send(sock, pseudo, strlen(pseudo), 0);

  pthread_t thread_ecrire;
  pthread_t thread_lire;

  pthread_create(&thread_ecrire , NULL ,  ecrire, sock);
  pthread_create(&thread_lire , NULL ,  lire, sock);

  pthread_join(thread_ecrire, NULL);
  pthread_join(thread_lire, NULL);

  close(sock);

  return 0;
}
