#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int smallingMissingPositive(vector<int> nums)
{
	for(int i= 0; i< nums.size(); i++){
		if(nums[i] <= 0) nums[i] = INT_MAX;
	}
	set<int> s(nums.begin(), nums.end());
	nums.assign(s.begin(),s.end());
	for(int i= 0; i< nums.size(); i++){
		if(nums[i] != i+1) return i+1;
	}
	
	return nums.size()+1;
}

int missingNumber(vector<int>& nums) {
	for(int i= 0; i< nums.size(); i++){
		if(nums[i] < 0) nums[i] = INT_MAX;
	}
	set<int> s(nums.begin(),nums.end());
	nums.assign(s.begin(),s.end());
	sort(nums.begin(),nums.end());
	for(int i= 0; i< nums.size(); i++){
		if(nums[i] != i) return i;
	}
	
	return nums.size();
}

void print(vector<int> nums){
	cout<<"{";
	for(int i= 0; i< nums.size(); i++){
		cout<<nums[i]<<",";
	}
	cout<<"}"<<endl;
}

int main(){
	vector<int> nums = {1,9,2,9,3,9,4,9,9,5,6,9,9,7,8,9,10,11,-1,0,-2,-10,13,-1,-2,14,-8};
	print(nums);
	cout<<"Smallest missing positive is: "<<smallingMissingPositive(nums)<<endl;
	cout<<"The missing number is is: "<<missingNumber(nums)<<endl;
	
	return 0;
}