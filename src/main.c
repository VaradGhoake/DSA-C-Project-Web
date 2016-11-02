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

int main(int argc, char *argv[]){
	
	if(argc == 1) {
		fprintf( stdout, "\nwget: missing URL\n");
		Usage();
		fprintf( stdout, "Try './wget --help' or './wget -h' for more options\n");
		
		return 1;
	}

	if(argc == 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)){
		
		fprintf( stdout, "\nLightweight Wget is a non-interactive network retriever.\n");		
		Usage();
		fprintf( stdout, "Mandatory arguments to long options are mandatory for short options too.\n\n");
		Options();


		return 0;
	}


	char *o_file = (char *)malloc(sizeof(char) * 20);
	o_file = NULL;

	int c;
	
	extern char *optarg;
	extern int optind;
	
	o_option = 0;
	k_option = 0;
	q_option = 0;
	r_option = 0;

	while (1) {
	
		c = getopt (argc, argv, "Vrko:a:qi:Fw");
		if (c == EOF)
        		break;

      		switch (c) {

        		case 'V':
          			fprintf( stdout, "\nLightweight Wget using sockets\n");
				fprintf( stdout, "V 0.0.1\n");
          			break;

        		case 'o':
				o_option = 1;
				strcpy(o_file, optarg);
          			//fprintf( stdout, "option o with value `%s'\n", optarg);
          			break;

        		case 'a':
          			fprintf( stdout, "option a with value `%s'\n", optarg);
          			break;

			case 'q':
				q_option = 1;
          			//fprintf( stdout, "\nQuiet mode on\n");
          			break;
			
			case 'i':
          			fprintf( stdout, "option i with value `%s'\n", optarg);
          			break;

			case 'k':
          			k_option = 1;
          			break;

			case 'r':
          			r_option = 1;
          			break;

			case 'w':
          			fprintf( stdout, "option w\n");
          			break;


        		case '?':
          			break;

        		default:
          			printf ("getopt returned\n");
		}
	}
	
	if(argv[optind] == NULL){

		fprintf( stdout, "\nwget: missing URL\n");
		Usage();
		fprintf( stdout, "Try './program --help' or './program -h' for more options\n");
		
		return 1;	
	}

	connection(argv[optind], NULL, o_file);


	return 0;
}
