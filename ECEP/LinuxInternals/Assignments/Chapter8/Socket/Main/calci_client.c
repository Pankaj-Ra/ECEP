#include "calci.h"

int main()
{
	int sock_fd, c_size;
	struct sockaddr_in serv_addr;
	struct request req;
	struct response resp;

	/* Create a client socket*/
	if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("Error: Could not create socket\n");
		return 1;
	}

	/* Populate it with servers address details */

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVER_PORT);
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

	if(connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) !=0)
	{
		printf("Error connecting to server\n");
		perror("connect");
		exit(0);
	}
	else
	{
		printf("Connection Successful\n");
	}
        
	while (1)
	{
		/* get the input from client */
                __fpurge(stdin);
		printf("\nEnter the operation you want to perform\n");
		scanf("%c", &req.operat);
		printf("Enter the first number\n");
		scanf("%d", &req.operan1);
		printf("Enter the second number\n");
		scanf("%d", &req.operan2);

		c_size = send(sock_fd, (void *)&req, sizeof(req), 0);

		if (c_size)
		{
			printf("Message send to server successfully, please check\n");
		}
		else
		{
			printf("Error: Message failed\n");
		}

		recv(sock_fd, (void *)&resp, sizeof(resp), 0);

		if (!resp.flag)
		{
			printf("Here is the data recieved from server: %f\n", resp.result);
		}
		else
		{
			printf("The operation is unsuccessful\n");
			close(sock_fd);
			exit(0);
		}
	}

}


