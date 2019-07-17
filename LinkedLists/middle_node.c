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
int find(struct node *start)
{
	struct node *slow=start,*fast=start;
	if(start!=NULL)
	{
		while(fast!=NULL && fast->next!=NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		return slow->a;
	}
}
void main()
{
	int k,pos;char ch,temp;
	do
	{
		printf("\n k= ");scanf("%d",&k);
		printf("pos= ");scanf("%d",&pos);
		insert(k,pos);
		printf("\ncontinue? : ");scanf("%c",&temp);scanf("%c",&ch);
	}while(ch=='y');
	printf("\n middle element= %d",find(start));
}
	
