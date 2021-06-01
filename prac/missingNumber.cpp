#include<iostream>
#include<cstdlib>
#include<set>
#include<vector>

int missingNumber(std::vector<int> values)
{
  std::set<int> allNumsSorted;
  for(int i= 0; i< values.size(); i++) allNumsSorted.insert(values[i]);
  
  int currNum = 1;
  for(std::set<int>::iterator it = allNumsSorted.begin(); it != allNumsSorted.end(); ++it)
  {
    if(*it != currNum) return currNum;
    currNum++;
  }
  return 0;
}

int main()
{
  std::vector<int> values = {8,2,6,1,4,2,5,3,4,3,9,12,11,10};
  std::cout<<"Missing number: "<<missingNumber(values)<<std::endl;
  return 0;
}
