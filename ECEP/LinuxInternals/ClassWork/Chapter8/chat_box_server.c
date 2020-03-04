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
			int sock_fd, data_sock_fd, buffer_len, c_size;
			struct sockaddr_in serv_addr;
			char serv_buffer[SERVER_BUFF];
			struct sockaddr_storage serverStorage;
			socklen_t addr_size;

			printf("\e[1;32mPANKAJ: Server is waiting...\e[0m\n");

			/*Create a TCP socket*/
			sock_fd = socket(AF_INET, SOCK_STREAM, 0);

			/*Bind it to a perticular IP address and port */
			serv_addr.sin_family = AF_INET;
			serv_addr.sin_addr.s_addr = INADDR_ANY;
			serv_addr.sin_port = htons(SERVER_PORT);

			bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

			/* Wait and listen for incoming connections */
			listen(sock_fd, SERVER_LENGTH);
                        
			addr_size = sizeof serverStorage;
			/* If there are any, accept and create a new data socket */
			data_sock_fd = accept(sock_fd, (struct sockaddr *)&serverStorage, &addr_size);
                        
			while (1)
			{
				int pid;
				pid = fork();
				if (!pid)
				{
					/* Try to get some actual data from client */
					c_size = recv(data_sock_fd, (void *) serv_buffer, SERVER_BUFF, 0);

					if (c_size)
					{
						/* Print the data recieved from client */
						printf("\t\t\t\e[1;32mU got a message:\e[0m \e[1;33m%s\e[0m\n", serv_buffer);
					}
					else
					{
						perror("recv");
						close(data_sock_fd);
						exit(0);
					}
				}
				else
				{
					printf("\e[1;33mClient typing....\e[0m\n");
					fgets(serv_buffer, 100, stdin);

					c_size = send(data_sock_fd, (void *) serv_buffer, SERVER_BUFF, 0);
					if (c_size)
					{
					//	printf("Message send to server successfully, please check\n");
					}
					else
					{
						perror("send");
						close(data_sock_fd);
						exit(0);
					}

				}
			}
			/* Close the sockets now */
			close(data_sock_fd);
}



