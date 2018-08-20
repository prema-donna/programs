#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums){
	vector<int> input = nums;
	vector<vector<int>> output;
	
	do{
		output.push_back(nums);
		next_permutation(nums.begin(),nums.end());
	}while(input!=nums);
	
	return output;
}

void print(vector<vector<int>> vec){
	for(int i= 0; i<vec.size(); i++){
		cout<<"[";
		for(int j= 0; j<vec[0].size(); j++){
			if(j != vec[0].size()-1){
				cout<<vec[i][j]<<",";
			}
			else{
				cout<<vec[i][j]<<"], ";		
			}
		}
	}
}

int main(){
	vector<int> item;
	item.push_back(1);
	item.push_back(2);
	item.push_back(3);
	item.push_back(4);
	
	permute(item);
	print(permute(item));
	
	return 0;
}