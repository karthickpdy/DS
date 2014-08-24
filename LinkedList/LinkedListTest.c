#include"LinkedList.h"
int main(int argc, char const *argv[])
{
	struct Node *list= create();
	append(&list,2);
	append(&list,3);
	add(&list,1,1);
	add(&list,4,2);
	
	
	deleteLast(&list);
	deleteLast(&list);
	deleteLast(&list);
	deleteLast(&list);
	add(&list,4,1);
	add(&list,22,5);
	add(&list,33,2);
	add(&list,11,3);
	add(&list,12,4);

	printList(list);

	return 0;
}