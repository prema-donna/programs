#include<algorithm>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

class Graph{
	vector<unordered_set<int>> m_adjacency_list;
	
public:
	Graph(int size):m_adjacency_list(size){}
	unordered_map<int,int> BFS(const int);
	void addEdge(const int, const int);
};

vector<int> traceback_path(int source, int target, unordered_map<int,int>&& parent_map){
	vector<int> path;
	int current_node = target;
		
	while(true){
		path.push_back(current_node);
		if(current_node == source){
			break;
		}
		current_node = parent_map[current_node];
	}
		
	//reverse the path
	reverse(path.begin(), path.end());
		
	return path;
}

unordered_map<int,int> Graph::BFS(const int source){
	unordered_map<int,int> parent_map;
	unordered_set<int> closed;
	queue<int> frontier;
	
	parent_map[source] = 0;
	frontier.push(source);
	
	while(!frontier.empty()){
		int current_node = frontier.front();
		frontier.pop();
		
		for(const int neighbor:m_adjacency_list[current_node]){
			if(closed.find(neighbor) == closed.cend()){
				closed.insert(neighbor);
				parent_map[neighbor] = current_node;
				frontier.push(neighbor);
			}
		}		
	}
	
	return parent_map;
}

void Graph::addEdge(int u, int v){
	m_adjacency_list[u].insert(v);
	m_adjacency_list[v].insert(u);
}

int main(){
	Graph grp1(8);
	grp1.addEdge(0,1);
	grp1.addEdge(0,2);
	grp1.addEdge(1,3);
	grp1.addEdge(1,4);
	grp1.addEdge(2,5);
	grp1.addEdge(3,4);
	grp1.addEdge(3,6);
	grp1.addEdge(4,6);
	grp1.addEdge(4,7);
	grp1.addEdge(6,7);
	
	unordered_map<int,int> parent_map = grp1.BFS(0);
	vector<int> path = traceback_path(0,7, move(parent_map));
	
	for(int node:path){
		cout<<node<<"\n";
	}
	
	return 0;
}