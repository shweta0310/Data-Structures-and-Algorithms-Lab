#include<stdio.h>
int arr[100],top=-1;
void display(int arr[])
{
	int i;putchar('\n');
	for(i=0;i<=top;i++)
	printf("%d  ",arr[i]);
}
void push(int k)
{
	if (top==99)
	printf("\n Stack overflow");
	else
	{	top++;arr[top]=k;	}
	display(arr);
}
void pop()
{
	if(top==-1)
	printf("\n Stack underflow");
	else
	{
		printf("\n Element popped: %d",arr[top]);
		top--;
	}
	display(arr);
}
void main()
{
	int option,k;
	l1:
	printf("\n option: ");scanf("%d",&option);
	switch(option)
	{
		case 1:	printf("\n Enter element: ");scanf("%d",&k);
				push(k);
				goto l1;
	
		case 2:	pop();
				goto l1;

		default: break;
	}
}

	
