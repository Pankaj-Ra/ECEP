SList.exe : SList_main.c
	gcc -o SList.exe SList_main.c -lSList -L../Library/ -I../Include
DList.exe : DList_main.c
	gcc -o DList.exe DList_main.c -lDList -L../Library/ -I../Include
Postfix.exe : postfix.c
	gcc -g -o Postfix.exe postfix.c -lstack -L../Library/ -I../Include
Prefix.exe : prefix.c
	gcc -o Prefix.exe prefix.c -lstack -L../Library/ -I../Include
Binary_search.exe : binary_search.c	
	gcc -o Binary_search.exe binary_search.c -lstack -L../Library/ -I../Include
Sorting.exe : sorting_main.c
	gcc -o Sorting.exe sorting_main.c -lsorting -L../Library/ -I../Include
Tree.exe : tree_main.c
	gcc -o Tree.exe tree_main.c -ltree -L../Library/ -I../Include
Text_indexer.exe : text_indexer_main.c
	gcc -o Text_indexer.exe text_indexer_main.c -ltext_indexer -L../Library/ -I../Include
Search_text.exe : search_text.c
	gcc -o Search_text.exe search_text.c -ltext_indexer -L../Library/ -I../Include
clean :
	rm ../Main/*.exe
