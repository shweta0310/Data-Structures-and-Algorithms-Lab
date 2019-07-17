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
	printf("%d ",p->a);p=p->next;
	while(p!=start && p!=NULL)
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
		if(start==NULL)
		{p->next=NULL;start=p;}
		else
		p->next=start;
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
	else
	{
		struct node *prev=start,*cur=start->next;
		while(cur->a!=k && cur!=start)
		{
			prev=cur;
			cur=cur->next;
		}
		
		if(cur==start && cur->a==k)
		{
			struct node *p=start;
			prev->next=cur->next;
			start=start->next;
			p->next=NULL;
			free(p);
		}
		else if(cur==start && cur->a!=k)
		printf("\n element not present");
		else if(cur!=start)
		{
			prev->next=cur->next;
			cur->next=NULL;
			free(cur);
		}
		display(start);
	}
}
int search(int k)
{	int pos=1;
	struct node *p=start;
	while(p->a!=k && p!=start)
	{
		p=p->next;pos++;
	}
	if (p==start)
	{	
		if(p->a!=k)			
		{printf("\n Element not present");return -1;}
		else return 1;
	}
	else
	return pos;
}
void main()
{
	int k,pos,c,opt;char ch,temp;
	do
	{
	printf("\n choise: ");scanf("%d",&c);
	switch(c)
	{
		case 1: printf("\n k  ");scanf("%d",&k);
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
	printf("\n continue? : ");scanf("%c",&temp);scanf("%c",&ch);
	}while(ch=='y');
}		

