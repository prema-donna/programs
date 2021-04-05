#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>

std::vector<int> sortByLargestVec(std::vector<int> vec)
{
  std::map<int,int> freq;
  std::multimap<int,int,std::greater<int>> allNums;
  std::vector<int> sortedVec;

  for(int i = 0; i< vec.size(); i++)
  {
    freq[vec[i]] += 1;
  }
  for(int i = 0; i< vec.size(); i++)
  {
    bool does_exist = false;
    for(std::multimap<int,int>::iterator it = allNums.begin(); it != allNums.end(); ++it)
    {
      if(it->second == vec[i])
      {
        does_exist = true;
        break;
      }
    }
    if(does_exist == false)
    {
      int count = freq[vec[i]];
      allNums.insert(std::pair<int,int> (count,vec[i]));
    }
  }
  for(std::multimap<int,int>::iterator it = allNums.begin(); it != allNums.end(); ++it)
  {
    std::cout<<"value: "<<it->second<<", count: "<<it->first<<std::endl;
    sortedVec.push_back(it->second);
  }
  return sortedVec; 
}

void print(std::vector<int> vec)
{
  std::cout<<"Sorted by quantity and precedence: ";
  for(int i= 0; i< vec.size(); i++)
    std::cout<<vec[i]<<", ";
  std::cout<<std::endl;
}

int main()
{
  std::vector<int> nums = {8,1,2,1,2,3,4,4,3,1,4,2,3,5,7,9,6,9};
  print(sortByLargestVec(nums));

  return 0;
}

