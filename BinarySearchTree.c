#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data){
	struct Node *node= (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printInorder(struct Node *node){
	if(node==NULL) return;
	printInorder(node->left);
	printf(" %d ",node->data);
	printInorder(node->right);
}	

void printPreorder(struct Node *node){
	if(node==NULL) return;
	printf(" %d ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

void printPostorder(struct Node *node){
	if(node==NULL) return;
	printPostorder(node->left);
	printPostorder(node->right);
	printf(" %d ", node->data);
}

int main(){
	struct Node *root = newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	
	printf("Preorder:");
	printPreorder(root);
	printf("\nPostorder:");
	printPostorder(root);
	printf("\nInorder:");
	printInorder(root);
	
	return 0;
}