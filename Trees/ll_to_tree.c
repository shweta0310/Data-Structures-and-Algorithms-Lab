#include<stdio.h>
#include<stdlib.h>
struct node
{
	int a;
	struct node* left,*right;
};
//struct node *root=NULL;
struct node* insert()
{
	struct node *p;
	int val;
	printf("\nEnter value: ");scanf("%d",&val);
	if(val==-1)
	return NULL;
	p=(struct node*)malloc(sizeof(p));
	p->a=val;
	printf("\nLeft child of %d :",p->a);
	p->left=insert();
	printf("\nRight child of %d :",p->a);
	p->right=insert();
	return p;
}
void preorder(struct node *t)
{	
	if(t!=NULL)
	{
		printf("%d ",t->a);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(struct node *t)
{	
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d ",t->a);
		inorder(t->right);
	}
}
void postorder(struct node *t)
{	
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d ",t->a);
	}
}
void main()
{
	int ch,k=1;
	struct node *root=insert();
	while(k<=3)
	{printf("\nDisplay tree : ");scanf("%d",&ch);
	switch(ch)
	{
		case 1: preorder(root);
				break;
		case 2: inorder(root);
				break;
		case 3: postorder(root);
				break;
	}
	k++;
	}
	
}
