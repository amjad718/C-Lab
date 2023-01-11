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
void reverse();
int i,n,a;
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *newnode,*current, *ptr, *temp, *head=NULL;
void main()
{
    do
	{
		printf("\n OPTIONS \n 1.Insertion \n 2.Traversing \n 3.Searching \n 4.Addition at the end \n 5.Addition after a specific element \n 6.Addition at the beginning \n 7.Deletion at the end \n 8.Deletion of a specific element \n 9.Deletion at the beginning \n 10.Reverse of the linked list \n 0.Exit");
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
			case 10: reverse();
			break;
			default: printf("Invalid Choice \n");
			break;
		}
	}while(a!=0);
}

void reverse(){
    current = head;
    if(head==NULL){
        printf("The linked list is empty");
    }
    else{
        current = head;
        while (current->next!=NULL){
            current = current->next;
        }
        while(current!=NULL){
            printf("\t <-%d-> \t",current->data);
            current = current->prev; 
        }
    }
}

void insertion()
{
	printf("Enter the no of data to be inserted ");
	scanf("%d",&n);
	printf("Enter the data \n");
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=newnode;
			current=newnode;
			newnode -> prev=NULL;
		}
		else
		{
			current->next=newnode;
			newnode->prev=current;
			current=newnode;
		}
	}
}

void traverse()
{
	if(head==NULL)
	{
		printf("The linked list is empty");
	}
	else
	{
		for(current=head;current!=NULL;current=current->next)
		{
			printf("\t <-%d-> \t",current -> data);
		}
	}
}

void search()
{
	int item,count=1;
	printf("Enter the item to search");
	scanf("%d",&item);
	if(head==NULL)
	{
		printf("The linked list is empty");
	}
	else
	{
		for(current=head;current->data!=item && current->next!=NULL;current=current->next)
		{
			count++;
		}
		if(current->data==item)
		{
			printf("Element is found at the position %d",count);
		}
		else
		{
			printf("Element is not in the linked list");
		}
	}
}

void addend()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data to be added");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		newnode->prev=NULL;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newnode->prev=temp;
		temp->next=newnode;
	}
}



void addspec()
{
	int item;
	current=head;
	newnode=malloc(sizeof(struct node));
	printf("Enter the item to add");
	scanf("%d",&newnode->data);
	printf("Enter the location to add");
	scanf("%d",&item);
	while(current->data!=item)
	{
		current=current->next;
	}
	newnode->next=current->next;
	newnode->prev=current;
	current->next->prev=newnode;
	current->next=newnode;
}

void addbeg()
{
	newnode=malloc(sizeof(struct node));
	printf("Enter the item to add in the list");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	newnode->next=head;
	head=newnode;
}

void deleteend()
{
	current=head;
	temp=current;
	if(head==NULL)
	{
		printf("There is nothing to delete");
	}
	else
	{	
		if(head->next==NULL){
			free(ptr);
			head=NULL;
		}else{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
	}}
}

void deletespec()
{
	struct node *preptr;
	int item;
	printf("Enter the location before the item you desire to delete");
	scanf("%d",&item);
	temp=head;
	if(head==NULL)
	{
		printf("The linked list is empty");
	}
	else
	{
		while(temp->data!=item)
		{
			temp=temp->next;
		}
		preptr=temp->next;
		ptr=preptr->next;
		temp->next=preptr->next;
		ptr->prev=preptr->prev;
		free(preptr);
	}
}


void deletebeg()
{
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
}

