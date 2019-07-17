#include<stdio.h>
#include<stdlib.h>
#define size 20
typedef struct queue
{
	int data[size];
	int r,f;
}queue;
typedef struct node
{
	int vertex;
	struct node *next;
}node;

node *g[20];
int n;

void enqueue(queue *p,int data)
{
	if(p->f==-1 && p->r==-1)
	{
		p->r=0;p->f=0;
		p->data[p->r]=data;
	}
	else
	{
		p->r++;
		p->data[p->r]=data;
	}
}
int dequeue(queue *p)
{	int temp;
	if(p->f==p->r && p->f!=-1)
	{
		temp=p->data[p->f];
		p->f=-1;p->r=-1;
		return temp;
	}
	else if(p->f!=-1)
	{
		temp=p->data[p->f];
		p->f++;
		return temp;
	}
}
int empty(queue *p)
{
	if(p->f==-1 && p->r==-1)
	return 1;
	return 0;
}	
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
	printf("\nNo. of vertices: ");scanf("%d",&n);
	int i,edges,vi,vj;
	for(i=0;i<n;i++)
	g[i]=NULL;
	printf("\nEnter no. of edges: ");scanf("%d",&edges);
	for(i=0;i<edges;i++)
	{
		printf("\nEnter edge (vi, vj): ");
		scanf("%d",&vi);
		scanf("%d",&vj);
		insert(vi,vj);
		insert(vj,vi);
	}
}
void bfs(int v)
{
	int w,i,vis[size]={0};
	queue q;
	node *p;
	
	q.r=q.f=-1;
	enqueue(&q,v);
	vis[v]=1;
	while(!empty(&q))
	{
		v=dequeue(&q);
		for(p=g[v];p!=NULL;p=p->next)
		{
			w=p->vertex;
			if(vis[w]==0)
			{
				enqueue(&q,w);
				vis[w]=1;
				printf(" %d",w);
			}	
		}
	}
}

void main()
{
	creategraph();
	int v;char ch;
	do
	{
		printf("\nEnter starting vertex: ");scanf("%d",&v);
		printf("\nReachable vertices in the graph are: %d",v);
		bfs(v);
		printf("\nContinue? (y/n): ");getchar();scanf("%c",&ch);
	}while(ch=='y');
}
