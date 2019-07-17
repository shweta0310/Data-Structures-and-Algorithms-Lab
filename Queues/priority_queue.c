#include<stdio.h>
#define size 5

struct node
{
	int a,p;
};
struct node n[size];
int f=-1,r=-1;



void enqueue(int k,int pri)
{
	if(f==-1 && r==-1)
	{
		f++;r++;
		n[r].a=k;
		n[r].p=pri;
	}
	else if(f==0 && r==size-1)
	printf("\nQueue full");
	else
	{
		r++;
		n[r].a=k;
		n[r].p=pri;
	}
}
int highest()
{
	int max=n[f].p,i=f+1;
	while(i<=r)
	{
		if(n[i].p<max)
		max=n[i].p;
		i++;
	}
	return max;
}
void dequeue()
{	
	if(f==-1 && r==-1)
	printf("\nQueue empty");
	else if(f==r)
	{
		printf("\nElement deleted: %d",n[f].a);
		f=-1;r=-1;
	}
	else
	{
	int i=f,k=highest();
	while(i<=r)
	{	
		if(n[i].p==k)
		{
			printf("\nElement deleted: %d",n[i].a);
			int j=i;
			while(j<r)
			{
				n[j]=n[j+1];	
				j++;
			}
			r--;
		}
		else
		i++;
	}
	}
}

void main()
{
	int option,k,pri;
	l1:
	printf("\n option: ");scanf("%d",&option);
	switch(option)
	{
		case 1:	printf("\nEnter element: ");scanf("%d",&k);
				printf("\nEnter priority: ");scanf("%d",&pri);
				enqueue(k,pri);
				goto l1;
	
		case 2:	dequeue();
				goto l1;
		case 3: printf("\n high: %d",highest());
				break;
		
		default: break;
	}
	
}
	
