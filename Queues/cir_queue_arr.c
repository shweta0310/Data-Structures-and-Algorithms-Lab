#include<stdio.h>
#define size 5
int arr[size],f=-1,r=-1;
void display(int arr[])
{	int i=f;
	putchar('\n');
	if(f<=r)
	{
		while(i<=r)
		{printf("%d ",arr[i]);i++;}
	}
	else
	{
		while(i<size)
		{printf("%d ",arr[i]);i++;}
		i=0;
		while(i<=r)
		{printf("%d ",arr[i]);i++;}
	}
}
void enqueue(int k)
{
	if(f==-1&&r==-1)
	{	
		f++;r++;arr[r]=k;
	}
	else if((f==0&&r==size-1)||(f-r==1))
	printf("\nQueue full");
	else if(r==size-1)
	{
		r=0;arr[r]=k;
	}
	else
	{
		r++;arr[r]=k;
	}
	display(arr);
}
void dequeue()
{
	if(f==-1&&r==-1)
	printf("\nQueue empty");
	else if(f==r)
	{
		printf("\nElement deleted: %d",arr[f]);
		f=-1;r=-1;
	}
	else if(f==size-1)
	{
		printf("\nElement deleted: %d",arr[f]);
		f=0;
		display(arr);
	}
	else
	{
		printf("\nElement deleted: %d",arr[f]);
		f++;
		display(arr);
	}
}
/*void search(int k)
{
	int i=f,pos;
	if(f<=r)
	{
		while(i<=r && arr[i]!=k)
		i++;
		if(i>r)
		pos= -1;
		else
		pos=i+1;		
	}
	else 
	{	int flag=0;
		while(i<size)
		{
			if(arr[i]==k)
			{flag=1;break;}
		}
		if(flag==0)
		{
			i=0;
			while(i<=r)
			{
				if(arr[i]==k)
				{flag=1;break;}
			}	
		}
		if(flag==1)
		pos=i+1;
		else
		pos=-1;
		if(pos==-1)
		printf("\nElement not in queue");
		else
		printf("\nElement at postion: %d",pos);
	}
}*/
void main()
{
	int option,k;
	l1:
	printf("\n option: ");scanf("%d",&option);
	switch(option)
	{
		case 1:	printf("\n Enter element: ");scanf("%d",&k);
				enqueue(k);
				goto l1;
	
		case 2:	dequeue();
				goto l1;
		/*case 3:	printf("\n Enter element: ");scanf("%d",&k);
				search(k);
				goto l1;*/

		default: break;
	}
}
