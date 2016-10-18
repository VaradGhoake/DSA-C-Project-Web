#include "headers.h"

void Connect(char *url){

	if(!q_option)	
		printf("URL : %s\n", url);

	//Variables sockets library
	int socket_desc;
	struct sockaddr_in server;
	char *message , server_reply[2000];

	//IP variable
	char *ip;
     	ip = NULL;

	//Creating a socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) {
		if(!q_option)
        		printf("Could not create socket");
	}
        
	//Aquiring IP Address
	ip = DomainToIP( url);

	if(ip == NULL){
		return;
	}
	if(!q_option){
		printf("URL Resolved\n");
		printf("Connecting to : %s\n", ip);
	}

	//Connecting to the IP
	server.sin_addr.s_addr = inet_addr(ip);
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );
 
  
	//Connecting to a remote server


	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0){
		if(!q_option)		
			puts("connect error");
        	return;
    	}
     

 	// puts("Connected\n");

	//Sending data

	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(socket_desc , message , strlen(message) , 0) < 0) {
		if(!q_option)        	
			puts("Send failed");
        	return;
    	}

	// puts("Data Send\n");

     
	//Receiving a reply from the server

	if( recv(socket_desc, server_reply , 2000 , 0) < 0) {
		if(!q_option)
        		puts("recv failed");
    	}

	// puts("Reply received\n");
	if(o_option)
		strcpy(url, o_file);
	else
		strcpy(url, "index.html");

	createFile(server_reply, url);


	if(k_option){

		ConvertLinks(url);
	}
     
	return;
}




