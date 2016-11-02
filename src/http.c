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

int create_tcp_socket() {
      int sock;
      if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
		perror("Can't create TCP socket");
		exit(1);
      }
      return sock;
}
     
     
char *get_ip(char *host) {

        struct hostent *hent;
        int iplen = 15; //XXX.XXX.XXX.XXX
        char *ip = (char *)malloc(iplen+1);
        memset(ip, 0, iplen+1);

        if((hent = gethostbyname(host)) == NULL) {
		herror("Can't get IP");
		exit(1);
        }

        if(inet_ntop(AF_INET, (void *)hent->h_addr_list[0], ip, iplen) == NULL) {
		perror("Can't resolve host");
		exit(1);
        }
	return ip;
}
     
char *build_get_query(char *host, char *page) {
	char *query;
        char *getpage = page;
        char *tpl = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
        if(getpage[0] == '/'){
        	getpage = getpage + 1;
        	//fprintf(stderr,"Removing leading \"/\", converting %s to %s\n", page, getpage);
        }
        // -5 is to consider the %s %s %s in tpl and the ending \0
        query = (char *)malloc(strlen(host)+strlen(getpage)+strlen(USERAGENT)+strlen(tpl)-5);
        sprintf(query, tpl, getpage, host, USERAGENT);
        return query;
}
