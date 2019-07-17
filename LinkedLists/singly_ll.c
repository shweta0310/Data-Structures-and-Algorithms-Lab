#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node *next;
};

struct node *start=NULL;

void display(struct node *start)
{	putchar('\n');
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d ",p->a);
		p=p->next;
	}
}
void insert(int k, int pos)
{
	struct node *p=NULL;
	p=(struct node*)malloc(sizeof(p));
	if(p==NULL)
	printf("\n Memory not allocated for new node");
	else if(pos==1)
	{
		p->a=k;
		p->next=NULL;
		start=p;
	}
	else 
	{	p->a=k;
		struct node *p1=start;
		int c=2;
		while(c<pos)
		{
			p1=p1->next;c++;
		}
		p->next=p1->next;
		p1->next=p;
	}
	display(start);
}

void Delete(int k)
{
	if(start==NULL)
	printf("\n Linked List empty");
	else if(start->a==k)
	{
		struct node *p=start;
		start=start->next;
		free(p);display(start);
	}
	else
	{
		struct node *prev=start,*cur=start->next;
		while(cur!=NULL && cur->a!=k)
		{
			prev=cur;
			cur=cur->next;
		}
		if(cur==NULL)
		printf("\n Element not in linked list");
		else
		{
			prev->next=cur->next;
			free(cur);
		}
		display(start);
	}
}

int search(int k)
{	int pos=1;
	struct node *p=start;
	while(p->a!=k)
	{
		p=p->next;pos++;
	}
	if (p==NULL)
	{	printf("\n Element not present");return -1;}
	else
	return pos;
}
void main()
{
	int k,pos,c;char ch,temp;
	do
	{
	printf("\n choise: ");scanf("%d",&c);
	switch(c)
	{
		case 1: printf("\n k & pos:  ");scanf("%d %d",&k,&pos);
				insert(k,pos);
				break;
		case 2:	printf("\n k= ");scanf("%d",&k);
				Delete(k);
				break;
		case 3:	printf("\n k= ");scanf("%d",&k);
				pos=search(k);
				printf("\n position: %d",pos);
				break;
	}
	printf("\n continue? : ");scanf("%c",&temp);scanf("%c",&ch);
	}while(ch=='y');
}			
		
