#include<stdio.h>
#define N 100
int t=-1;
void push();
void pop();
void display();
void top();
void main()
{
	int choice;
	do{
	printf("Enter the choice: \n 1.Push \n 2.Pop \n 3.View the element in the top \n 4.Display the stack elements \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:push();
		break;
		case 2: pop();
		break;
		case 3: top();
		break;
		case 4: display();
		break;
		default: printf("Invalid Choice");			
	}
	}while(choice!=0);
}
void push()
{
	int item,stack[N];
	printf("Enter the element to be added \n");
	scanf("%d",&item);
	if(t==N-1)
	{
		printf("Stack Overflow");	
	}
	else
	{
		t++;
		stack[t]=item;	
	}
}	
void pop()
{
	int item,stack[N];
	if(t==-1)
	{
		printf("Stack Underflow");	
	}
	else
	{
		item=stack[t];
		t--;
		printf("The deleted item is %d \n",item);
	}
}
void top()
{
    int stack[N];
	if(t==-1)
	{
		printf("Stack is empty");
	}
	else
 	{
		printf("%d",stack[t]);
	}
}
void display()
{
	int i,stack[N];
	printf("The Stack is: \n");
	if(t==-1)
	{
		printf("The Stack is Empty");
	}
	else
	{
		for(i=t;i>=0;i--)
			printf("%d \n",stack[i]);
	}
}
