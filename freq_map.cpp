//array: [1,1,1,2,2,3,3,3,3], k= 2, output:[1,3]

#include<iostream>
#include<cstdlib>
#include<climits>
#include<unordered_map>
#include<vector>

using namespace std;

void print(vector<int> vec){
	cout<<"[";
	for(int i=0; i<vec.size()-1; i++){
		cout<<vec[i]<<",";
	}
	cout<<vec[vec.size()-1]<<"]\n";
}

void print_map(unordered_map<int,int> umap){
	cout<<"{";
	for(unordered_map<int,int>::iterator it = umap.begin(); it!= umap.end(); ++it){
		cout<<"["<<it->first<<","<<it->second<<"], ";
	}
	cout<<"}\n";
}

vector<int> freq_count(vector<int> input, int k){
	unordered_map<int,int> map;
	int frequency = k;
	
	for(int i= 0; i< input.size(); i++){
		if(map.find(input[i]) == map.end()){
			map.insert(make_pair(input[i],1));
		}
		else{
			map[input[i]] += 1;
		}
	}
	cout<<"\nmap: ";
	print_map(map);
	int count = 0;
	int key = 0;
	int index = 0;
	vector<int> output(frequency,0);
	
	while(frequency > 0){
	for (unordered_map<int,int>::iterator it= map.begin(); it != map.end(); ++it){
		if(it->second > count){
			count = it->second;
			key = it->first;
		}
	}
	count = 0;
	output[index] = key;
	index++;
	map[key] = INT_MIN;
	frequency--;
	}
	
	return output;
}

int main(){
	vector<int> vec= {1,1,1,1,2,2,2,2,3,3,3,3,4,4,5,5,6,4,5,4,5,6,6,6};
	int k = 6;
	cout<<"Most frequent "<<k<<" elements: ";
	print(freq_count(vec,k));; 
	
	return 0;
}
