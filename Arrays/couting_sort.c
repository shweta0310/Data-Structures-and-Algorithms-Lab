#include<stdio.h>
void sort(int a[],int n)
{
	int b[10]={0},c[100],i;
	for(i=0;i<n;i++)
	b[a[i]]++;
	for(i=1;i<=9;i++)
	b[i]+=b[i-1];
	for(i=0;i<n;i++)
	{
		c[b[a[i]]]=a[i];
		b[a[i]]--;
	}	
	printf("\nSorted Array:\n ");
	for(i=1;i<=n;i++)
	printf("%d ",c[i]);
}
void main()
{
	int a[100],n,i;
	printf("\nSize: ");scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,n);
}
	
