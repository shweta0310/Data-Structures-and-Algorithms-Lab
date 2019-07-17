#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node1
{
	char key;
	struct node1 *left,*right;
};
struct node1 *root=NULL;
struct node1 *s[10];
int top=-1;
//struct node *top=NULL;
int isOperator(char c)
{
	if(c=='+' ||c=='-' ||c=='*' ||c=='/')
	return 1;
	else 
	return 0;
}
struct node1* create(char k)
{
	struct node1 *p=NULL;
	p=(struct node1*)malloc(sizeof(p));
	/*char key;
	printf("\nKey: ");scanf("%c",&key);*/
	p->key=k;
	p->left=NULL;p->right=NULL;
	return p;
}

void inorder(struct node1 *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%c ",root->key);
		inorder(root->right);
	}
}
void push(struct node1 *t)
{
	s[++top]=t;
}
struct node1* pop()
{
	return(s[top--]);
}

void exp_tree(char *e)
{	struct node1 *t;
	if(isalnum(*e))
	{
		t=create(*e);
		push(t);
		
	}
	else if (isOperator(*e)==1)
	{
		t=create(*e);
		t->right=pop();
		t->left=pop();
		push(t);
		
	}
	
}
		
		
void main()
{
	char *p,str[100];
	printf("\npostfix: ");gets(str);
	p=str;int i=0;
	while(str[i]!='\0')
	{
		exp_tree(p);
		p++;
		i++;
	}
	inorder(s[top]);
}

