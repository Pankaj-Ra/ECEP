#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <netinet/in.h>

#define SERVER_IP        "127.0.0.1"
#define SERVER_PORT      5000
#define CLIENT_BUFF_SIZE 50
#define BUFF_SIZE        64

struct remote_req
{
	char client_buff[CLIENT_BUFF_SIZE];
	int data;
	int ack;
};

struct remote_resp
{
	char buff[BUFF_SIZE];
	int pack_num;
	int length;
};

int main()
{
	int sock_fd, c_size;
	struct sockaddr_in serv_addr;
	struct remote_req send;
	struct remote_resp receive;
	int i = 1;
	int fd1;
	int serv_len;

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
        
	serv_len = sizeof(struct sockaddr_in);

	/* get the message from client */
	printf("Enter the command you want to send\n");
	fgets(send.client_buff, CLIENT_BUFF_SIZE, stdin);

	/* Send the message to the server */
	c_size = sendto(sock_fd, (void *)&send, sizeof(send), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	if (c_size)
	{
		printf("Message send to the server successfuly\n");
		if (!strcmp(send.client_buff, "exit"))
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

	if ((fd1 = open("dest.txt", O_APPEND | 0666)) == -1)
	{
		perror("open");
		return -1;
	}

	while (1)
	{
	//	printf("%s", receive.buff);

		if (receive.buff[0] == '\0')
		{
			break;
		}

		/* Try to get some actual data from client */
		recvfrom(sock_fd, (void *)&receive, sizeof(receive), 0, (struct sockaddr *)&serv_addr, &serv_len);

		if (receive.pack_num == i)
		{
			if (write(fd1, receive.buff, receive.length) == -1)                                                           
			{
				perror("write");
				return -1;
			}
                        send.ack = 0;
			sendto(sock_fd, (void *)&send, sizeof(send), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
			i++;
		}
		else
		{
			printf("ACK: corrupted\n");
			send.ack = -1;
			sendto(sock_fd, (void *)&send, sizeof(send), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
		}
	}
//	printf("\n");
	close(sock_fd);
}
