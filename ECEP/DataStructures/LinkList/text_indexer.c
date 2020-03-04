#include "../Include/text_indexer.h"

void alloc_index(Wlist ***start)
{
	int i;

	*start = malloc(26 * sizeof(int *));

	for (i = 0; i < 26; i++)
	{
		(*start)[i] = NULL;
	}
}

Wlist *wl_create_node(void)
{
	return (malloc(sizeof(Wlist)));
}

int hash_function(char *key)
{
	return key[0] - 'a';
}

SList *sl_create_node(void)
{
	return (malloc(sizeof(SList)));
}

int sl_isempty(SList *head)
{
	if (head == NULL)
	{
		return 1;
	}
	return 0;
}

void lower_case(char *word)
{
	int i = 0;
	int val;

	while (word[i] != '\0')
	{
		if (isupper(word[i]))
		{
			val = word[i] - 'A';
			word[i] = 'a' + val;
		}
		i++;
	}
}

void word_chain(SList **head, SList **tail, char *info)
{

	SList *new = sl_create_node();

	if (new == NULL)
	{
		return;
	}

	strcpy(new->data, info);
	new->link = NULL;

	if (sl_isempty(*head))
	{
		(*head) = (*tail) =  new;
		return;
	}

	(*tail)->link = new;
	(*tail) = new;
	return;
}

void count_remove_duplicate(SList **head, SList **tail, int arr[], int j)
{
	int i;

	if (sl_isempty(*head))
	{
		return;
	}

	SList *temp1, *temp2;

	temp2 = (*head);
	i = 1;

	while (temp2->link != NULL)
	{
		if (!strcmp(temp2->link->data, (*head)->data))
		{
			temp1 = temp2->link;
			i++;
			arr[j] = i;

			if (temp1->link == NULL)
			{
				temp2->link = NULL;
				(*tail) = temp2;
				free(temp1);
				return;
			}

			temp2->link = temp2->link->link;
			free(temp1);
			continue;
		}
		temp2 = temp2->link;
		if (temp2->data[0] == '\0')
		{
			i = 0;
			j++;
		}
	}

}

void alloc_populate_list(Wlist ***start, char *string, int index, int count, int *file, int num)
{
	int i;

	Wlist *new = wl_create_node();

	if (new == NULL)
	{
		return;
	}

	strcpy(new->word, string);
	new->w_count = count;
	new->link = NULL;

	for (i = 0; i < num; i++)
	{
		new->f_count[i] = file[i];
	}

	if (((*start)[index]) == NULL)
	{
		(*start)[index] = new;
		return;
	}

	new->link = (*start)[index];
	(*start)[index] = new;
}

Wlist *search_string(Wlist **start, char *string, int index)
{
	Wlist *temp = start[index];

	if (temp == NULL)
	{
		printf("Given word does't exist\n");
		return NULL;
	}

	if (!strcmp(temp->word, string))
	{
		return temp;
	}

	while (temp->link != NULL)
	{
		if (!strcmp(temp->word, string))
		{
			return temp;
		}
		temp = temp->link;
	}
	printf("Given word does't exist\n");
	return NULL;
}

void print_detail(Wlist *temp, char *file[], int f_count)
{
	int i;

	printf("Word: %s\n", temp->word);

	if (temp->word == NULL)
	{
		return;
	}
	printf("Total count: %d\n", temp->w_count);

	for (i = 0; i < f_count; i++)
	{
		printf("File count: %s: %d\n", file[i + 1], temp->f_count[i]);
	}

}

void create_database(Wlist **start, char *file[], int argc)
{
	int i, j;

	FILE *fd = fopen(file[argc - 1], "w");

	Wlist *node = start[0];

	for (j = 0; j < argc - 2; j++)
	{
		fputs(file[j + 1], fd);
		fputc(':', fd);
	}
	fputc('\n', fd);

	for (i = 0; i < 26; i++)
	{
		fputc('#', fd);
		fprintf(fd, "%d", i);

		if (start[i] != NULL)
		{
			node = start[i];
			Start:
			fputc('@', fd);
			fputs(node->word, fd);
			for (j = 0; j < argc - 2; j++)
			{
				fputc('/', fd);
				fprintf(fd, "%d", node->f_count[j]);
			}
			fputc('$', fd);
			fprintf(fd, "%d", node->w_count);

                        if (node->link != NULL)
			{
				node = node->link;
				goto Start;
			}
		}
		fputc('\n', fd);
	}
	fclose(fd);
}

void search_database(char *word, char *argv[])
{
	int index, i = 0;
	int *val;
	char ch = 0, string[20] = {'\0'};

	index = hash_function(word);

	SList *head = NULL, *tail = NULL;

	FILE *fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		printf("fopen: failed to open the file\n");
		return;
	}

	while (ch != '\n')
	{
		ch = fgetc(fd);
		if (ch == ':')
		{
			string[i] = '\0';
			word_chain(&head, &tail, string);
			i = 0;
			ch = fgetc(fd);
		}
		string[i] = ch;
		i++;
	}

	while ((ch = fgetc(fd)) != EOF)
	{
		if (ch == '#')
		{
			fscanf(fd, "%d", val);

			if (*val == index)
			{
				ch = fgetc(fd);
				if (ch == '\n')
				{
					printf("\n\e[1;34m---------------------------------------------\e[0m\n\n");
					printf("\e[1;35m<<<No match Found for [\e[1;33m%s\e[0m\e[1;35m]>>>\e[0m\n", word);
					fclose(fd);
					return;
				}
                                Loop:

				i = 0;
				ch = fgetc(fd);
				while (ch != '/')
				{
					string[i++] = ch;
					ch = fgetc(fd);
				}
				string[i] = '\0';
				if (!strcmp(string, word))
				{
					printf("\n\e[1;34m---------------------------------------------\e[0m\n\n");
					printf("\e[1;32mString:\e[0m \e[01;35m%s\e[0m\n", string);

					SList *tempo = head;

					printf("\e[1;32mF_count:\e[0m \e[1;33m%s:\e[0m ", tempo->data);
					fscanf(fd, "%d", val);
					printf("\e[1;35m%d\e[0m\n", *val);

					while (tempo->link != NULL)
					{
						printf("\e[1;32mF_count:\e[0m \e[1;33m%s:\e[0m ", tempo->data);
						fseek(fd, 1, SEEK_CUR);
						fscanf(fd, "%d", val);
						printf("\e[1;35m%d\e[0m\n", *val);
						tempo = tempo->link;
					}
					fseek(fd, 1, SEEK_CUR);
					fscanf(fd, "%d", val);
					printf("\e[1;32mTotal count:\e[0m \e[1;35m%d\e[0m\n", *val);

					fclose(fd);
					return;
				}
				while ((ch != '@') && (ch != '\n'))
				{
					ch = fgetc(fd);
				}
				if (ch == '@')
				{
					goto Loop;
				}
				else
				{
					printf("\n\e[1;34m---------------------------------------------\e[0m\n\n");
					printf("\e[1;35m<<<No match Found for [\e[1;33m%s\e[0m\e[1;35m]>>>\e[0m\n", word);
					fclose(fd);
					return;
				}
			}
		}
	}
	fclose(fd);
}

