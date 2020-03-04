#include "tree.h"

int main()
{
	Tree *root = NULL;
	data_t info;
	int i = 0, option;
	data_t result;

	while(1)
	{
		if (!i)
		{
			printf("Select the options below:\n 1. Insert the element in the tree\n 2. To find min element in tree\n 3. To fins max element in tree\n 4. To delete a node in tree\n 5. To print inorder transverse\n 6. To print preorder transverse\n 7. To print postorder transverse\n 8. To search a perticular node\n 9. EXIT\n");
			i++;
		}
		else
		{
			printf("<<<Select the operations>>>\n");
		}
		scanf("%d", &option);

		switch (option)
		{
			case 1:

				printf("[Enter the element]\n");
				scanf("%d", &info);

				root = bst_insert(root, info);
                                
				inorder(root);

				printf("\n");

				break;

			case 2:

				result = find_min(root);

				if (result)
				{
					printf("[Minimum value is: %d ]\n", result);
				}
				else
				{
					printf("[Data not found]\n");
				}

				break;

			case 3:

				result = find_max(root);

				if (result)
				{
					printf("[Maximum value is: %d ]\n", result);
				}
				else
				{
					printf("[Data not found]\n");
				}

				break;

			case 4:

				printf("[Enter the node you want to delete]\n");
				scanf("%d", &info);

				result = bst_delete_node(root, info);

				if(result)
				{
					inorder(root);
					printf("\n");
				}
				else
				{
					printf("[Data not found]\n");
				}

				break;

			case 5:

				inorder(root);
				printf("\n");

				break;

			case 6:

				preorder(root);
				printf("\n");

				break;

			case 7:

				postorder(root);
				printf("\n");

				break;

			case 8:

				printf("[Enter the node you want to search]\n");
				scanf("%d", &info);
				result = search_node(root, info);

				if (result)
				{
					printf("[Given data %d exists in tree]\n", result);
				}
				else
				{
					printf("[Data not found]\n");
				}

				break;

			case 9:
			        
				printf("[EXIT]\n");
				exit(0);

			default :

				printf("<<<Select the option between 1-9>>>\n");

				break;
		}
	}
	return 0;
}

