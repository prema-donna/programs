#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

vector<pair<int,int>> twoSum(vector<int> &nums, int target){
	for(int i=0; i<nums.size(); i++){
		for(int j=i+1; j<nums.size(); j++){
			if(nums[i]+nums[j] == target){
				vector<pair<int,int>> index;
				index.push_back(make_pair(i,j));
				return index;
			}
		}
	}
} 

int main(){
	int target = 16;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(6);
	nums.push_back(12);
	
	vector<pair<int,int>> sum = twoSum(nums,target);
	
	cout<<"Indices ["<<sum[0].first<<","<<sum[0].second<<"]"<<" added together equal "<<target<<endl;;
	
	return 0;
}