// Iterative C++ program to reverse a linked list
#include<iostream>
#include<cstdlib>
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
};
 
/* Function to reverse the linked list */
void reverse(Node** head_ref)
{
    if(*head_ref == NULL) return;
    Node* prev   = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL)
    {
        // Store next
        next  = current->next;  
 
        // Reverse current node's pointer
        current->next = prev;   
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
    Node* new_node = (Node*) malloc(sizeof(struct Node));           
    new_node->data  = new_data;
    new_node->next = (*head_ref);    
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        std::cout<<temp->data<<" ";    
        temp = temp->next;  
    }
}    
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     std::cout<<"Given linked list\n";
     printList(head);    
     reverse(&head);                      
     std::cout<<"\nReversed Linked list \n";
     printList(head);    
}
