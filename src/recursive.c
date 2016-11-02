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
#include "recursive.h"
#include "recur.c"

//Links are sometimes "//link", extracting them

char *clean_link(char *link) {

	if (link[0] == '/' && link[1] == '/')
		memmove(link, link+2, strlen(link));

	if (link[0] == '/') 
		memmove(link, link+1, strlen(link));
	return link;
	
}





void recursive(char *host) {
	
		// regex pattern to match the "<a href" tag
        char reginald[] = "<a href=\"[A-Z1-9a-z/.]+\"";
	
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
			link_start = strstr(href, "\"");
			link_start++;
			i = 0;

			while(*(link_start) != '"'){

					link[i] = *link_start;
					link_start++;
					i++;
				}

				link[i] = '\0';
				strcpy(link, clean_link(link));
				printf("\t%s\n", link);


				recurconn(host, link, NULL);


                        }

                }

        // Free up memory held within the regex memory
        regfree(&rgx);

        return;


}
