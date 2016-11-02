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

void Usage(){
	fprintf(stdout, "\nUsage: ./program [OPTION]... [URL]...\n");
	fprintf(stdout, "[URL] : HTTP supported URLs only\n");
	return;
}


void Options() {


	fprintf(stdout, "-V\t--version\n");
	fprintf(stdout, "\tShows the current version of wget\n\n");
	fprintf(stdout, "-o [file]\t--output-file [file]\n");
	fprintf(stdout, "\tStore HTML in a specific file\n\n");
	fprintf(stdout, "-q\n");
	fprintf(stdout, "\tSilence the output of wget\n\n");
	fprintf(stdout, "-F\t--Force-HTML\n");
	fprintf(stdout, "\tTreat every output as HTML\n\n");
	fprintf(stdout, "-w\t--wait\n");
	fprintf(stdout, "\tWait for sometime to relieve the server load\n\n");
	fprintf(stdout, "-k\t--convert-links\n");
	fprintf(stdout, "\tDownload all the links from the HTML\n\n");

}
