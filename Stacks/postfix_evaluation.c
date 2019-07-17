#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
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
}
int pop()
{	int k;
	/*if(top==NULL)
	printf("\n Stack Underflow");*/
		struct node *p=top;
		k=p->data;
		top=top->next;
		free(p);
		return k;
}
void postfix(char s[100])
{
	int i=0,k,flag=0;
	while(s[i]!='\0')
	{
		switch(s[i])
		{
			case '+':	k=pop();
						if(top!=NULL)
						top->data=top->data+k;
						else 
						flag=1;
						break;
			case '-':	k=pop();
						if(top!=NULL)
						top->data=top->data-k;else 	flag=1;
						break;
			case '*':	k=pop();
						if(top!=NULL)
						top->data=top->data*k;else 	flag=1;
						break;
			case '/':	k=pop();
						if(top!=NULL)
						top->data=top->data/k;	else 	flag=1;
						break;
			case '%':	k=pop();
						if(top!=NULL)
						top->data=top->data%k;else 	flag=1;	
						break;
			case '^':	k=pop();
						if(top!=NULL)
						top->data=(int)(pow(top->data,k));else 	flag=1;	
						break;
			default:	push(s[i]-48);
						break;
		}
		i++;
	}	
	if(flag==1)
	printf("\n Invalid expression");
	printf("\n Evaluation of postfix expression: %d",top->data);
}
void main()
{
	char s[100];
	printf("\n Enter postfix expression: ");gets(s);
	postfix(s);
}
