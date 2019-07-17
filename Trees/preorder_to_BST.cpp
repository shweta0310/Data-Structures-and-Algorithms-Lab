#include<iostream>
#include <limits.h> 
using namespace std;
struct node
{
	int key;
	node *left,*right;
};
node* newNode(int key)
{
	node *temp=NULL;
	temp= new node;
	temp->key=key;
	temp->left=NULL;temp->right=NULL;
	return temp;
}

node* utility(int pre[],int *preindex,int key,int min, int max, int size)
{
	if(*preindex>=size)
	return NULL;
	
	node* root=NULL;
	
	if(key>min && key<max)
	{
		root=newNode(key);
		*preindex=*preindex+1;
		if(*preindex<size)
		{
			root->left=utility(pre,preindex,pre[*preindex],min,key,size);
			root->right=utility(pre,preindex,pre[*preindex],key,max,size);
		}
	}
	return root;
}
node* construct_bst(int pre[],int size)
{
	int preindex=0;
	return utility(pre,&preindex,pre[0],INT_MIN,INT_MAX,size);
}
void inorder(node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}
int main () 
{ 
	int pre[] = {10, 5, 1, 7, 40, 50}; 
	int size = sizeof( pre ) / sizeof( pre[0] ); 

	node *root = construct_bst(pre, size); 

	cout<<"Inorder traversal of the constructed tree: \n";
	inorder(root); 

	return 0; 
} 
