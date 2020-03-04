#include "SList.h"

int main()
{
	SList *head = NULL, *tail = NULL;
	SList *head1 = NULL, *tail1 = NULL;
	data_t info, binfo, ainfo;
	int num, result, i = 1;
	int  count = 0, index;

	while (1)
	{
		if (i == 1)
		{
		printf("Select Operation from list as follows:\n 0  To create Two Link Lists\n 1  To Insert node at first position\n 2  To Insert node at last position\n 3  To delete node at first position\n 4  To delete node at last position\n 5  To delete a perticular node\n 6  To insert node before\n 7  To insert node after\n 8  To delete whole list\n 9  To print Whole list\n 10 To count the occurance of given element in the link\n 11 To Get the data from particular index position\n 12 To insert value at particular position in a list\n 13 To insert element at right position in a sorted list\n 14 To sort a given link list\n 15 To append two link lists\n 16 To split a given list into two link lists\n 17 To Remove duplicate nodes from the list\n 18 To Merge two sorted link lists together\n 19 To Reverse a given link list\n 20 TO EXIT\n <<<Select OPERATION from above LIST>>>\n");
		}
		else
		{
			printf("<<<Select next OPERATION from above LIST>>>\n");
		}
		scanf("%d", &num);
                i++;

		switch (num)
		{
			case 0:
                               
				printf("[Enter the element value for 1st list]\n");
				scanf("%d", &info);

				result = sl_insert_last(&head1, &tail1, info);

				sl_print_list(&head, result);

				sl_print_list(&head1, result);

				break;

			case 1:

				printf("[Enter the element value]\n");
				scanf("%d", &info);

				result = sl_insert_first(&head, &tail, info);

				sl_print_list(&head, result);

				break;

			case 2:

				printf("[Enter the element value]\n");
				scanf("%d", &info);

				result = sl_insert_last(&head, &tail, info);

				sl_print_list(&head, result);

				break;

			case 3:

				result = sl_delete_first(&head, &tail);

				sl_print_list(&head, result);

				break;

			case 4:

				result = sl_delete_last(&head, &tail);

				sl_print_list(&head, result);

				break;

			case 5:

				printf("[Enter the element value u want to delete]\n");
				scanf("%d", &info);

				result = sl_delete_element(&head, &tail, info);

				sl_print_list(&head, result);

				break;

			case 6:

				printf("[Before which value in link you want to add the new element]\n");
				scanf("%d", &binfo);
				printf("[Enter the element value]\n");
				scanf("%d", &info);

				result = sl_insert_before(&head, &tail, info, binfo);

				sl_print_list(&head, result);

				break;

			case 7:

				printf("[After which value in link you want to add the new element]\n");
				scanf("%d", &binfo);
				printf("[Enter the element value]\n");
				scanf("%d", &info);

				result = sl_insert_after(&head, &tail, info, ainfo);

				sl_print_list(&head, result);

				break;

			case 8:

				result = sl_delete_list(&head, &tail);

				sl_print_list(&head, result);

				break;

			case 9:
			
				sl_print_list(&head, 0);

				break;
	
	                case 10:

			        printf("[Enter the element u want to check the occurance of]\n");
				scanf("%d", &info);

				result = sl_count(&head, info, &count);

				sl_print_list(&head, result);

				if (count)
				{
					printf("[The given element %d occures %d times in list]\n", info, count);
				}

				break;

		        case 11:
			        
				printf("[Enter the index value]\n");
				scanf("%d",&index);

				result = sl_get_nth(&head, &info, index);

				sl_print_list(&head, result);

				if (!result)
				{
					printf("[Data at %d position is: %d]\n", index, info);
				}

				break;

                        case 12:

			       printf("[Enter the index position]\n");
			       scanf("%d", &index);
			       printf("[Enter the value to insert at %d position]\n", index);
			       scanf("%d", &info);

			       result = sl_insert_nth(&head, &tail, info, index);

			       sl_print_list(&head, result);

			       break;

			case 13:

			        printf("[Enter the element]\n");
				scanf("%d", &info);

				result = sl_sorted_insert(&head, &tail, info);

				sl_print_list(&head, result);

				break;

                        case 14:

			        result = sl_insert_sort(&head, &tail);

				sl_print_list(&head, result);

				break;

                        case 15:
                                
				result = sl_append(&head, &head1, &tail, &tail1);

				sl_print_list(&head, result);

				break;

			case 16:

			        result = sl_split_list(&head, &head1, &tail, &tail1);

				sl_print_list(&head, result);

				sl_print_list(&head1, result);

				break;

                        case 17:

			        result = sl_remove_duplicates(&head, &tail);

				sl_print_list(&head, result);

				break;
 
                        case 18:

			        result = sl_sorted_merge(&head, &head1, &tail, &tail1);

				sl_print_list(&head, result);

				break;

                        case 19:

			        result = sl_reverse(&head, &tail);

				sl_print_list(&head, result);

				break;

			case 20:

				printf("<<<ALL IS WELL>>>\n");
				exit (0);

			default :

				printf("<<<Please enter options between 0 to 20>>>\n");
                               
				break;

		}

	}

	return 0;
}


