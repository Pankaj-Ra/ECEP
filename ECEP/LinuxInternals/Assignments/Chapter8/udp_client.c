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

#define SERVER_IP        "127.0.0.1"
#define SERVER_PORT      5000
#define CLIENT_BUFF_SIZE 200

int main()
{
	int sock_fd, c_size;
	char client_buff[CLIENT_BUFF_SIZE];
	struct sockaddr_in serv_addr;

	/* Create a client socket*/
	if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		printf("Error: Could not create socket\n");
		return 1;
	}

	/* Populate it with servers address details */

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVER_PORT);
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

	while (1)
	{
		/* get the message from client */
		printf("Enter the message you want to send\n");
		fgets(client_buff, 20, stdin);

		/* Send the message to the server */
		c_size = sendto(sock_fd, (void *)&client_buff, CLIENT_BUFF_SIZE, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

		if (c_size)
		{
			printf("Message send to the server successfuly\n");
			if (!strcmp(client_buff, "exit"))
			{
				printf("Terminated\n");
				close(sock_fd);
				exit(0);
			}
		}
		else
		{
			printf("Error: Message failed\n");
			close(sock_fd);
			exit(0);
		}
	}
	//	close(sock_fd);
}
