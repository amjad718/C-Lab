#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int n;
struct node* set(int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}


struct node* insertion(struct node* newnode,int key){
	if (newnode == NULL){
		return set(key);
	}
	if (key < newnode->data){
		newnode->left = insertion(newnode->left, key);
	}
	else if (key > newnode->data){
		newnode->right = insertion(newnode->right, key);
	}
	return newnode;
}


void display(struct node *root){
	if(root==NULL){
    printf("Tree is empty....!");
	}
	else{
	printf("Root node: %d",root->data);
	}	
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
void main(){

	struct node* root = NULL;
	int choice,data;
	do{
	
		printf("Enter a choice : \n1.insertion of node\n2.Preorder traverse\n3.Inorder traverse\n4.Post order traverse \n5.Display root node\n 6.Creation 0.Exit\n\n");
		scanf("%d",&choice);

		switch(choice){
			case 1 : {
					printf("Enter the data :");
				    	scanf("%d",&data);
					root=insertion(root,data);
					break;
				 }
			case 2 : {
					preorder(root);
					break;
				 }
			case 3 : {
					 inorder(root);
					 break;
				 }
			case 4 : {
					 postorder(root);
					 break;
				 }
			case 5 : {
					 display(root);
					 break;
				 }
			case 6 : {
					printf("Enter the number of data you want to insert");
					scanf("%d,&n");
					for(i=0;i<n;i++){
					printf("Enter the data :");
				    	scanf("%d",&data);
					root=insertion(root,data);}
					break;
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

