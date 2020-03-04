#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_IP    "127.0.0.1"
#define SERVER_PORT  5000
#define SERVER_BUFF  200

int main()
{
	int sock_fd, buffer_len, cli_len;
	struct sockaddr_in serv_addr, cli_addr;
	char serv_buffer[SERVER_BUFF];

	printf("PANKAJ: Server is waiting...\n");

	/*Create a TCP socket*/
	sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

	/*Bind it to a perticular IP address and port */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        
	cli_len = sizeof(struct sockaddr_in);
        
	while (1)
	{
		/* Try to get some actual data from client */
		recvfrom(sock_fd, (void *) serv_buffer, SERVER_BUFF, 0, (struct sockaddr *)&cli_addr, &cli_len);

		/* Print the data recieved from client */
		printf("Here is the client data: %s\n", serv_buffer);
		if (!strcmp(serv_buffer, "exit"))
		{
			printf("Terminated\n");
			close(sock_fd);
			exit(0);
		}

	}

	/* Close the sockets now */
	//	close(sock_fd);
}
