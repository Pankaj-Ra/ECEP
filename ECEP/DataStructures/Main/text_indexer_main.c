#include "text_indexer.h"

int main(int argc, char *argv[])
{
	int i, j;
	FILE *fs;
	Wlist **start = NULL;
	SList *head = NULL, *tail = NULL;
	char ch;
	char string[20] = {'\0'};

	printf("Enter the word you want to search\n");
	scanf("%[^\n]", string);

	lower_case(string);

	char *word = malloc(20 * sizeof(char));

	int *arr = calloc((argc - 1),  sizeof(int));

        alloc_index(&start);
        
	for (i = 1; i < argc - 1; i++)
	{
		fs = fopen(argv[i], "r");

		if (fs == NULL)
		{
			printf("fopen: failed to open the file\n");
			return -1;
		}

		while ((ch = fgetc(fs)) != EOF)
		{
			if (isalpha(ch))
			{
				j = 0;
				while (isalpha(ch) && ch != EOF)
				{
					word[j] = ch;
					ch = fgetc(fs);
					j++;
				}
				word[j] = '\0';

				lower_case(word);

				word_chain(&head, &tail, word);
			}
		}
		word[0] = '\0';
		word_chain(&head, &tail,  word);
		fclose(fs);
	}

	SList *temp = head;
	int index, count = 0;
	j = 0;

	while (temp->link != NULL)
	{
		count_remove_duplicate(&head, &tail, arr, j);

		index = hash_function(head->data);

                for (i = 0; i < argc - 1; i++)
		{
			count += arr[i];
		}

		alloc_populate_list(&start, head->data, index, count, arr, argc - 2);

		for (i = 0; i < argc - 1; i++)
		{
			arr[i] = 0;
		}
                
		count = 0;
		temp = temp->link;
		free(head);
		head = temp;
		if (temp->link != NULL)
		{
			while (temp->data[0] == '\0')
			{
				temp = temp->link;
				free(head);
				head = temp;
				j++;
			}
		}
	}

	index = hash_function(string);

	Wlist *node = search_string(start, string, index);

	if (node != NULL)
	{
		print_detail(node, argv, argc - 2);
	}

	create_database(start, argv, argc);

	return 0;
}

