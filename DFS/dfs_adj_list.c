#include<stdio.h>
#include<stdlib.h>
int time=0;
typedef struct node
{
	int vertex,d,f;
	struct node *next;
}node;
node *g[20];
int vis[20]={0};
int n;

void insert(int vi,int vj)
{
	node *p,*q;
	q=(node*)malloc(sizeof(node*));
	q->vertex=vj;
	q->next=NULL;
	if(g[vi]!=NULL)
	{
		p=g[vi];
		while(p->next!=NULL)
		p=p->next;
		p->next=q;
	}
	else
	g[vi]=q;
}

void creategraph()
{
	int i,edges,vi,vj;
	printf("\nEnter no. of edges: ");scanf("%d",&edges);
	for(i=0;i<edges;i++)
	{
		printf("\nEnter edge(vi,vj): ");scanf("%d",&vi);scanf("%d",&vj);
		insert(vi,vj);
	}
}
void display()
{
	int i=0;node *p;
	while(i<n)
	{
		putchar('\n');
		for(p=g[i];p!=NULL;p=p->next)
		printf("%d ",p->vertex);
		i++;
	}
}
void dfs_visit(node *p)
{
	int w=p->vertex,x;
	time++;
	p->d=time;
	vis[w]=1;
	printf("%d ",w);
	node *q=NULL;
	for(q=p;q!=NULL;q=q->next)
	{
		x=q->vertex;
		if(vis[x]==0 && g[x]!=NULL)
		dfs_visit(g[x]);
	}
	vis[w]=2;
	time++;
	p->f=time;
}
void dfs(int u)
{
	int j;
	if(g[u]!=NULL)
	{
		node *p=g[u];
		int w=p->vertex;
		if(vis[w]==0)
		dfs_visit(p);
	}
	for(j=0;j<n;j++)
	{	
		//putchar('\n');
		if(vis[j]==0 && j!=u)
		dfs(j);
	}
}

void main()
{
	int i;
	printf("\nNo. of vertices: ");scanf("%d",&n);
	for(i=0;i<n;i++)
	g[i]=NULL;
	for(i=0;i<n;i++)
	insert(i,i);
	creategraph();
	display();
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
