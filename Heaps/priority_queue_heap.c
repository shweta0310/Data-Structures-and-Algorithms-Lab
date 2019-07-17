#include<stdio.h>

#define MAX 10

void display(int a[],int n)
{	putchar('\n');
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
void swap(int *p, int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
}
int parent(int n)
{	int i;
	(n%2==0)?(i=n/2-1):(i=n/2);
	return i;
}
void maxheapify(int a[],int i,int heapsize)
{
	int left=(2*i)+1;
	int right=(2*i)+2;
	int largest;
	if(left<heapsize)
	{
		if(a[left]>a[i])
		largest=left;
		else
		largest=i;
		if((right<heapsize)&&(a[right]>a[largest]))
		largest=right;
		
		if(largest!=i)
		{
			swap(&a[i],&a[largest]);
			maxheapify(a,largest,heapsize);
		}
		
	}
	else
	return;	
}

int* buildmaxheap(int a[],int n)
{
	int j;
	for(j=n/2;j>=0;j--)
	maxheapify(a,j,n);
	return a;
}

void heapinsert(int a[],int data, int heapsize)
{
	if(heapsize>=MAX)
	printf("\nQueue full");
	else
	{
		heapsize++;
		a[heapsize-1]=data;
		int i=heapsize-1;
		while(i>0 && a[i]>a[parent(i)])
		{
			swap(&a[i],&a[parent(i)]);
			i=parent(i);
		}
	}
	int *p=a;
	display(p,heapsize);
}

int extract(int a[],int heapsize)
{		int max;
		if(heapsize<=0)
		printf("\nQueue Empty");
		else
		{
			max=a[0];
			a[0]=a[heapsize-1];
			heapsize--;
			int *p=buildmaxheap(a,heapsize);
			display(p,heapsize);
		}
		return max;
}
		
void main()
{
	int a[MAX],n,*ptr;
	printf("\nSize: ");scanf("%d",&n);putchar('\n');
	int i,size=n;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	ptr=buildmaxheap(a,n);
	display(ptr,n);
	int option,m;
	l1:
	printf("\nEnter option ");scanf("%d",&option);
	switch(option)
	{
		case 1: printf("\nEnter Element: ");scanf("%d",&m);
				heapinsert(ptr,m,n);
				size++;
				goto l1;
		case 2:	m=extract(ptr,size);
				printf("\nElement removed: %d",m);
				goto l1;
		default:	break;
	}
}
