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
void main()
{
	int k,pos;char ch,temp;
	do
	{
		printf("\n k= ");scanf("%d",&k);
		printf("\t pos= ");scanf("%d",&pos);
		insert(k,pos);
		printf("\n continue? : ");scanf("%c",&temp);scanf("%c",&ch);
	}while(ch=='y');
	printf("\n no. of nodes= %d",count(start));
}
	
