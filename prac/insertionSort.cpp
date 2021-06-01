#include<iostream>
#include<cstdlib>
#include<vector>

void swap(std::vector<int>& vec, int pos1, int pos2)
{
  int temp = vec[pos1];
  vec[pos2] = temp;
  vec[pos1] = vec[pos2];
}

std::vector<int> insertionSort(std::vector<int> vec)
{
  if(vec.size() <= 1) return vec;
  for(int i= 1; i< vec.size(); i++)
  {
    int currVal = vec[i];
    int j = i-1;
    for(; j >= 0 && vec[j] > currVal; j--)
    {
      swap(vec, j, j+1);
    }
    vec[j+1] = currVal;
  }
  return vec;
}

void print(std::vector<int> vec)
{
  std::cout<<"{";
  for(int i= 0; i< vec.size(); i++)
  {
    std::cout<<vec[i]<<",";
  }
  std::cout<<"}"<<std::endl;
}

int main()
{
  std::vector<int> vec = {4, 2, 6, 2, 7, 2, 9, 12, 1, 4, 3, 8, 14, 4, 7, 5};
  print(insertionSort(vec));
  return 0;
}
