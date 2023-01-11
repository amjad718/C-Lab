#include<stdio.h>
#define N 5
int front=-1,rear=-1,queue[N];
void enqueue();
void dequeue();
void display();
void top();
void main()
{
	int choice;
	do{
	printf("Enter the choice: \n 1.Enqueue \n 2.Dequeue \n 3.View the element in the Front \n 4.Display the Queue elements \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:enqueue();
		break;
		case 2: dequeue();
		break;
		case 3: top();
		break;
		case 4: display();
		break;
		default: printf("Invalid Choice \n");			
	}
	}while(choice!=0);
}



void enqueue()
{
	int item;
	printf("Enter the element to be added \n");
	scanf("%d",&item);
	if((rear+1)%N==front)
	{
		printf("Overflow \n");	
	}
	else if(rear==-1 && front==-1)
	{
		front=rear=0;
		queue[rear]=item;
	}
	else
	{
		rear = (rear+1)%N;
		queue[rear]=item;	
	}
}	
void dequeue()
{
	int item;
	if(rear==-1 && front==-1)
	{
		printf("Underflow \n");	
	}
	else if(front==rear)
	{
		printf("The deleted item is %d \n",queue[front]);
		front=rear=-1;
	}
	else
	{
		printf("The deleted item is %d \n",queue[front]);
		front = (front+1)%N;
	}
}
void top()
{
	if(rear==-1 && front==-1)
	{
		printf("Queue is empty \n");
	}
	else
 	{
		printf("The element in the front is %d \n",queue[front]);
	}
}
void display()
{
	int i;
	if(front <=rear){
		if(rear==-1 && front==-1)
		{
			printf("The queue is empty \n");
		}
		else
		{
			for(i=front;i<=rear;i++){
				printf("%d \t",queue[i]);
			}
		}}
	else{
		for(i=front;i<N;i++){
			printf("%d \t",queue[i]);
		}
		for(i=0;i<=rear;i++){
			printf("%d \t",queue[i]);	
		}
	}
}	
