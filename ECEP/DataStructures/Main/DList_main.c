#include "../Include/DList.h"

int main()
{
	DList *head = NULL;
	data_t info, binfo, ainfo;
	int num, result, i = 1;

	while (1)
	{
		if (i == 1)
		{
		printf("Select Operation from list as follows:\n 1 To Insert node at first position\n 2 To Insert node at last position\n 3 To delete node at first position\n 4 To delete node at last position\n 5 To delete a perticular node\n 6 To insert node before\n 7 To insert node after\n 8 To delete whole list\n 9 To print Whole list\n 10 To EXIT\n");
		}
		else
		{
			printf("Select next OPERATION from above LIST\n");
		}
		scanf("%d", &num);
                i++;

		switch (num)
		{
			case 1:

				printf("Enter the element value\n");
				scanf("%d", &info);

				result = dl_insert_first(&head, info);

				dl_print_list(&head, result);

				break;

			case 2:

				printf("Enter the element value\n");
				scanf("%d", &info);

				result = dl_insert_last(&head, info);

				dl_print_list(&head, result);

				break;

			case 3:

				result = dl_delete_first(&head);

				dl_print_list(&head, result);

				break;

			case 4:

				result = dl_delete_last(&head);

				dl_print_list(&head, result);

				break;

			case 5:

				printf("Enter the element value u want to delete\n");
				scanf("%d", &info);

				result = dl_delete_element(&head, info);

				dl_print_list(&head, result);

				break;

			case 6:

				printf("Before which value in link you want to add the new element\n");
				scanf("%d", &binfo);
				printf("Enter the element value\n");
				scanf("%d", &info);

				result = dl_insert_before(&head, info, binfo);

				dl_print_list(&head, result);

				break;

			case 7:

				printf("After which value in link you want to add the new element\n");
				scanf("%d", &binfo);
				printf("Enter the element value\n");
				scanf("%d", &info);

				result = dl_insert_after(&head, info, binfo);

				dl_print_list(&head, result);

				break;

			case 8:

				result = dl_delete_list(&head);

				dl_print_list(&head, result);

				break;

			case 9:
			
				dl_print_list(&head, 0);

				break;
			
			case 10:

				printf("ALL IS WELL\n");
				exit (0);

			default :
				printf("Please enter options between 1 to 10\n");

				break;

		}

	}

	return 0;
}







				














