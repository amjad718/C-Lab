#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
void front();
int a;
struct node{
	int data;
	struct node *next;
} *current, *head=NULL, *temp, *newnode;

void main()
{
	do
	{
		printf("\n OPTIONS \n 1.Push \n 2.Pop \n 3.Display Front \n 4.Display \n 0.Exit");
		scanf("%d",&a);
		switch(a)
		{
			case 1: enqueue();
			break;
			case 2: dequeue();
			break;
			case 4: display();
			break;
			case 3: front();
			break;
			default: printf("Invalid Choice \n");
			break;
		}
	}while(a!=0);
} 

void enqueue(){
	newnode=malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the item to insert");
	scanf("%d",&newnode->data);
	if(head==NULL){
		head=newnode;
	}
	else{
		current=head;
		while(current->next!=NULL){
			current=current->next;		
		}
		current->next=newnode;
	}
}

void dequeue(){
	if(head==NULL){
		printf("Queue Underflow");
	}
	else{
		current=head;
		head=head->next;
		printf("The deleted element is %d",current->data);
		free(current);
	}
}

void front(){
	if(head==NULL){
		printf("The queue is empty");
	}
	else{
		printf("%d is the element in the front",head->data);
	}
}

void display(){
	if(head==NULL){
		printf("The queue is empty");
	}
	else{
		for(current=head;current!=NULL;current=current->next){
			printf("%d \t",current->data);
		}
	}
}
