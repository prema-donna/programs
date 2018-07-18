#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node *newNode(int data){
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void removeDuplicates(struct Node *start){
	struct Node *a;
	struct Node *b;
	struct Node *duplicate;
	a = start;
	
	while(a!=NULL && a->next!=NULL){
		b = a;
		//compare picked element with rest of elements 
		while(b->next != NULL){
			if(a->data == b->next->data){
				duplicate = b->next;
				b->next = b->next->next;
				delete(duplicate);
			}
			else b = b->next;
		}
		a = a->next;
	}
}

void printList(struct Node *node){
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next = newNode(11);
    start->next->next->next->next->next->next = newNode(10);
 
    printf("Linked list before removing duplicates ");
    printList(start);
 
    removeDuplicates(start);
 
    printf("\nLinked list after removing duplicates ");
    printList(start);
 
    return 0;
}