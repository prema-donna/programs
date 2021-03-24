#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack{
	int data;
	struct Stack *next;
};

struct Stack *newNode(int data){
	struct Stack *s= (struct Stack*)malloc(sizeof(struct Stack));
	s->data= data;
	s->next= NULL;
	return s;
}

int isEmpty(struct Stack *root){return !root;}

void push(struct Stack **root, int data){
	struct Stack *s = newNode(data);
	s->next = *root;
	*root= s;
	printf("%d pushed to stack \n",data);
}

int pop(struct Stack **root){
	if(isEmpty(*root)) return INT_MIN;
	struct Stack *temp= *root;
	*root = (*root)->next;
	int pop_item = temp->data;
	free(temp);
	
	return pop_item;
}

int peek(struct Stack *root){
	if (isEmpty(root)) return INT_MIN;
	return root->data;
}

int main(){
	struct Stack *root= NULL;
	push(&root,1);
	push(&root,2);
	push(&root,3);
	printf("%d popped from stack \n", pop(&root));
	printf("Top element is %d \n", peek(root));
	
	return 0;
}

