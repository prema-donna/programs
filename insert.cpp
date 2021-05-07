#include<iostream>

struct Node
{
  int data;
  Node* next;
};

int size;

void insertNode(Node** list, int value, int position)
{
  if(position < 0 || position > size + 1) return;
  else
  {
    while(position--)
    {
      if(position == 0)
      {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = *list;
        *list = newNode;
        size++;
      }
      else
      {
        list = &(*list)->next;
      }
    }
  }
}

void deleteNode(Node** list, int key)
{
  Node* current = *list;
  Node* prev = NULL;
  
  if(current != NULL && current->data == key)
  {
    *list = current->next;
    delete current;
    return;
  }
  else
  {
    while(current != NULL && current->data != key)
    {
      prev = current;
      current = current->next;
    }
    if(current == NULL) return;
    
    prev->next = current->next;
    delete prev;
    size--;
  }
}
