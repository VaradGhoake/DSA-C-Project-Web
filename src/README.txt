Title : HTTP Wget in C
Name  : Varad Ghodake
MIS   : 111503022


Description:

Wget is an non-interactive network downloader

Features used:
	Sockets
	Regex
	getopt for command line options

Usage:

	$ make
	$ ./program [options]...[url]

Options implemented:

	-r :
		recursive download
		finds the links in the page and downloads them

	-o or --output-file:

		CreateHTML call after server response is received

	-a or --append-output

	-q or --quiet

		Create a global variable and use it as a flag before every output 

	-i or --input-file

	-F or --force-html

		Using this as a default case 
	
	-V or --version

	-h or --help


Partially implemented and hence commented out:
	-k or--convert-links:

		Usage : currently -k is working
		Source to extract the links is in CovertLinks.c using regex
		Repeated calls to Connect.c and CreateHTML.c will do the job

		Finds all the links in the HTML page and downloads their code

		See:
			css.c & css.h



	SSL:

		For HTTPS, able to download the certificates necessary


		See:
			ssl_client.c


