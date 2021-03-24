// C++ program to delete element in binary tree
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has key, pointer to left
   child and a pointer to right child */
struct Node
{
    int key;
    struct Node* left, *right;
};
 
/* function to create a new node of tree and
   return pointer */
struct Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};
 
/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
}

void preorder(struct Node* temp){
	if(!temp) return;
	cout<<temp->key<<" ";
	preorder(temp->left);
	preorder(temp->right);
}

void postorder(struct Node* temp){
	if(!temp) return;
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->key<<" ";
}
 
/* function to delete the given deepest node
   (d_node) in binary tree */
void deletDeepest(struct Node *root,
                  struct Node *d_node)
{
    queue<struct Node*> q;
    q.push(root);
 
    // Do level order traversal until last node
    struct Node* temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
 
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left=NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
 
/* function to delete element in binary tree */
void deletion(struct Node* root, int key)
{
    queue<struct Node*> q;
    q.push(root);
 
    struct Node *temp;
    struct Node *key_node = NULL;
 
    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
 
        if (temp->key == key)
            key_node = temp;
 
        if (temp->left)
            q.push(temp->left);
 
        if (temp->right)
            q.push(temp->right);
    }
 
    int x = temp->key;
    deletDeepest(root, temp);
    key_node->key = x;
}
 
// Driver code
int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
 
    cout << "Inorder traversal before deletion : ";
    inorder(root);
	
	cout<<"\nPreorder traversal before deletion: ";
	preorder(root);
 
	cout<<"\nPostorder traversal before deletion: ";
	postorder(root);
	
    int key = 11;
    deletion(root, key);
 
    cout << "\nInorder traversal after deletion : ";
    inorder(root);
	
	cout<<"\nPreorder traversal after deletion: ";
	preorder(root);
	
	cout<<"\nPostorder traversal after deletion: ";
	postorder(root);
	
    return 0;
}