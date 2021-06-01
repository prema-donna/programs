#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>

bool targetSum(std::vector<int> vec, int target)
{
  std::unordered_map<int,int> diffs;
  for(int i= 0; i< vec.size(); i++)
  {
    diffs[vec[i]] = target-vec[i]; 
  }
  for(std::unordered_map<int,int>::iterator it = diffs.begin(); it != diffs.end(); ++it)
  {
    if(diffs.count(it->second) == 1)
    {
      std::cout<<"Sum reached with "<<it->first<<" and "<<it->second<<std::endl;
      return true;
    }
  }
  std::cout<<"Target sum cannot be reached"<<std::endl;
  return false;
}

int main()
{
  std::vector<int> vec = {1,2,3,4,9,6,5,8,7,12,10,11};
  int target = 21;
  targetSum(vec,target);
  return 0;
}
