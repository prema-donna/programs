#include<iostream>
#include<cstdlib>
#include<vector>
#include<set>

int numSwaps(std::vector<int> arr)
{
  std::set<int> inOrder;
  std::vector<int> sortVec;
  int numSwaps = 0;
  for(int i= 0; i< arr.size(); i++)
  {
    inOrder.insert(arr[i]);
  }
  for(std::set<int>::iterator it = inOrder.begin(); it != inOrder.end(); ++it)
  {
    sortVec.push_back(*it);
  }
  while(arr != sortVec)
  {
    for(int i= 0; i< arr.size()-1; i++)
    {
      if(arr[i] > arr[i+1])
      {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        numSwaps++;
      }
    }
  }
  return numSwaps;
}

int main()
{
  std::vector<int> arr = {7,4,3,0,2,1};
  std::cout<<"Number of swaps = "<<numSwaps(arr)<<std::endl;

  return 0;
}
