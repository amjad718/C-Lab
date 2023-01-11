#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	int data;
	struct node *right;
};

struct node* set(int data){
		struct node* newnode = malloc(sizeof(struct node));
		newnode -> data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
}

struct node* insertion(struct node* head, int key){
	if(head==NULL){
		return set(key);
	}
	if(key<head->data){
		head->left = insertion(head->left,key);
	}
	else if(key>head->data){
		head->right = insertion(head->right,key);
	}
	return head;
}

void preorder(struct node *root){
	if(root!=NULL){
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}	

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d->",root->data);
	}
}

void display(struct node *root){
	if(root==NULL){
		printf("The tree is empty");
	}
	else{
		printf("The root of the tree is %d",root->data);
	}
}

void main(){

	struct node* root = NULL;
	int choice,data,n,i;
	do{
	
		printf("Enter a choice : \n1.Creation \n2.insertion of node\n3.Preorder traverse\n4.Inorder traverse\n5.Post order traverse \n6.Dispaly root node\n7.Deletion \n0.Exit\n\n");
		scanf("%d",&choice);

		switch(choice){
			case 1 : {
					printf("Enter the number of nodes you want to add");
					scanf("%d",&n);
					for(i=0;i<n;i++){
						printf("Enter the data :");
				    		scanf("%d",&data);
						root=insertion(root,data);
					}
					break;
				 }
			case 2: {
					printf("Enter the data to insert");	
					scanf("%d",&data);
					root=insertion(root,data);
				}
			case 3 : {
					preorder(root);
					break;
				 }
			case 4 : {
					 inorder(root);
					 break;
				 }
			case 5 : {
					 postorder(root);
					 break;
				 }
			case 6 : {
					 display(root);
					 break;
				 }
			case 7 : {
					printf("Enter the item to delete");
					scanf("%d",&data);
								
				 }
			case 0 : {
					printf("Exiting....!\n");
					break;
				 }
			default : {
					  printf("Wrong input\n");
					  break;
				  }
		}
	}while(choice != 0 );
}
