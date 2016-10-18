#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <time.h>
#include <regex.h>


char ipstr[INET6_ADDRSTRLEN];




char* DomainToIP(char *domain);
void createFile(char *html);
