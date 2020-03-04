libSList.so : SList_functions.c
	gcc -shared -fPIC -o ../Library/libSList.so SList_functions.c
libDList.so : DList_function.c
	gcc -shared -fPIC -o ../Library/libDList.so DList_function.c
libstack.so : stack.c
	gcc -shared -fPIC -o ../Library/libstack.so stack.c
libsorting.so : sorting.c
	gcc -shared -fPIC -o ../Library/libsorting.so sorting.c
libtree.so : binary_search_tree.c
	gcc -shared -fPIC -o ../Library/libtree.so binary_search_tree.c
libtext_indexer.so : text_indexer.c
	gcc -shared -fPIC -o ../Library/libtext_indexer.so text_indexer.c
clean :
	rm ../Library/*.so

