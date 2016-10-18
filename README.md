# Lightweight Wget using Sockets

Mini-project for DSA 2016-17

Created completely using **C Language**

###Features used

Sockets

Regex

###Usage

```
$ make
$ ./wget [options]...[url]
```

###Options planning to implement:

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

-f or --force-html

    Using this as a default case 


--backup

--spider:

    Off-line version of it

-T ot --timeout

    time.h 

--connect-timeout

    time.h
    
-w or --wait

    time.h

-V or --version

-h or --help

-t

    tag finding feature using regex

Also various directory options and possibly proxy and (HTTP-FTP options)

###Main problem

Proxy internet is the main constraint as the Connection phase is the triggering event for further options

Some of the implemented options are tested offline and they work



