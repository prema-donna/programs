#include<iostream>
#include<queue>

using namespace std;

void pq(priority_queue<int> q){
	priority_queue<int> qq = q;
	while(!qq.empty()){
		cout<<"\t"<<qq.top();
		qq.pop();
	}
	cout<< "\n";
}

int main(){
	priority_queue <int> q;
	q.push(10);
	q.push(30);
	q.push(20);
	q.push(5);
	q.push(1);
	
	cout<<"Contents of the priority_queue are:\n";
	pq(q);
	
	cout<<"Size of priority_queue: "<<q.size()<<endl;
	cout<<"Top of priority_queue: "<<q.top()<<endl;
	cout<<"After popping an element:\n";
	q.pop();
	pq(q);
	
	return 0;
}