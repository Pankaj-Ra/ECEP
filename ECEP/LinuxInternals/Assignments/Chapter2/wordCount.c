#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void my_wc(char *argv[], int status, int end)
{
	int fs, wd_count = 0 , len_count = 0 , ch_count = 0 , bytes_read;
	char ch;
	char buff;
	int flag = 0;
	static int wc = 0, lc = 0, cc = 0;
        
	if (status)
	{
		if ((fs = open(argv[status], O_RDONLY)) == -1)
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

		flag = 0;
		while (buff > 32)
		{
			bytes_read = read(fs, &buff, 1);
			ch_count++;
			flag = 1;
			if (bytes_read == 0)
			{
				wd_count++;
				break;
			}
		}

		if (flag)
		{
			wd_count++;
		}
                
		if (buff == '\n')
		{
			len_count++;
		}
	}

	printf("  %d", len_count);
	printf("  %d", wd_count);
	printf("  %d", ch_count);
	if (status)
	{
		printf("  :%s", argv[status]);
		wc += wd_count;
		lc += len_count;
		cc += ch_count; 
	}
	if (end)
	{
		printf("\n %d  %d  %d  :Total", lc, wc, cc);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int arg;
	int end = 0;

	if (argc == 1)

	{
		my_wc(argv, 0, end);
	}
	else
	{
		for (arg = 1; arg < argc; arg++)
		{
			if (arg == argc - 1)
			{
				end = 1;
			}
			my_wc(argv, arg, end);
		}
	}
	return 0;
}
