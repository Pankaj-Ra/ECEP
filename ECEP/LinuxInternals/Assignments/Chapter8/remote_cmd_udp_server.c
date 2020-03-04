#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
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
	int sock_fd, buffer_len, cli_len;
	int read_len;
	struct sockaddr_in serv_addr, cli_addr;
	struct remote_req receive;
	struct remote_resp send;
	int fd1, fd2;

	printf("PANKAJ: Server is waiting...\n");

	/*Create a TCP socket*/
	sock_fd = socket(AF_INET, SOCK_DGRAM, 0);

	/*Bind it to a perticular IP address and port */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        
	cli_len = sizeof(struct sockaddr_in);
        
//	while (1)
//	{
		/* Try to get some actual data from client */
		recvfrom(sock_fd, (void *)&receive, sizeof(receive), 0, (struct sockaddr *)&cli_addr, &cli_len);

		/* Print the data recieved from client */
		printf("Here is the client data: %s\n", receive.client_buff);
		if (!strcmp(receive.client_buff, "exit"))
		{
			printf("Terminated\n");
			close(sock_fd);
			exit(0);
		}

		if ((fd1 = open("source.txt", O_RDWR | 0666)) == -1)
		{
			perror("open");
			return -1;
		}
                
		//dup2(fs1, 1);
		system(receive.client_buff);
                
		send.pack_num = 0;
		while (((read_len = read(fd1, send.buff, BUFF_SIZE-1)) != -1) && (read_len != 0))
		{
			send.pack_num += 1;
                        send.length = strlen(send.buff);
                       
RESEND:			/* Send the message to the server */
			sendto(sock_fd, (void *)&send, sizeof(send), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
                        
			/* Try to get some actual data from client */
			recvfrom(sock_fd, (void *)&receive, sizeof(receive), 0, (struct sockaddr *)&cli_addr, &cli_len);
                        memset(send.buff, '\0', 64);

			if (!receive.ack)
				continue;
			else
				goto RESEND;
		}
		send.buff[0] = '\0';
		send.pack_num += 1;
		send.length = strlen(send.buff);
		sendto(sock_fd, (void *)&send, sizeof(send), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
               //}
		/* Close the sockets now */
		close(sock_fd);
}
