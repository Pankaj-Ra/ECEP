#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_IP     "127.0.0.1"
#define SERVER_PORT   5000
#define SERVER_LENGTH 10
#define SERVER_BUFF   20

int main()
{
	int sock_fd, data_sock_fd, buffer_len;
	struct sockaddr_in serv_addr;
	char serv_buffer[SERVER_BUFF];

	printf("PANKAJ: Server is waiting...\n");
        
	/*Create a TCP socket*/
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	/*Bind it to a perticular IP address and port */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	/* Wait and listen for incoming connections */
	listen(sock_fd, SERVER_LENGTH);

	/* If there are any, accept and create a new data socket */
	data_sock_fd = accept(sock_fd, (struct sockaddr*)NULL, NULL);

	/* Try to get some actual data from client */
	recv(data_sock_fd, (void *) serv_buffer, SERVER_BUFF, 0);

	/* Print the data recieved from client */
	printf("Here is the client data: %s\n", serv_buffer);

	/* Close the sockets now */
	close(data_sock_fd);
	close(sock_fd);
}

