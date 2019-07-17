#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node *next;
	struct node *prev;
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
		p->next=start;
		p->prev=NULL;
		start=p;
	}
	else 
	{	p->a=k;
		struct node *p1=start;
		int c=2;
		while(c<pos && p1->next!=NULL)
		{
			p1=p1->next;c++;
		}
		if (p1->next!=NULL)
		{
			struct node *temp=p1->next;
			p1->next=p;
			p->prev=p1;
			p->next=temp;
			temp->prev=p;
		}
		else if (p1->next==NULL)
		{
			p1->next=p;
			p->next=NULL;
			p->prev=p1;
		}
		
	}
	display(start);
}

void Delete(int k)
{
	if(start==NULL)
	printf("\n Linked List empty");
	else if(start->a==k && start->next!=NULL)
	{
		struct node *p=start;
		start=start->next;
		start->prev=NULL;
		free(p);display(start);
	}
	else if (start->a==k && start->next==NULL)		//only 1 element in ll
	{
		struct node *p=start;
		start=NULL;
		p->prev=NULL;
		free(p);
	}
	else
	{
		struct node *cur=start;
		while(cur->next!=NULL && cur->a!=k )
		{
			cur=cur->next;
		}
		if(cur->next==NULL)
		{
			if(cur->a!=k)			
			printf("\n Element not in linked list");
			else
			{cur->prev->next=NULL;free(cur);}
		}
		else
		{	
			struct node *temp=cur->next;			
			cur->prev->next=temp;
			temp->prev=cur->prev;
			cur->prev=NULL;cur->next=NULL;                                                           
			free(cur);
		}
		display(start);
	}
}

int search(int k)
{	int pos=1;
	struct node *p=start;
	while(p->a!=k && p->next!=NULL)
	{
		p=p->next;pos++;
	}
	if (p->next==NULL)
	{	
		if(p->a!=k)			
		{printf("\n Element not present");return -1;}
		else return pos;
	}
	else
	return pos;
}
void main()
{
	int k,pos,c;char ch,temp;
	do
	{
		printf("\nchoise: ");scanf("%d",&c);
		switch(c)
		{
			case 1: printf("\n k:  ");scanf("%d",&k);
					printf("\n pos:  ");scanf("%d",&pos);
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
		printf("\ncontinue? : ");scanf("%c",&temp);scanf("%c",&ch);
	}while(ch=='y');
}			

