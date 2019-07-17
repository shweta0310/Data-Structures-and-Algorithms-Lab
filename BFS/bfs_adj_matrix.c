#include<stdio.h>
int a[20][20],q[20],vis[20],n,f=0,r=-1;
void bfs(int v)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[v][i] && !vis[i])
		{
			q[++r]=i;
			//printf("\n %d",i);
		}
		if(f<=r)
		{
			vis[q[f]]=1;
			bfs(q[f++]);
		}
	}
}
void main()
{
	printf("\nNo. of vertices: ");scanf("%d",&n);
	int i,j,v;
	for(i=1;i<=n;i++)
	{
		q[i]=0;
		vis[i]=0;
	}
	printf("\nEnter graph in matrix form: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("\nEnter staring vertex: ");scanf("%d",&v);
	bfs(v);
	printf("\nReachable vertices in the graph are : ");
	
	for(i=1;i<=n;i++)
	{
		if(vis[i]==1)
		printf("%d ",i);
		else
		{
			//printf("\nBFS not possible");
			break;
		}
	}
}
