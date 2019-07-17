#include<stdio.h>
int a[100],n;
int func(int sum, int i,int n)
{
	int j;
	for(j=i+1;j<n;j++)
	{
		if(sum==a[i])
		return 1;
	}
	return 0;
}
void main()
{
	int sum,i,ans,flag=0;
	printf("\n array size: ");scanf("%d",&n);
	printf("\n sum: ");scanf("%d",&sum);
	int k=sum;
	for(i=0;i<n;i++)
	{
		putchar(' ');
		scanf("%d",&a[i]);
	}	
	for(i=0;i<n;i++)
	{
		k-=a[i];
		ans=func(k,i,n);
		if(ans==1)
		{printf("\n TRUE");flag=1;}
		else if(ans==0)
		k+=a[i];
	}
	if(flag==0)
	printf("\n FALSE");
}
