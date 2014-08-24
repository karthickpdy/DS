#include"LinkedList.h"
int main(int argc, char const *argv[])
{
	struct Node *list= create();
	append(&list,2);
	append(&list,3);
	add(&list,1,1);
	add(&list,4,2);
	
	
	printList(list);

	return 0;
}