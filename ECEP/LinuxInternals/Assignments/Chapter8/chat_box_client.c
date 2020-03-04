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

#define SERVER_IP        "192.168.12.19"
#define SERVER_PORT      5000
#define SERVER_LENGTH    10
#define CLIENT_BUFF_SIZE 100
#define SERVER_BUFF      100

int main()
{
	int sock_fd, c_size;
	char client_buff[CLIENT_BUFF_SIZE];
	struct sockaddr_in serv_addr;

	// Create a client socket
	if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Error: Could not create socket\n");
		return 1;
	}

	// Binding with client socket is optional 

	// Populate it with servers address details 

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVER_PORT);
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);


	if(connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) !=0)
	{
		printf("\e[1;35mError connecting to server\e[0m\n");
		exit(0);
	}
	//	else
	//	{
	//		printf("Connection Successful\n");
	//	}
	while (1)
	{
		int pid = fork();
			if (!pid)
			{
				// get the message from client 
				printf("\e[1;33mClient typing....\e[0m\n");
				//scanf("%[^\n]%*c", client_buff);
				fgets(client_buff, 100, stdin);
				// Send the message to the server 
				c_size = send(sock_fd, (void *)&client_buff, CLIENT_BUFF_SIZE, 0);

				if (c_size)
				{
					//printf("Message send to server successfully, please check\n");
				}
				else
				{
					printf("\e[1;35mError: Message failed\e[0m\n");
					close(sock_fd);
					exit(0);
				}
			}
			else
			{
				/* Try to get some actual data from client */
				c_size = recv(sock_fd, (void *) client_buff, SERVER_BUFF, 0);

				if (c_size)
				{
					/* Print the data recieved from client */
					printf("\t\t\t\e[1;32mU got a message:\e[0m \e[1;33m%s\e[0m\n", client_buff);
				}
				else
				{
					perror("recv");
					close(sock_fd);
					exit(0);
				}
			}

	}
}
