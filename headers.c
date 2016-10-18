#include "headers.h"


char *DomainToIP(char *domain) {

	//Variables for IP resution
	struct addrinfo hints, *res, *p;
	int status;

	printf("Resolving URL...\n");
	unsigned int retTime = time(0) + 2;
    	while (time(0) < retTime);    


	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	//Fail Cases

	if ((status = getaddrinfo(domain, NULL, &hints, &res)) != 0) {
		printf("Null");
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        	return NULL;
    	}

    	
    	for(p = res; p != NULL; p = p->ai_next) {
        	void *addr;
        	//char *ipver;

        //Getting the pointer to the address itself
        // different fields in IPv4 and IPv6


	//Version detection ipv4 or ipv6

        	if (p->ai_family == AF_INET) {
        		struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
        		addr = &(ipv4->sin_addr);
        		//ipver = "IPv4";
 

       		} else {
        		struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
        		addr = &(ipv6->sin6_addr);
        		//ipver = "IPv6";
        }

        //converting the IP to a string

 	       inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr); 
	       return ipstr;
    }
	return NULL;

}





void createFile(char *html, char *url){

	FILE *fp;
	fp = fopen("index.html", "w");
	
	if(fp == NULL) {
		printf("Couldn't create file");
		return;
	}

	fprintf(fp, "%s", html);
	fclose(fp);
	return;
}

void Usage(){
	printf("\nUsage: ./wget [OPTION]... [URL]...\n");
	return;
}


void Options() {


	printf("-V\t--version\n");
	printf("\tShows the current version of wget\n\n");
	printf("-o [file]\t--output-file [file]\n");
	printf("\tStore HTML in a specific file\n\n");
	printf("-q\n");
	printf("\tSilence the output of wget\n\n");
	printf("-F\t--Force-HTML\n");
	printf("\tTreat every output as HTML\n\n");
	printf("-w\t--wait\n");
	printf("\tWait for sometime to relieve the server load\n\n");
	printf("-k\t--convert-links\n");
	printf("\tDownload all the links from the HTML\n\n");

}
