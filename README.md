# Lightweight Wget using Sockets

Mini-project for DSA 2016-17

Created completely using **C Language**

###Requirements

Linux OS

GCC compiler

###Usage

```
make
./wget [options]...[url]
```

###Options planning to implement:

--convert-links:

    Finds all the links in the HTML page and downloads their code

-o or --output-file

-a or --append-output

-q or --quiet

-i or --input-file

-f or --force-html

-o or --output-document

--backup

--spider:

    Off-line version of it

-T ot --timeout

--connect-timeout

-w or --wait

-v or --version

-h or --help

Also various directory options and possibly proxy and (HTTP-FTP options)

###Main problem

Proxy internet is the main constraint as the Connection phase is the triggering event for further options

Some of the implemented options are tested offline



