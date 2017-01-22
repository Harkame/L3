#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

int nombre_connexions = 0;
pthread_t* threads;
int*  sockets;
char** pseudos;

void* connection_handler(int p_numero)
{
  nombre_connexions++;

  int sock = sockets[p_numero];
  int read_size;

  char entete[255];
  char message[255];
  char message_recu[255];

  strcpy(entete, pseudos[p_numero]);
  strcat(entete, " : ");

  while((read_size = recv(sock, message_recu, 255, 0)) > 0 )
  {
    strcpy(message, entete);
    strcat(message, message_recu);

    for(int index = 0; index < nombre_connexions; index++)
      send(sockets[index], message ,strlen(message), 0);
  }

  switch(read_size)
  {
    case 0:
      perror("Connexion perdu");
    break;
    case -1:
      perror("recv");
    break;
  }

//  for(int index = 0; index < nombre_connexions; index++)
  //  free(sockets[index]);

  return 0;
}

int main(int argc , char *argv[])
{
  sockets = malloc(255 * sizeof(int));
  pseudos = malloc(255 * sizeof(char));
  threads = malloc(255 * sizeof(pthread_t));

  for(int index = 0; index < 255; index++)
  pseudos[index] = malloc(255 * sizeof(char));

  int socket_desc , new_socket , c , *new_sock;
  struct sockaddr_in server , client;
  char *message;

  //Create socket
  socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  if (socket_desc == -1)
  {
  printf("Could not create socket");
  }

  //Prepare the sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8888);

  //Bind
  if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
  {
    perror("bind");
    exit(1);
  }

  listen(socket_desc , 3);

  c = sizeof(struct sockaddr_in);
  while((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)))
  {
    puts("Nouvelle connexion");

    recv(new_socket, pseudos[nombre_connexions], 255, 0);

    pthread_t sniffer_thread;

    new_sock = malloc(1);
    *new_sock = new_socket;

    //sockets[nombre_connexions] = new_socket;
    sniffer_thread = new_socket;

    if(pthread_create(&sniffer_thread, NULL, connection_handler, nombre_connexions) < 0)
    {
      perror("pthread_create");
      exit(1);
    }

    pthread_join(sniffer_thread, NULL);
  }

    if (new_socket < 0)
    {
      perror("accept");
      exit(1);
    }
    return 0;
}
