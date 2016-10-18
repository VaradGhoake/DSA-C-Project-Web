#include "headers.h"
#define MAXMATCH 20

int ConvertLinks(char *url) {

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

        /* Read in and compile a regular expression */
        /* Using extended regular expresssions */

        status = regcomp(&rgx, reginald, REG_EXTENDED);

        /* Leave program if regex is faulty */
        /* we could use regerror to decode the error ... */

        if (status) return 1;


	/*Delete this once proxy setings are done*/

	printf("\nUsing offline available HTML file \"index.html\"\n");

	fp = fopen("index.html", "r");
	char *link_start;

        char mainString[256];

	printf("\nLinks in the given html file:\n");

    	while (fgets(mainString, sizeof(mainString), fp)) {

                /* Loop until an empty line id given */

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
				printf("\t%s\n", link);




			/*Call DomainToIP and Connect here*/



                        }

                }

        /* Free up memory held within the regex memory */
        regfree(&rgx);

        return 0;

        }
