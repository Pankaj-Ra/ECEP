#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void my_wc(char *argv[], int status)
{
	int fs, wd_count = 0 , len_count = 0 , ch_count = 0 , bytes_read;
	char ch;
	char buff;
	int flag = 0;
        
	if (status)
	{
		if ((fs = open(argv[1], O_RDONLY)) == -1)
		{
			perror("open");
			return;
		}
	}
	else
	{
		fs = 0;
	}

	while (((bytes_read = read(fs, &buff, 1)) != -1) && (bytes_read != 0))
	{
		ch_count++;
		if ((buff == ' ') || (buff == '\t'))
		{
			while ((buff == ' ') || (buff == '\t'))
			{
				bytes_read = read(fs, &buff, 1);
				ch_count++;
			}

			if (!bytes_read)
			{
				break;
			}

			if (flag)
			{
				wd_count++;
			}
		}
		if (buff == '\n')
		{
			len_count++;
			bytes_read = read(fs, &buff, 1);
			ch_count++;
			if ((buff == ' ') || (buff == '\t'))
			{
				while ((buff == ' ') || (buff == '\t'))
				{
					bytes_read = read(fs, &buff, 1);
					ch_count++;
				}
				continue;

			}
			if (!bytes_read)
			{
				break;
			}
			wd_count++;
		}
		flag++;
	}

	printf("\nWord count: %d\n", wd_count);
	printf("Line count: %d\n", len_count);
	printf("Char count: %d\n", ch_count);
}

int main(int argc, char *argv[])
{

	switch (argc)
	{
		case 1:
			{
				my_wc(argv, 0);
				break;
			}

	/*	case 2:
			{
				printf("Plz enter right format: ./a.out -w/l/c <sourcefile>\n");
				break;
			}*/

		case 2:
			{
				my_wc(argv, 1);
				break;
			}

		default:
			{
				printf("Plz enter right format: ./a.out -w/l/c <sourcefile>\n");
				break;
			}
	}
	return 0;
}

