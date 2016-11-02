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




#define MAXMATCH 20
#include "css.h"

void get_css(char *host) {
	

	// regex pattern to match the "<a href" tag
        char reginald[] = "<link rel=\"stylesheet\" href=\"[a-zA-Z0-9./?=]+\"";
	
	// Variable declarations 
        regex_t rgx;
	char href[100];     /*Holds entire tag*/
	char link[81];	    /*Holds the link*/

        regmatch_t matches[MAXMATCH]; /* Array of matches */
        int status;
        int i;
        FILE *fp;

        // Read in and compile a regular expression 
        // Using extended regular expresssions 

        status = regcomp(&rgx, reginald, REG_EXTENDED);

        // Leave program if regex is faulty 
        // we could use regerror to decode the error ... 

        if (status) return;


	//Delete this once proxy setings are done

	fp = fopen("index.html", "r");
	char *link_start;

        char mainString[256];

    	while (fgets(mainString, sizeof(mainString), fp)) {

                // Loop until an empty line id given

                mainString[strlen(mainString) - 1] = '\0';
                if (strlen(mainString) < 1) continue;

                status = regexec(&rgx, mainString, MAXMATCH, matches, 0);

                if (status == 0) {

			//Copying the match to href
			strcpy(href, mainString + matches[0].rm_so);
			href[strlen(href)] = '\0';

			//Finding the link
			link_start = strstr(href, "//");

			link_start++;
			i = 0;

			while(*(link_start) != '"'){

					link[i] = *link_start;
					link_start++;
					i++;
				}

				link[i] = '\0';
				strcpy(link, clean_link(link));
				//printf("\t%s\n", link);
			CSS *css = CSS_retrieve(link);
			//recurconn(css -> host, css -> page, NULL);
			
			//Call DomainToIP and Connect here
			downloadcss(css -> host, css -> page, NULL);


                        }

                }

        // Free up memory held within the regex memory
        regfree(&rgx);
	get_css1(host);
        return;

  


}




void get_css1(char *host) {
	

	// regex pattern to match the "<a href" tag
        char reginald[] = "<link rel=\"stylesheet\" type=\"text/css\" href=\"[a-zA-Z0-9./?=]+\"";
	
	// Variable declarations 
        regex_t rgx;
	char href[100];     /*Holds entire tag*/
	char link[81];	    /*Holds the link*/

        regmatch_t matches[MAXMATCH]; /* Array of matches */
        int status;
        int i;
        FILE *fp;

        // Read in and compile a regular expression 
        // Using extended regular expresssions 

        status = regcomp(&rgx, reginald, REG_EXTENDED);

        // Leave program if regex is faulty 
        // we could use regerror to decode the error ... 

        if (status) return;


	//Delete this once proxy setings are done

	fp = fopen("index.html", "r");
	char *link_start;

        char mainString[256];


    	while (fgets(mainString, sizeof(mainString), fp)) {

                // Loop until an empty line id given

                mainString[strlen(mainString) - 1] = '\0';
                if (strlen(mainString) < 1) continue;

                status = regexec(&rgx, mainString, MAXMATCH, matches, 0);

                if (status == 0) {

			//Copying the match to href
			strcpy(href, mainString + matches[0].rm_so);
			href[strlen(href)] = '\0';

			//Finding the link
			link_start = strstr(href, "//");

			link_start++;
			i = 0;

			while(*(link_start) != '"'){

					link[i] = *link_start;
					link_start++;
					i++;
				}

				link[i] = '\0';
				strcpy(link, clean_link(link));
				//printf("\t%s\n", link);
				CSS *css = CSS_retrieve(link);
				//recurconn(css -> host, css -> page, NULL); 

			//Call DomainToIP and Connect here

				downloadcss(css -> host, css -> page, NULL);

                        }

                }

        // Free up memory held within the regex memory
        regfree(&rgx);
        return;

  
}

int downloadcss(char *host, char *page, char *file) {

	FILE *fp;
	file = (char *) malloc(sizeof(char) * 50);

	strcpy(file, page); 
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
	fprintf(stderr, "Query is:\n<<START>>\n%s<<END>>\n", get);
     
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


CSS *CSS_retrieve (char *link) {

	CSS *css = (CSS *)malloc(sizeof(CSS));
	css -> host = (char *)malloc(sizeof(char) * 30);
	css -> page = (char *)malloc(sizeof(char) * 50);
	int i = 0;

	while(*link != '/') {
		(css -> host)[i] = *link;
		i++;
		link++;
	}
	(css -> host)[i] = '\0';
	i = 0;

	printf("\n%s\n", css -> host);

	while(*link != '\0'){
		(css -> page)[i] = *link;
		i++;
		link++;
	}
	(css -> page)[i]  = '\0';

	//

	strcpy(css -> page, clean_link(css -> page));

	printf("%s\n", css -> page);

	return css;
}
