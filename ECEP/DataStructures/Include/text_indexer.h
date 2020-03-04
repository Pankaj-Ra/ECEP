#ifndef _TEXT_INDEXER_H_
#define _TEXT_INDEXER_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct word_link_list
{
	char word[20];
	int w_count;
	int f_count[10];
	struct word_link_list *link;
}Wlist;

typedef struct single_link_list
{
	char data[20];
	struct single_link_list *link;
}SList;

void alloc_index(Wlist ***start);
Wlist *wl_create_node(void);
int hash_function(char *key);
SList* sl_create_node(void);
int sl_isempty(SList *head);
void lower_case(char *word);
void word_chain(SList **head, SList **tail, char *info);
void count_remove_duplicate(SList **head, SList **tail, int arr[], int j);
void alloc_populate_list(Wlist ***start, char *string, int index, int count, int *file, int num);
Wlist *search_string(Wlist **start, char *string, int index);
void print_detail(Wlist *temp, char *file[], int f_count);
void create_database(Wlist **start, char *file[], int argc);
void search_database(char *word, char*argv[]);

#endif




