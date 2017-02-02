#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

void foo()
{
  int sock;
  struct addrinfo hints,*res;
  struct sockaddr_in *addr;
  int n;
  int err;
  struct in_addr in;

  char* name = "p1";

  memset(&hints,0,sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;

  err = getaddrinfo(name, NULL,&hints,&res);

  addr = (struct sockaddr_in *)res->ai_addr;
  in = addr->sin_addr;

  fprintf(stdout, "IP : %s\n",inet_ntoa(in));

  freeaddrinfo(res);
}

int main(int argc, char** argv)
{
  foo();

  return 0;
}
