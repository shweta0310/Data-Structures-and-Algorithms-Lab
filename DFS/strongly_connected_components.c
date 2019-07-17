#include<stdio.h>
int a[20][20]={0},at[20][20]={0},vis[20]={0},n,stack[20],top=-1;

void push(int k)
{
	//printf("\nstack push: %d",k);putchar('\n');
	stack[++top]=k;
}
int pop()
{
	top--;
	//printf("\nstack: %d",stack[top+1]);putchar('\n');
	return stack[top+1];
}

void creategraph()
{
	int i,j;
	printf("\nEnter no. of vertices: ");scanf("%d",&n);
	printf("\nEnter matrix: ");
	for(i=0;i<n;i++)
	{
		putchar('\n');
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			at[j][i]=a[i][j];
		}
	}
}
void dfs(int u)
{
	int j;
	vis[u]=1;
	printf("%d ",u);
	for(j=0;j<n;j++)
	{
		if(a[u][j]==1 && vis[j]==0)
		dfs(j);
	}
	vis[u]=2;
	push(u);
	
}
void dfs_t(int u)
{
	int j;
	vis[u]=1;
	printf("%d ",u);
	for(j=0;j<n;j++)
	{
		if(at[u][j]==1 && vis[j]==0)
		dfs_t(j);
	}
	vis[u]=2;
}
void scc()
{
	int p;
	
	while(top!=-1)
	{
		putchar('\n');
		p=pop();
		if(vis[p]!=0)
		continue;
		else
		dfs_t(p);
	}
}
void cleargraph()
{
	int i;
	for(i=0;i<n;i++)
	vis[i]=0;
}
	
void main()
{
	int i,j;
	creategraph();
	
	int v;char ch;
	do
	{
		printf("\nEnter starting vertex: ");scanf("%d",&v);
		printf("\nReachable vertices in graph are: ");
		dfs(v);
		for(j=0;j<n;j++)
		{
			if(vis[j]==0 && j!=v)
			dfs(j);
		}
		cleargraph();
		printf("\nReachable vertices in transpose of graph are: ");
		dfs_t(v);
		for(j=0;j<n;j++)
		{
			if(vis[j]==0 && j!=v)
			dfs_t(j);
		}
		cleargraph();
		printf("\nStrongly connected components are : ");
		scc();
		cleargraph();
		printf("\nContinue? (y/n): ");getchar();scanf("%c",&ch);
	}while(ch=='y');
}
