#include<stdio.h>
#define max 10
int tree[max]={0},i=0,j=0;
void display();
void insert(int val)
{
	int ch;
	if(tree[i]==0)
	tree[i]=val;
	else
	{
		while(j<=max)
		{
			printf("\nLeft (0) or Right (1) child: ");scanf("%d",&ch);getchar();
			if(ch==0)
			j=(2*i)+1;
			else if (ch==1)
			{j=(2*i)+2;i++;}
			if(tree[j]!=0)
			{	i++; continue;	}
			else
			{tree[j]=val;break;}
		}
	}
	display();
}
void display()
{
	int i;putchar('\n');
	for(i=0;i<max;i++)
	printf("%d ",tree[i]);
}
void search(int k)
{
	if(k==0)
	printf("\n root node");
	else if(k%2==0)
	printf("\n Parent of %d: %d",tree[k],tree[(k-2)/2]);
	else
	printf("\n Parent of %d: %d",tree[k],tree[(k-1)/2]);
	
	int l,r;
	l=(2*k)+1;
	r=(2*k)+2;
	if(tree[l]==0 && l>=)
	printf("\nNo left child of %d",tree[k]);
	else 
	printf("\nLeft child of %d is %d",tree[k],tree[l]);
	if(tree[r]==0 && r>=max-1)
	printf("\nNo right child of %d",tree[k]);
	else 
	printf("\nRight child of %d is %d",tree[k],tree[r]);
}
void main()
{
	int val,k;char ch;

	do
	{
		printf("\nEnter value: ");scanf("%d",&val);getchar();
		insert(val);
		printf("\nContinue(y/n): ");scanf("%c",&ch);
	}while(ch=='y');
	display();
	printf("\nEnter search index: ");scanf("%d",&k);
	search(k);
}
