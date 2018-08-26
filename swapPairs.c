#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node *next;
};

void push(struct Node** head,int value){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->val = value;
	new_node->next = *head;
	*head = new_node;
}

void print(struct Node* head){
	struct Node* temp = head;
	
	while(temp != NULL){
		printf("%d->",temp->val);
		temp = temp->next;
	}
	printf("\n");
}

struct Node* swapPairs(struct Node* head){
	 if(NULL == head)
        return NULL;
    /*tmp:exchange the value*/
    int tmp = 0;
    struct Node *p = head;
    struct Node *pnext = p->next;
    
    while(p && pnext)
    {
        /*exchange p and pnext*/
        tmp = p->val;
        p->val = pnext->val;
        pnext->val = tmp;
        
        /*prepare for next loop*/
        p = pnext->next;
        /*p not null,then use p->next*/
        if(p)
            pnext = p->next;
    }
    
    return head;
}

int main(){
	struct Node* head = NULL;
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print(head);
	swapPairs(head);
	print(head);
	
	return 0;
}