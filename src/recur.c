/* 


Author: Varad Ghodake
College of Engineering, Pune
2015-2019

This file is part of HTTP Wget Miniproject.

HTTP Wget is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

HTTP Wget is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Wget.  If not, see <http://www.gnu.org/licenses/>.

Additional permission under GNU GPL version 3 section 7

If you modify this program, or any covered work, by linking or
combining it with the OpenSSL project's OpenSSL library (or a
modified version of that library), containing parts covered by the
terms of the OpenSSL or SSLeay licenses, the Free Software Foundation
grants you additional permission to convey the resulting work.
Corresponding Source for a non-source form of such a combination
shall include the source code for the parts of OpenSSL used as well
as that of the covered work.  */



#include "headers.h"
#include "client.h"
#include "http.h"

int recurconn(char *host, char *page, char *file) {

	FILE *fp;
	file = (char *) malloc(sizeof(char) * 50);

	strcpy(file, page);
	strcat(file, ".html"); 
	fp = fopen(file, "w");

	fflush(fp);

	struct sockaddr_in *remote;
	int sock;
	int tmpres;
	char *ip;
	char *get;
	char buf[BUFSIZ+1];

	sock = create_tcp_socket();
	ip = get_ip(host);
	fprintf(stderr, "IP is %s\n", ip);
	remote = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *));
	remote->sin_family = AF_INET;
	tmpres = inet_pton(AF_INET, ip, (void *)(&(remote->sin_addr.s_addr)));

	if( tmpres < 0) {

		perror("Can't set remote->sin_addr.s_addr");
		exit(1);

	}else if(tmpres == 0) {
		fprintf(stderr, "%s is not a valid IP address\n", ip);
		exit(1);
	}


	remote->sin_port = htons(PORT);
     
	if(connect(sock, (struct sockaddr *)remote, sizeof(struct sockaddr)) < 0) {
		perror("Could not connect");
		exit(1);
	}

	get = build_get_query(host, page);
	fprintf(stderr, "\n%s\n", get);
     
	//Send the query to the server
	int sent = 0;
	while(sent < strlen(get)) {
		tmpres = send(sock, get+sent, strlen(get)-sent, 0);
		if(tmpres == -1){
			perror("Can't send query");
			exit(1);
	}
	sent += tmpres;
	}

      //now it is time to receive the page
	memset(buf, 0, sizeof(buf));
	int htmlstart = 0;
	char * htmlcontent;
	while((tmpres = recv(sock, buf, BUFSIZ, 0)) > 0){
		


	if(htmlstart == 0) {
          /* Under certain conditions this will not work.
          * If the \r\n\r\n part is splitted into two messages
          * it will fail to detect the beginning of HTML content
          */
		htmlcontent = strstr(buf, "\r\n\r\n");
		if(htmlcontent != NULL){
			htmlstart = 1;
			htmlcontent += 4;
		}
                }else {

        		htmlcontent = buf;
	        }
	        if(htmlstart){

			fprintf(fp, "%s", htmlcontent);

	        }
     
	        memset(buf, 0, tmpres);
	 }

	if(tmpres < 0) {
		perror("Error receiving data");
	}

	free(get);
	free(remote);
	free(ip);
	close(sock);
	fclose(fp);
	fprintf(stdout, "\nOutput is stored in %s\n", file);
	fprintf(stdout, "\t\t\t[=========================>] 100%%");


	return 0;
}
