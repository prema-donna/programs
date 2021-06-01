#include<iostream>
#include<cstdlib>

struct Node{
  int data;
  Node *next;
};

void push(Node** head, int data)
{
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

Node *combinedList(Node *list1, Node *list2)
{
  Node *outList = NULL;
  Node *l1 = list1;
  Node *l2 = list2;

  while(l1 != NULL && l2 != NULL)
  {
    int sum = l1->data + l2->data;
    push(&outList, sum);
    l1 = l1->next;
    l2 = l2->next;
  }
  return outList;
}

void print(Node *list)
{
  Node *l1 = list;
  while(l1 != NULL)
  {
    std::cout<<l1->data<<", ";
    l1 = l1->next;
  }
  std::cout<<std::endl;
}

int main()
{
  Node *list1 = NULL;
  Node *list2 = NULL;
  push(&list1, 20);
  push(&list1, 2);
  push(&list1, 1);
  push(&list1, 7);
  push(&list1, 13);
  push(&list2, 10);
  push(&list2, 20);
  push(&list2, 30);
  push(&list2, 5);
  push(&list2, 3);

  print(combinedList(list1, list2));
  return 0;
}
