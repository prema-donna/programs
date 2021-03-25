#include<iostream>
#include<cstdlib>
#include<climits>
#include<map>
#include<vector>

int smallestPositiveInt(std::vector<int> currArr)
{
  int sp = INT_MAX;
  std::map<int,int> allValues;
  for(int i= 0; i< currArr.size(); i++)
  {
    if(currArr[i] < sp && currArr[i] > 0)
    {
      allValues[currArr[i]] += 1;
      sp = currArr[i];
    }
  }
  if (sp != 1) return 1;
  for(std::map<int,int>::iterator it = allValues.begin(); it != allValues.end(); ++it)
  {
    int currVal = it->first;
    if(currVal-sp > 1) return sp+1;
    else sp = currVal;
  }
  return sp+1;
}

int main()
{
  std::vector<int> vals = {12, 1, -5, 2, 2, 3, 4, 6, 7, 8};
  std::cout<<"Smallest positive integer = "<<smallestPositiveInt(vals)<<std::endl;
}
