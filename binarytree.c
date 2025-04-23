#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};  					
struct node *getnode(){
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	return ptr;
}
struct node *creation(){
	int data;
	struct node *ptr = getnode();
	printf("\n>");
	scanf("%d",&data);
	if(data == -1)
		return NULL;
	
	else{
		ptr->data = data;
		printf("\nEnter the left child: ");
		ptr->left = creation();
		printf("\nEnter the right child: ");
		ptr->right = creation();
	}
	return ptr;
}
void preorder(struct node *root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int main(){
	struct node *root = creation();
	printf("Preorder:\n");
	preorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\nPostorder:\n");
	postorder(root);
	return 0;
}
