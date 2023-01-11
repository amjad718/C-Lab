#include<stdio.h>
#include<stdlib.h>
void insertion();
void traverse();
void search();
void addend();
void addspec();
void addbeg();
void deleteend();
void deletespec();
void deletebeg();
int i,n,a;
struct node
{
	int data;
	struct node *next;
};
struct node *newnode, *end, *current, *temp, *head=NULL, *preptr, *ptr;
void main()
{
	do
	{
		printf("\n OPTIONS \n 1.Insertion \n 2.Traversing \n 3.Searching \n 4.Addition at the end \n 5.Addition after a specific element \n 6.Addition at the beginning \n 7.Deletion at the end \n 8.Deletion of a specific element \n 9.Deletion at the beginning \n 0.Exit");
		scanf("%d",&a);
		switch(a)
		{
			case 1: insertion();
			break;
			case 2: traverse();
			break;
			case 3: search();
			break;
			case 4: addend();
			break;
			case 5: addspec();
			break;
			case 6: addbeg();
			break;
			case 7: deleteend();
			break;
			case 8: deletespec();
			break;
			case 9: deletebeg();
			break;
			default: printf("Invalid Choice \n");
			break;
		}
	}while(a!=0);
}

void insertion()
{

	printf("Enter the no of elements");
	scanf("%d",&n);	
	printf("Enter the elements in to the linked list: \n");
	for(i=0;i<n;i++)
	{
		newnode=malloc(sizeof(struct node));
		scanf("%d",&newnode->data);		
	
	if(head==NULL)
	{
		head=newnode;
		end=newnode;
		newnode->next=newnode;	
	}
	else
	{
		end->next=newnode;
		end=newnode;
		newnode->next=head;
	}
}
}

void traverse(){
	if(head==NULL){
		printf("The linked list is empty");
	}
	else{
		for(current=head;current!=end;current=current->next){
			printf("%d-->",current->data);
		}
		printf("%d",current->data);
	}
}

void search(){
	int item,flag,count=0;
	if(head==NULL){
		printf("The linked list is empty");	
	}
	else{
		printf("Enter the item you want to search");
		scanf("%d",&item);
		for(current=head;current!=end;current=current->next){
			count++;	
			if(current->data==item){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("The item is found at the %d position",count);
		}
		else{
			printf("The element is not found");
		}
	}
}

void addend(){
	newnode=malloc(sizeof(struct node));
	printf("Enter the element to insert");
	scanf("%d",&newnode->data);
	if(head==NULL){
		newnode->next=NULL;
		head=newnode;
		end=newnode;
	}
	else{
		for(current=head;current!=end;current=current->next){
			newnode->next=head;
			end->next=newnode;
			end=newnode;
		}
	}
}

void addspec(){
	int item;
	newnode=malloc(sizeof(struct node));
	if(head==NULL){
		newnode->next=NULL;
		head=NULL;
		end=NULL;
	}
	else{
		printf("Enter the element after you want to add new element");
		scanf("%d",&item);
		printf("Enter the element you want to add");
		scanf("%d",&newnode->data);
		while(current->data!=item){
			current=current->next;
		}
		newnode->next=current->next;
		current->next=newnode;
	}
}

void addbeg(){
	newnode=malloc(sizeof(struct node));
	printf("Enter the element to add");
	scanf("%d",&newnode->data);
	if(head==NULL){
		newnode->next=newnode;
		head=newnode;
		end=newnode;
	}
	else{
		newnode->next=head;
		head=newnode;
		end->next=newnode;
	}
	
}

void deleteend(){
	if(head==NULL){
		printf("Underflow");
	}
	else{
		ptr=head;
		while(ptr!=end)	{
			preptr=ptr;
			ptr=ptr->next;
		}	
		preptr->next=head;
		end=preptr;
		free(ptr);
	}
}

void deletespec(){
	int item;
	if(head==NULL){
		printf("Underflow");
	}
	else{
		printf("Enter the item after you want to delete");
		scanf("%d",&item);
		ptr=head;
		while(ptr->data!=item){
			ptr=ptr->next;
			preptr=ptr;	
		}
		preptr=ptr->next;
		ptr->next=preptr->next;
		free(preptr);
	}		
}

void deletebeg(){
	if(head==NULL){
		printf("Underflow");
	}
	else{
		ptr=head;
		head=head->next;
		free(ptr);
	}
}
