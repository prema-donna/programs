#include<iostream>
#include<cstdlib>
#include<unordered_set>

struct node
{
  int data;
  node *next;
};

void push(node** head, int data)
{
  struct node *new_node = new node();
  new_node->data = data;
  new_node->next = *head;
  *head = new_node; 
}

bool isCycle(node *list)
{
  struct node *curr = list;
  //struct node *curr2 = curr->next;
  std::unordered_set<node *> addresses;
  while(curr != NULL)
  {
    //if(curr2 == curr) return true;
    if(addresses.count(curr) == 1) return true;
    addresses.insert(curr);
    curr = curr->next;
    //curr2 = curr2->next->next;
  }
  return false;
}

int main()
{
  struct node *head = NULL;
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);

  head->next->next->next->next = head;

  if(isCycle(head)) std::cout<<"Found cycle!"<<std::endl;
  else std::cout<<"No cycle found!"<<std::endl;

  return 0;
}
