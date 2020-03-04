#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_IP        "127.0.0.1""
#define SERVER_PORT      5000
#define SERVER_LENGTH    10
#define CLIENT_BUFF_SIZE 20

int main()
{
	while (1)
	{
		int sock_fd, c_size;
		char client_buff[CLIENT_BUFF_SIZE];
		struct sockaddr_in serv_addr;

		/* Create a client socket*/
		if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		{
			printf("Error: Could not create socket\n");
			return 1;
		}

		/* Binding with client socket is optional */

		/* Populate it with servers address details */

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(SERVER_PORT);
		serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

		/* get the message from client */
		printf("Enter the message you want to send\n");
		fgets(client_buff, 20, stdin);

		if(connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) !=0)
		{
			printf("Error connecting to server\n");
		}
		else
		{

			printf("Connection Successful\n");
		}

		/* Send the message to the server */
		c_size = send(sock_fd, (void *)&client_buff, CLIENT_BUFF_SIZE, 0);

		if (c_size)
		{
			printf("Message send to server successfully, please check\n");
		}
		else
		{
			printf("Error: Message failed\n");
		}
	}
//	close(sock_fd);
}





