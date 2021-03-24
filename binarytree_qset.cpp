#include<iostream>
#include<queue>
#include<set>
#include<cstdlib>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int dat){
		data = dat;
		left = nullptr;
		right = nullptr;
	}
};

void sorted_level_order(Node *root){
	queue<Node*> q;
	set<int> s;
	
	q.push(root);
	q.push(nullptr);
	
	while(q.empty() == false){
		Node* temp = q.front();
		q.pop();
		
		if(temp == nullptr){
			if(s.empty() == true) break;
			for(set<int>::iterator it= s.begin(); it!= s.end(); ++it)
				cout<<*it<<" ";
			q.push(nullptr);
			s.clear();
		}
		else{
			s.insert(temp->data);
			if(temp->left != nullptr)
				q.push(temp->left);
			if(temp->right != nullptr)
				q.push(temp->right);
		}
	}
}

int main(){
	Node* root = new Node(7);
	root->left = new Node(6);
	root->right = new Node(5);
	root->left->left = new Node(4);
	root->left->right = new Node(3);
	root->right->left = new Node(2);
	root->right->right = new Node(1);
	sorted_level_order(root);
	
	return 0;
}