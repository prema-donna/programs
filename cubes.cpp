#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<unordered_map>

std::vector<std::vector<int>> abcd(int max)
{
  int a, b;
  std::unordered_multimap<int,std::pair<int,int>> allCubeSums;
  std::vector<std::vector<int>> sameSums;
  for(int a = 1; a <= max; a++)
  {
    for(int b = 1; b <= max; b++)
    {
      int cubeSum = pow(a,3)+pow(b,3);
      allCubeSums.insert(std::make_pair(cubeSum,std::make_pair(a,b)));
    }
  }
  for(std::unordered_multimap<int,std::pair<int,int>>::iterator it = allCubeSums.begin(); it != allCubeSums.end(); ++it)
  {
    if(allCubeSums.count(it->first) > 1)
    {
      std::pair<std::unordered_multimap<int,std::pair<int,int>>::iterator, std::unordered_multimap<int,std::pair<int,int>>::iterator> itA = allCubeSums.equal_range(it->first);
      for(std::unordered_multimap<int,std::pair<int,int>>::iterator itB = itA.first; itB != itA.second; ++itB)
      {
        if(itB->first == it->first && itB->second.first != it->second.first && itB->second.second != it->second.second && itB->second.first != it->second.second && itB->second.second != it->second.first)
        {
          std::vector<int> allValues;
          allValues.push_back(it->second.first);
          allValues.push_back(it->second.second);
          allValues.push_back(itB->second.first);
          allValues.push_back(itB->second.second);
          allValues.push_back(it->first);
          sameSums.push_back(allValues);
        }
      }
    }
  }
  return sameSums;
}

void print(std::vector<std::vector<int>> result, int target)
{
  std::cout<<"Numbers that produce the same cubed sum: "<<std::endl;
  for(int i= 0; i< result.size(); i++)
  {
    for(int j= 0; j< result[i].size()-1; j++)
    {
      std::cout<<result[i][j]<<", ";
    }
    std::cout<<"sum: "<<result[i][result[i].size()-1]<<std::endl;
  }
  std::cout<<"Number of combinations that produce the same cubed sum, up to "<<target<<": "<<result.size()<<std::endl;
}

int main()
{
  int target = 1000;
  print(abcd(target),target);
  return 0;
}
