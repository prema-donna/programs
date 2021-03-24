#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node** head, int new_data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
}

void delete_key(struct node **head,int key){
	struct node* temp = *head;
	struct node* prev = *head;
	
	while (temp != NULL && temp->data == key){
		*head = temp->next;
		free(temp);
		temp = *head;
	}
	
	while (temp!= NULL){
		while (temp->data != key){
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		free(temp);
		temp = prev->next;
	}
}

void printList(struct node *node){
	while (node != NULL){
		printf("%d, ",node->data);
		node = node->next;
	}
}

int main(){
	struct node* head = NULL;
	push(&head, 1);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);
	push(&head, 1);
	push(&head, 1);
	push(&head, 3);
	push(&head, 4);
	push(&head, 1);
	push(&head, 5);
	push(&head, 1);
	printf("Linked List, no deletion: \n");
	printList(head);
	
	int key = 1;
	delete_key(&head,key);
	printf("\nLinked List after deleting 1: \n");
	printList(head);

	return 0;
}