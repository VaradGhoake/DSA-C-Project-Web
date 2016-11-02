# HTTP Wget using Sockets

Mini-project for DSA 2016-17

Created completely using **C Language**

###Features used

Sockets

Regex

getopt for command line options

###Usage

```
$ make
$ ./wget [options]...[url]
```

###Options implemented:

-r:

    Most important feature of wget 
    recursive download

-k or--convert-links:

    Usage : currently -k is working
    
    Source to extract the links is in CovertLinks.c using regex
    
    Repeated calls to Connect.c and CreateHTML.c will do the job

    Finds all the links in the HTML page and downloads their code

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



###Partially implemented and commented
--proxy:

    Proxy internet is the main constraint as the Connection phase is the triggering event for further options

    Some of the implemented options are tested offline and they work
-k or--convert-links:

		Usage : currently -k is working
		Source to extract the links is in CovertLinks.c using regex
		Repeated calls to Connect.c and CreateHTML.c will do the job

		Finds all the links in the HTML page and downloads their code



	SSL:

		For HTTPS, able to download the certificates necessary



