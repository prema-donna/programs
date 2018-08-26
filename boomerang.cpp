#include<iostream>
#include<cstdlib>
#include<unordered_map>
#include<vector>

using namespace std;

void print(unordered_map<int,int> umap){
	cout<<"{";
	for(unordered_map<int,int>::iterator it = umap.begin(); it!= umap.end(); ++it){
		cout<<"["<<it->first<<","<<it->second<<"], ";
	}
	cout<<"}\n";
}

int numBoomerangs(vector<pair<int,int>>& points){
	int size = points.size();
	int number = 0;
	for(auto& p:points){
		unordered_map<int,int> map(size);
		for(auto& q:points){
			int x= p.first - q.first;
			int y= p.second - q.second;
			int distance = x*x+y*y;
			number += 2*map[distance]++;
		}
		print(map);
	}
	return number;
}

int main(){
	vector<pair<int,int>> input = {{0,0},{1,0},{2,0}};
	
	cout<<"number of possible boomerangs: "<<numBoomerangs(input)<<endl;
	
	return 0;
}