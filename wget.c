#include "headers.c"

int main(int argc, char *argv[]){
	
	if(argc == 1) {
		printf("\nwget: missing URL\n");
		Usage();
		printf("Try './wget --help' or './wget -h' for more options\n");
		
		return 1;
	}

	if(argc == 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)){
		
		printf("\nLightweight Wget is a non-interactive network retriever.\n");		
		Usage();
		printf("Mandatory arguments to long options are mandatory for short options too.\n\n");

		return 0;
	}


	int c;
	
	extern char *optarg;
	extern int optind;
	

	while (1) {
	
		c = getopt (argc, argv, "Vko:a:qi:Fw");
		if (c == EOF)
        		break;

      		switch (c) {

        		case 'V':
          			printf("\nLightweight Wget using sockets\n");
				printf("V 0.0.1\n");
          			break;

        		case 'o':
          			printf("option o with value `%s'\n", optarg);
          			break;

        		case 'a':
          			printf("option a with value `%s'\n", optarg);
          			break;

			case 'q':
          			printf("\nQuiet mode on\n");
          			break;
			
			case 'i':
          			printf("option i with value `%s'\n", optarg);
          			break;

			case 'k':
          			
          			break;

			case 'w':
          			printf("option w\n");
          			break;


        		case '?':
          			break;

        		default:
          			printf ("getopt returned\n");
		}
	}
	
	if(argv[optind] == NULL){

		printf("\nwget: missing URL\n");
		Usage();
		printf("Try './wget --help' or './wget -h' for more options\n");
		
		return 1;	
	}

	Connect(argv[optind]);


	return 0;
}
