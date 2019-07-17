#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
void display(struct node *top)
{	putchar('\n');
	struct node *p=top;
	while(p!=NULL)
	{
		printf(" %d",p->data);
		p=p->next;
	}
}
void push(int k)
{
	struct node *p=NULL;
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	printf("\n Memory not allocated");
	else
	{
		p->data=k;
		p->next=top;
		top=p;
	}
	display(top);
}
void pop()
{
	if(top==NULL)
	printf("\n Stack Underflow");
	else
	{	
		struct node *p=top;
		printf("\n Element popped is: %d",p->data);
		top=top->next;
		free(p);
	}
	display(top);
}
void main()
{
	int option,k;
	l1:
	printf("\n option: ");scanf("%d",&option);
	switch(option)
	{
		case 1:	printf("\n Enter element: ");scanf("%d",&k);
				push(k);
				goto l1;
	
		case 2:	pop();
				goto l1;

		default: break;
	}
}
