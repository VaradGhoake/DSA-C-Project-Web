#include "headers.c"

int Connect(char *URL);

int main(int argc, char *argv[]){
	
	if(argc == 1){
		printf("\nwget: missing URL\n");
		printf("\nUsage: ./wget [OPTION]... [URL]...\n");
		printf("Try './wget --help' or './wget -h' for more options\n");

		return 1;
	}

	if(argc == 2 && (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)){
		
		printf("\nWget is a non-interactive network retriever.\n");		
		printf("\nUsage: ./wget [OPTION]... [URL]...\n");
		printf("Mandatory arguments to long options are mandatory for short options too.\n\n");

		return 0;
	}

	Connect(argv[1]);


	return 0;
}
