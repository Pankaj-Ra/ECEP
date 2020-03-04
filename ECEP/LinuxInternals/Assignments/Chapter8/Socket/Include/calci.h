#include <sys/socket.h>
#include <stdio_ext.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_IP        "192.168.12.126"
#define SERVER_PORT      5000
#define SERVER_LENGTH    10

struct request
{
	char operat;
	float operan1;
	float operan2;
};

struct response
{
	int flag;
	float result;
};



