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
int count(struct node *start)
{
	struct node *p=start;int c=0;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}
int end(int n)
{
	struct node *slow=start,*fast=start;int c=1;
	while(c<=n)
	{
		fast=fast->next;
		c++;
	}
	while(fast!=NULL )
	{
		slow=slow->next;
		fast=fast->next;
	}
	return slow->a;
}
void main()
{
	int k,pos,n;char ch,temp;
	do
	{
		printf("\n k= ");scanf("%d",&k);
		printf("pos= ");scanf("%d",&pos);
		insert(k,pos);
		printf("\ncontinue? : ");scanf("%c",&temp);scanf("%c",&ch);
	}while(ch=='y');
	l1:
	printf("\n enter n: ");scanf("%d",&n);
	if(n>count(start))
	goto l1;
	printf("\n nth element from end= %d",end(n));
}		
