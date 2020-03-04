#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void factorial(void)
{
	int total = 1, i;
	int num;

	printf("Enter the value to get factorial\n");
	scanf("%d", &num);

	if (num)
	{
		for (i = num; i > 0; i--)
		{
			total = total * i;
		}

		printf("Factorial : %d\n", total);
		return;
	}
	printf("Factorial : %d\n", total);
	return;
}

void prime(void)
{
	int N, i, j = 2, REMENDER = 1, COUNT;
START: printf ("Enter the number to get prime series\n");
       scanf ("%d",&N);

       if (N < 2)
       {
	       printf ("Enter the valid input > 2 \n");
	       goto START;
       }

       printf("Prime series up to %d is \n", N);

       for (i = 2;i <= N;i++)
       {
	       j = 2;
	       COUNT = i;
	       while (j*j  <= COUNT)
	       {
		       REMENDER = (i % j);
		       if (REMENDER == 0)
		       {
			       break;
		       }
		       j++;
	       }
	       if (REMENDER != 0)
	       {
		       sleep(1);
		       printf ("%d\n", i);
	       }
       }
       printf ("\n");
}

void fibonachi(void)
{
	int N, i, NUM1=0, NUM2=1, GREAT=0;

	printf ("Enter the Number to get fibonachi series\n");
	scanf ("%d",&N);
	printf ("Fibonacci Series up to %d is\n",N);
	for (i = 0; i <= N + 1; i++)
	{
		if (NUM1 <= N)
		{
			GREAT = NUM1 + NUM2;               
			printf ("%d\t",NUM1);             
			NUM1 = NUM2;
			NUM2 = GREAT;
		}
	}
	printf ("\n");
}

int main()
{
	int pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		printf("child pid: %d child ppid %d: \n", getpid(), getppid());
		//factorial();
	        	prime();
		//	fibonachi();
	}
	else
	{
		prime();
		printf("\n<<<pairent is waiting>>>\n");
		printf("parent pid: %d parent ppid %d: \n", getpid(), getppid());
		wait(&status);


		if (WIFEXITED(status)) {
			printf("exited, status=%d\n", WEXITSTATUS(status));
		} else if (WIFSIGNALED(status)) {
			printf("killed by signal %d\n", WTERMSIG(status));
		} else if (WIFSTOPPED(status)) {
			printf("stopped by signal %d\n", WSTOPSIG(status));
		} else if (WIFCONTINUED(status)) {
			printf("continued\n");
		}

		sleep(3);

		printf("<<<pairent is dying>>>\n\n");

	}

	return 0;
}


