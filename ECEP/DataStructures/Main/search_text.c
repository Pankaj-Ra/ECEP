#include "text_indexer.h"

int main(int argc, char *argv[])
{
	char string[50] = {'\0'};
	char word[20] = {'\0'};
	int len, option;
	char ch;
	int i = 0, j;

	while (1)
	{
		printf("\n\e[1;33mType 1 : To search words in the database\nType 2 : To exit\e[0m\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:

				printf("\n\e[1;33mEnter the word you want to search\e[0m\n");
				scanf("\n%[^\n]", string);

				len = strlen(string);
				lower_case(string);

				char *str = string;
				char *temp, *temp1 = string;

				i = 0;
				while (*str)
				{
					while (*str == ' ')
					{
						temp = str;
						if (i)
						{
							str++;
						}
						if (*str == ' ')
						{
							while (*str)
							{
								*str = *(str + 1);
								str++;
							}
							str = temp;
						}
					}
					str++;
					i++;
				}
				str = temp1;
				printf("\e[1;32mstring:\e[0m \e[1;33m%s\e[0m\n", str);

				while (*str)
				{
					j = 0;
					while ((*str != ' ') && *str)
					{
						word[j++] = *str++;
						word[j] = '\0';
					}
					search_database(word, argv);
					if (*str++)
					{
						continue;
					}
					break;
				}
				printf("\n\e[1;34m---------------------------------------------\e[0m\n\n");

				break;

			case 2:
			         
                                printf("\e[1;35m<<<EXIT>>>\e[0m\n");
				exit(0);

			default :

				printf("\e[1;35m<<<Select option 1 or option 2>>>\e[0m\n");
				break;
		}
	}

	return 0;
}

