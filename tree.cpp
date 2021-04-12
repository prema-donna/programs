#include<iostream>
#include<cstdlib>
#include<queue>

struct tree
{
  int data;
  tree* left;
  tree* right;
};

tree* createNode(int data)
{
  tree* newItem = new tree();
  newItem->data = data;
  newItem->left = newItem->right = NULL;
  return newItem;
}

tree* insertNode(tree* root, int data)
{
  if(root == NULL)
  {
    root = createNode(data);
    return root;
  }

  std::queue<tree*> q;
  q.push(root);

  while (!q.empty())
  {
    tree* temp = q.front();
    q.pop();

    if(temp->left != NULL)
    {
      q.push(temp->left);
    }
    else
    {
      temp->left = createNode(data);
      return root;
    }

    if(temp->right != NULL)
    {
      q.push(temp->right);
    }
    else
    {
      temp->right = createNode(data);
      return root;
    }
  }

  return root;
}

void inOrder(tree* temp)
{
  if(temp == NULL) return;
  inOrder(temp->left);
  std::cout<<temp->data<<" ";
  inOrder(temp->right);
}

void preOrder(tree* temp)
{
  if(temp == NULL) return;
  std::cout<<temp->data<<" ";
  preOrder(temp->left);
  preOrder(temp->right);
}

void postOrder(tree* temp)
{
  if(temp == NULL) return;
  postOrder(temp->left);
  postOrder(temp->right);
  std::cout<<temp->data<<" ";
}

int main()
{
  tree* root = createNode(10);
  root->left = createNode(11);
  root->left->left = createNode(7);
  root->right = createNode(9);
  root->right->left = createNode(15);
  root->right->right = createNode(8);

  std::cout<<"Inorder traversal after insertion : ";
  inOrder(root);
  std::cout<<std::endl;

  root = insertNode(root, 12);

  std::cout<<"Preorder traversal after insertion : ";
  preOrder(root);
  std::cout<<std::endl;

  root = insertNode(root, 14);

  std::cout<<"Postorder traversal after insetion : ";
  postOrder(root);
  std::cout<<std::endl;

  return 0;
}
