#include "calci.h"

int main()
{

	int sock_fd, data_sock_fd, c_size;
	struct sockaddr_in serv_addr;
	struct response resp;
	struct request req;

	printf("PANKAJ: Server is waiting...\n");

	/*Create a TCP socket*/
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	/*Bind it to a perticular IP address and port */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(SERVER_PORT);

	bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	/* Wait and listen for incoming connections */
	listen(sock_fd, SERVER_LENGTH);

	/* If there are any, accept and create a new data socket */
	data_sock_fd = accept(sock_fd, (struct sockaddr*)NULL, NULL);

	while (1)
	{
		printf("\nPANKAJ: Server is waiting...\n");

		/* Try to get some actual data from client */
		recv(data_sock_fd, (void *)&req, sizeof(req), 0);

		//calling arithmatic operation to perfom operations
		arithmatic(&req, &resp);

		if (!resp.flag)
		{
			/* Print the data recieved from client */
			printf("\nHere is the result: %f\n", resp.result);
			c_size = send(data_sock_fd, (void *)&resp, sizeof(resp), 0);

			if (c_size)
			{
				printf("Message send to relay agent successfully, please check\n");
			}
			else
			{
				printf("Error: Message failed\n");
			}
		}
		else
		{
			send(data_sock_fd, (void *)&resp, sizeof(resp), 0);
			printf("Plz enter the right operator (*, /, +, -)\n");

			/* Close the sockets now */
			close(data_sock_fd);
			close(sock_fd);
			exit (0);
		}
	}
}

