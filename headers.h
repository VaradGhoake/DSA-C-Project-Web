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



void Usage();
char* DomainToIP(char *);
void createFile(char *, char *);
int getopt (int, char **, char *);
void Connect(char *);
int ConvertLinks(char *);