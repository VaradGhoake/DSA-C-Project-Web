#include "headers.h"
#include "DomainToIP.c"


void Connect(char *url){

	printf("URL : %s\n", url);

	int socket_desc;
	struct sockaddr_in server;
	char *message , server_reply[2000];
	char *ip;
     
	/***************************************************Creating a socket *****************************************************/



	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) {
        	printf("Could not create socket");
	}
        


	/****************************************************Aquiring IP Address**********************************************/

	ip = DomainToIP( url);

	printf("URL Resolved\n");

	printf("Connecting to : %s\n", ip);
	

	/********************************************************************************************************************/



	server.sin_addr.s_addr = inet_addr(ip);
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );
 
  
	/*****************************************************Connecting to a remote server***********************************************/


	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0){
		puts("connect error");
        	return;
    	}
     
 	// puts("Connected\n");
     


	/***************************************************Sending data ***************************************************************/


	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(socket_desc , message , strlen(message) , 0) < 0) {
        	puts("Send failed");
        	return;
    	}
	// puts("Data Send\n");

     
	/***************************************************Receiving a reply from the server*****************************************/

	if( recv(socket_desc, server_reply , 2000 , 0) < 0) {
        	puts("recv failed");
    	}
	// puts("Reply received\n");
	//createFile(server_reply);
     
	//   return 0;
}


/*
//Testing
int main(){
	Connect("www.google.com");

}
*/
