#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int a;
struct node{
	int data;
	struct node *next;
} *newnode, *current,*temp, *top=NULL;

void main()
{
	do
	{
		printf("\n OPTIONS \n 1.Push \n 2.Pop \n 3.Display \n 0.Exit");
		scanf("%d",&a);
		switch(a)
		{
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: display();
			break;
			default: printf("Invalid Choice \n");
			break;
		}
	}while(a!=0);
}


void push(){
	newnode=malloc(sizeof(struct node));
	printf("Enter the item to insert");
	scanf("%d",&newnode->data);
	if(top==NULL){
		newnode->next=NULL;
		top=newnode;	
	}
	else{
		newnode->next=top;
		top=newnode;
	}
}

void pop(){
	if(top==NULL){
		printf("Stack Underflow");
	}
	else{
		temp=top;
		top=top->next;
		printf("The popped item is %d",temp->data);
		free(temp);
	}
}

void display(){
	if(top==NULL){
		printf("The stack is empty");
	}
	else{
		for(current=top;current->next!=NULL;current=current->next){
			printf("%d\n",current->data);
		}
	}
	printf("%d",current->data);
}
