#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int num;

void my_handler(int unused)
{	

	int i, res = 1;

	for(i = num; i > 0; i--)
	{
		res *= i;
	}
	printf("res: %d\n", res);


}

int main()
{
	int pid, fd[2];
        int temp;

	pipe(fd);

	pid = fork();

	if(pid == 0)
	{
		printf("Enter num: ");
		scanf("%d", &num);
		temp = getppid();
		write(fd[1], &num, sizeof(num));
		kill(temp, SIGUSR1);
	}
	else
	{
		signal(SIGUSR1, my_handler);
		read(fd[0], &num, sizeof(num));
	}

	return 0;
}
