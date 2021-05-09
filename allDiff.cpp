#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

void print(std::vector<std::pair<int,int>> vec, int target)
{
  std::cout<<"Number of potential pairs with a difference of "<<target<<": "<<vec.size()<<std::endl; 
  std::cout<<"Potential pairs: "<<std::endl;
  for(int i= 0; i< vec.size(); i++)
  {
    std::cout<<"{"<<vec[i].first<<", "<<vec[i].second<<"}, ";
  }
  std::cout<<std::endl;
}

void numPairsTargetDiff(std::vector<int> nums, int target)
{
  std::set<int> mapPairs;
  std::vector<std::pair<int,int>> allPairs;
  for(int i= 0; i< nums.size(); i++)
  {
    mapPairs.insert(nums[i]);
  }
  for(std::set<int>::iterator it = mapPairs.begin(); it != mapPairs.end(); ++it)
  {
    if(mapPairs.count(*it-target) == 1)
    {
      allPairs.push_back(std::make_pair(*it-target,*it));
    }
  }
  print(allPairs,target);
}

int main()
{
  std::vector<int> nums = {1,7,5,9,2,12,3};
  int target = 2;
  numPairsTargetDiff(nums,target);
  return 0;
}
