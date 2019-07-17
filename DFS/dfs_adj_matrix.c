#include<stdio.h>
int a[20][20]={0},vis[20]={0},n;

void creategraph()
{
	int i,j;
	printf("\nEnter no. of vertices: ");scanf("%d",&n);
	printf("\nEnter matrix: ");
	for(i=0;i<n;i++)
	{
		putchar('\n');
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
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
	for(j=0;j<n;j++)
	{
		if(vis[j]==0 && j!=u)
		dfs(j);
	}
}
void main()
{
	int i;
	creategraph();
	
	int v;char ch;
	do
	{
		printf("\nEnter starting vertex: ");scanf("%d",&v);
		printf("\nReachable vertices are: ");
		dfs(v);
		for(i=0;i<n;i++)
		vis[i]=0;
		printf("\nContinue? (y/n): ");getchar();scanf("%c",&ch);
	}while(ch=='y');
}
