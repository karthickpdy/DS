#include<stdio.h>
#include<stdlib.h>
struct Node
{
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

		while(temp && temp->next && i<pos)
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

void deleteFirst(struct Node **head)
{
	if(!(*head) || !(*head)->next)
		return;
	struct Node *temp = (*head)->next;
	(*head)->next=(*head)->next->next;
	free(temp);
}


void deleteLast(struct Node **head)
{
	if(!(*head) || !(*head)->next)
		return;
	if(!(*head)->next->next)
	{
		deleteFirst(head);
		return;
	}
	struct Node *temp = (*head)->next;
	while(temp->next && temp->next->next)
	temp=temp->next;

	struct Node *temp1 = temp->next;
	temp->next=temp->next->next;
	free(temp1);
	
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
