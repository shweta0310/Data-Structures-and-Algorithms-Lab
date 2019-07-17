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
int search(int a[], int ele, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==ele)
		break;
	}
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
	
}

int* buildmaxheap(int a[],int n)
{
	int j;
	for(j=n/2;j>=0;j--)
	maxheapify(a,j,n);
	return a;
}

int extract(int a[],int pos,int heapsize)
{		int max;
		if(heapsize<=0)
		printf("\nHeap Empty");
		else
		{
			max=a[pos];
			a[pos]=a[heapsize-1];
			heapsize--;
			int *p=buildmaxheap(a,heapsize);
			display(p,heapsize);
		}
		return max;
}
void main()
{
	int a[MAX],n,*ptr,ele;
	printf("\nSize: ");scanf("%d",&n);putchar('\n');
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	ptr=buildmaxheap(a,n);
	display(ptr,n);
	printf("\nElement to be deleted: ");scanf("%d",&ele);
	int t=search(a,ele,n),temp;
	if(t==n)
	printf("\nElement not present");
	else
	temp=extract(ptr,t,n);
}
