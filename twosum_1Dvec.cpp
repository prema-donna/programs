#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int> nums, int target){
	vector<int> index;
	int sum= 0;
	
	for(int i= 1; i< nums.size(); i++){
		sum= nums[i]+nums[i-1];	
		if(sum == target){
			index.push_back(i-1);
			index.push_back(i);
		}
	}
	
	return index;
}

int main(){
	vector<int> nums= {2,7,11,15};
	int target= 26;
	vector<int> sum_indices= twoSum(nums,target);
	
	cout<<"The sum of indices "<<sum_indices[0]<<" and "<<sum_indices[1]<<" is "<<target<<endl;
	
	return 0;
}