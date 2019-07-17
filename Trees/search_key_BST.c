#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *left,*right;
};
struct node *root=NULL;

struct node* create_node();
void insert(struct node*,struct node*);
 
struct node* search(struct node *root,int key)
{
	struct node *p=NULL;
	if(root==NULL || root->key==key)
	return root;
	else if(key<root->key)
	return search(root->left,key);
	else if(key>root->key)
	return search(root->right,key);
}

struct node* create_node()
{
	struct node *p=NULL;
	p=(struct node*)malloc(sizeof(p));
	int key;
	printf("\nKey: ");scanf("%d",&key);
	p->key=key;
	p->left=NULL;p->right=NULL;
	return p;
}

void insert(struct node *root, struct node *p)
{
	if(p->key<=root->key)
	{
		if(root->left!=NULL)
		insert(root->left,p);
		else
		root->left=p;
	}
	else if(p->key>root->key)
	{
		if(root->right!=NULL)
		insert(root->right,p);
		else
		root->right=p;
	}
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}

void main()
{	struct node *p,*root=NULL;
	char opt,ch;
	do
	{
		struct node *p=create_node();
		if(root==NULL)
		root=p;
		else
		insert(root,p);
		printf("\nContinue? : ");ch=getchar();scanf("%c",&opt);
	}while(opt=='y');
	putchar('\n');
	inorder(root);
	printf("\nDo you want to Search key? : ");
	ch=getchar();
	scanf("%c",&opt);
	if(opt=='y')
	{	int n;
		printf("\nSearch key: ");ch=getchar();scanf("%d",&n);
		p=search(root,n);
		if(p==NULL)
		printf("\nKey not present\n");
		else
		printf("\np= %d",p->key);
	}		
}
