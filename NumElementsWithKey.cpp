#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int removeElement(vector<int>& nums, int val){
	int count= 0;
	for(int i= 0; i< nums.size(); i++){
		if(nums[i] == val)
			count++;
		else
			nums[i-count] = nums[i];
	}
	
	return nums.size()-count;
}

int main(){
	vector<int> nums= {3,2,2,3,2,2};
	int val= 3;
	
	cout<<"Number of elements with a value of "<<val<<" is: "<<removeElement(nums,val)<<endl;
	
	return 0;
}