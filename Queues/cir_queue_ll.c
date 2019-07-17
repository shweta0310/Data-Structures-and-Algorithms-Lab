#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node *next;
};
struct node *f=NULL,*r=NULL;

void display(struct node *f,struct node *r)
{	putchar('\n');
	struct node *p=f;
	while(p!=r)
	{
		printf("%d ",p->a);
		p=p->next;
	}
	printf("%d ",r->a);
}
void enqueue(int k)
{
	struct node *p=NULL;
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	printf("\nMemory not allocated");
	else if(f==NULL && r==NULL)
	{
		p->a=k;f=p;r=p;
	}
	else
	{
		p->a=k;
		r->next=p;
		p->next=f;
		r=p;
	}
	display(f,r);
}
void dequeue()
{
	if(f==NULL && r==NULL)
	printf("\nQueue empty");
	else if(f==r)
	{
		struct node *p=f;
		printf("\nElement to be deleted: %d",p->a);
		f=NULL;r=NULL;
		free(p);
		
	}
	else
	{
		struct node *p=f;
		printf("\nElement to be deleted: %d",p->a);
		f=f->next;
		p->next=NULL;
		free(p);
		display(f,r);
	}
}
void main()
{
	int option,k;
	l1:
	printf("\n option: ");scanf("%d",&option);
	switch(option)
	{
		case 1:	printf("\nEnter element: ");scanf("%d",&k);
				enqueue(k);
				goto l1;
	
		case 2:	dequeue();
				goto l1;

		default: break;
	}
}
	
