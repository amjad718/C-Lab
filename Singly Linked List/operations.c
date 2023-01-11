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
struct node *newnode, *current, *temp, *head=NULL;
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
	printf("Enter the no of data to be inserted");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d->",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
			current=newnode;
		}
		else
		{
			current->next=newnode;
			current=newnode;
		}
	}
}

void traverse()
{
	printf("Linked List:");
	if(head==NULL)
	{
		printf("The linked list is empty");	
	}
	for(current=head;current!=NULL;current=current->next)
	{
		printf("%d->",current->data);
	}
}

void search()
{
	int item,count=1;	
	if(head==NULL)
	{
		printf("Empty Linked List");
	}
	printf("Enter the item to be searched \n");
	scanf("%d",&item);
	for(current=head;current->data!=item;current=current->next)
	{
		count++;
	}
	if(current->data==item)
	{
		printf("Item is found at the %d linked list",count);
	}
	else
	{
		printf("The element is not found");
	}
}


void addend()
{
	newnode=(struct node*)malloc(sizeof(newnode));
	newnode->next=NULL;
	printf("Enter the data to add");
	scanf("%d->",&newnode->data);
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void addspec()
{
	int item;
	struct node *ptr;
	newnode=(struct node*)malloc(sizeof(newnode));
	printf("Enter the data to be inserted");
	scanf("%d->",&newnode->data);
	printf("Enter the item where you have to insert the data");
	scanf("%d",&item);
	if(head==NULL)
	{
		head=newnode;
		newnode->next=NULL;
	}
	else
	{	
		ptr=head;
		while(ptr->data!=item)
		{
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;				
	}
	
}
void addbeg()
{
	newnode=(struct node*)malloc(sizeof(newnode));
	printf("Enter the data to be inserted \n");
	scanf("%d->",&newnode->data);
	newnode->next=head;
	head=newnode;
}

void deleteend()
{
	struct node *preptr, *ptr;
	if(head==NULL)
	{
		printf("Underflow");	
	}
	else
	{		
		ptr=head;
		while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;	
		}
		preptr->next=NULL;	
		free(ptr);
	}
}

void deletebeg()
{
	if(head==NULL)
	{
		printf("Underflow");
	}
	else
	{
		struct node *ptr, *preptr;
		ptr=head;
		preptr=ptr;
		ptr=ptr->next;
		free(preptr);
		head=ptr;			
	}
}

void deletespec()
{
		int item;
		struct node *ptr, *preptr;
		if(head==NULL)
		{
			printf("Linked List Underflow");
		}
		else
		{
			ptr=head;
			preptr=ptr;
			printf("Enter the item before the item you wish to delete \n");
			scanf("%d",&item);
			while(preptr->data!=item)
			{
				preptr=ptr;
				ptr=ptr->next;				
			}
			temp=ptr;
			preptr->next=ptr->next;
			free(temp);
		}
}
