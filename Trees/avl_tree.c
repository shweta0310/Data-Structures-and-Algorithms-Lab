#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int key;
	struct tree *left,*right;
}tree;
tree *root=NULL;
//functions
tree* newNode(int);
int search(tree*,int);
int height(tree*);
int bf(tree*);
tree* rotleft(tree*);
tree* rotright(tree*);
tree* LL(tree*);
tree* LR(tree*);
tree* RR(tree*);
tree* RL(tree*);
tree* insert(tree*,int);
tree* Delete(tree*,int);
void inorder(tree*);

tree* newNode(int key)
{
	tree *node=NULL;
	node=(tree*)malloc(sizeof(tree*));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int search(tree *root,int key)
{
	if(root==NULL)  
	return -1;
	else if (root->key==key)
	return root->key;
	else if(key<root->key)
	return search(root->left,key);
	else if(key>root->key)
	return search(root->right,key);
	
}

int height(tree *node)
{
	if(node==NULL)
	return 0;
	else if(height(node->left)<=height(node->right))
	return 1+height(node->right);
	else
	return 1+height(node->left);
}

int bf(tree *node)
{
	return height(node->left)-height(node->right);
}
 
tree* rotleft(tree *pivot)
{
	if(pivot==NULL)
	return pivot;
	tree *temp=pivot;
	pivot=pivot->right;
	tree *temp1=pivot->left;
	pivot->left=temp;
	temp->right=temp1;
	return pivot;
}

tree* rotright(tree *pivot)
{
	if(pivot==NULL)
	return pivot;	
	tree *temp=pivot;
	pivot=pivot->left;
	tree *temp1=pivot->right;
	pivot->right=temp;
	temp->left=temp1;
	return pivot;
}

tree* RR(tree *node)
{
	node=rotleft(node);
	return node;
}
tree* LL(tree *node)
{
	node=rotright(node);
	return node;
}
tree* LR(tree* node)
{
	node->left=rotleft(node->left);
	node=rotright(node);
}
tree* RL(tree* node)
{
	node->right=rotright(node->right);
	node=rotleft(node);
}

tree* insert(tree *node, int key)
{
	if(node==NULL)
	return newNode(key);
	else if (key<node->key)
	{
		node->left=insert(node->left,key);
		if(bf(node)>=2)
		{
			if(key<node->left->key)
			node=LL(node);
			else
			node=LR(node);
		}
	}
	else if(key>node->key)
	{
		node->right=insert(node->right,key);
		if(bf(node)<=-2)
		{
			if(key>node->right->key)
			node=RR(node);
			else
			node=RL(node);
		}
	}
	//inorder(node);
	return node;
}

tree* Delete(tree *node ,int key)
{
	tree *p;
	if(node==NULL)
	return node;
	if(search(root,key)!=-1)
	{ 
		if(node->left==NULL && node->right==NULL)
		{
			p=NULL;
			return p;
		}
		else if(key<node->key)
		{
			node->left=Delete(node->left,key);
			if(bf(node)<=-2)
			{
				if(bf(node->right)<=0)
				node=RR(node);
				else
				node=RL(node);
			}	
		}
		else if(key>node->key)
		{
			node->right=Delete(node->right,key);
			if(bf(node)>=2)
			{
				if(bf(node->left)>=0)
				node=LL(node);
				else
				node=LR(node);
			}	
		}
		else
		{
			if(node->right!=NULL)
			{
			p=node->right;
			while(p->left!=NULL)
			p=p->left;
			node->key=p->key;
			node->right=Delete(node->right,p->key);
		
			if(bf(node)>=2)
			{
				if(bf(node->left)>=0)
				node=LL(node);
				else
				node=LR(node);
			}	
			}
			else 
			return node->left;
		}
		return node;
	}
	p=NULL;
	return p;
}

void inorder(tree *root)
{
	if(root!=NULL)
	{inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);}
}	

void main()
{
	
	int option,key,ans;
	printf("1.insert\n2.delete\n3.search\n4.print\n5.quit");
	l1:
	printf("\nEnter choise: ");scanf("%d",&option);
	switch(option)
	{
		case 1:	printf("\nKey to be inserted: ");scanf("%d",&key);
				root=insert(root,key);
				
				goto l1;
		case 2:	printf("\nKey to be deleted: ");scanf("%d",&key);
				root=Delete(root,key);
				if(root==NULL)
				{
					if(search(root,key)==-1)
					printf("\nElement not found");
					else
					printf("\nTree is empty ");
				}
				else
				printf("\nDelete result: %d",root->key);
				goto l1;	
		case 3:	printf("\nKey to be searched: ");scanf("%d",&key);
				ans=search(root,key);
				printf("\nSearch result: %d",ans);
				goto l1;
		case 4:	inorder(root);
				goto l1;
		case 5:	exit(0);	
	}
}	
