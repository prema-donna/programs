#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>

using namespace std;

vector<pair<int,int>> twoSum(vector<int> &nums, int target){
	vector<pair<int,int>> index;
	for(int i=0; i<nums.size(); i++){
		for(int j=i+1; j<nums.size(); j++){
			if(nums[i]+nums[j] == target){
				index.push_back(make_pair(i,j));
				return index;
			}
		}
	}
  return index;
}

vector<pair<int,int>> twoSumLinear(vector<int> &nums, int target)
{
  unordered_map<int,int> numCounts;
  vector<pair<int,int>> answer;
  for(int i = 0; i< nums.size(); i++)
  {
    int difference = target - nums[i];
    if(numCounts.count(difference) != 0)
    {
      answer.push_back(make_pair(numCounts[difference],i));
      return answer;
    }
    else
    {
      numCounts[nums[i]] = i;
    }
  }
  return answer;
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
	
	vector<pair<int,int>> sum = twoSumLinear(nums,target);
	
	cout<<"Indices ["<<sum[0].first<<","<<sum[0].second<<"]"<<" added together equal "<<target<<endl;;
	
	return 0;
}
