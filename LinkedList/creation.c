#include<stdio.h>
#include<stdlib.h>
struct Node
{
	/* data */
	int data;
	struct Node *next;

};


struct Node * create()
{
	struct Node *head = (struct Node *) malloc(sizeof(struct Node ));
	(head)->data= 1;
	(head)->next=NULL;
	return head;
}

void add(struct Node **head,int data,int pos)
{
	if(!*head || pos<1)
		return ;

	struct Node *valueNode = (struct Node *)malloc(sizeof(struct Node));
	struct Node *temp=*head;
	
	valueNode->data=data;
	int i=1;

	if(pos==1)
	{
		valueNode->next = (*head)->next;
		(*head)->next=valueNode;
	}
	else
	{

		while(temp && i<pos)
		{
			i++;
			temp = temp->next;
		}
		valueNode->next = temp->next;
		temp->next = valueNode;
		
	}

}


void append(struct Node **head,int data)
{


	if(!*head)
		return ;

	struct Node *valueNode = (struct Node *)malloc(sizeof(struct Node));
	struct Node *temp=*head;
	
	valueNode->data=data;

	while(temp->next)
			temp=temp->next;
	
		temp->next=valueNode;
		valueNode->next=NULL;
	
}

void printList(struct Node *head)
{
	if(!head)
		return;
	head=(head)->next;
	while(head)
	{
		printf("%d\n",(head)->data );
		(head)=(head)->next;
	}

}

int main(int argc, char const *argv[])
{
	struct Node *list= create();
	append(&list,2);
	append(&list,3);
	add(&list,1,1);
	add(&list,4,2);
	
	printList(list);
	printList(list);

	return 0;
}