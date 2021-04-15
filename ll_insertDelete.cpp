#include<iostream>
#include<cstdlib>

struct Node{
  int data;
  struct Node* next;
};

//size of LL
int size = 0;

// function to create and return a Node
Node* getNode(int data)
{
  //allocate space for new node
  Node* newNode = new Node();
  
  //insert required data
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// function to insert a Node at required position
void insertPos(Node** current, int pos, int data)
{
  //This checks whether the position given is valid
  if(pos < 1 || pos > size + 1) std::cout<<"Invalid position!"<<std::endl;
  else
  {
    //keep looping until pos is 0, as that's when we place the data
    while(pos--)
    {
      if(pos == 0)
      {
        //add Node at required position
        Node* temp = getNode(data);

        //making the new node to point to the old node at the same position
        temp->next = *current;

        //changing the pointer of the node previous to the old node to point to
        //the new node
        *current = temp;
      }
      else
      {
        //Assign double pointer variable to point to the pointer pointing
        // to the address of the next Node
        current = &(*current)->next; 
      }
    }
    size++;
  }
}

// given a reference (pointer to pointer) to the head of a list and a key,
// deletes the first occurrence of a key in the linked list
void deleteNode(Node** head_ref, int key)
{
  //store head node
  Node* temp = *head_ref;
  Node* prev = NULL;

  //if head node itself holds the key to be deleted
  if(temp != NULL && temp->data == key)
  {
    *head_ref = temp->next; //changed head
    delete temp; //free old head
    return;
  }
  else //search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
  {
    while(temp != NULL && temp->data != key)
    {
      prev = temp; //cycle through linked list, setting previous to current and current to next
      temp = temp->next;
    }
    
    //if key was not present in the linked list
    if(temp == NULL) return;

    //unlink the node from linked list
    prev->next = temp->next;

    //Free memory
    delete temp;
  }
}

void printList(struct Node* head)
{
  while(head != NULL)
  {
    std::cout<<" "<<head->data;
    head = head->next;
  }
  std::cout<<std::endl;
}

int main()
{
  // Creating list 3->5->8->10
  Node* head = NULL;
  head = getNode(3);
  head->next = getNode(5);
  head->next->next = getNode(8);
  head->next->next->next = getNode(10);

  size = 4;
  std::cout<< "Linked list before insertion: ";
  printList(head);

  int data = 12, pos = 3;
  insertPos(&head, pos, data);
  std::cout<< "Linked list after insertion of 12 at position 3: ";
  printList(head);

  //front of the linked list
  data = 1, pos = 1;
  insertPos(&head, pos, data);
  std::cout<<"Linked list after insertion of 1 at position 1: ";
  printList(head);

  //insertion at end of the linked list
  data = 15, pos = 7;
  insertPos(&head, pos, data);
  std::cout<<"Linked list after insertion of 15 at position 7: ";
  printList(head);

  data = 12;
  deleteNode(&head, data);
  std::cout<<"Linked list after deleting 12: ";
  printList(head);

  return 0;
}
