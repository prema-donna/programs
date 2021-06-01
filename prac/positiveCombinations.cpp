#include<iostream>
#include<cstdlib>
#include<vector>

void print_all_sum_rec(int target, int current_sum, int start, std::vector<std::vector<int>>& output, std::vector<int>& result) 
{
  if (target == current_sum)
  {
    output.push_back(result);
  }

  for (int i = start; i < target; ++i) 
  {
    int temp_sum = current_sum + i;
    if (temp_sum <= target)
    {
      result.push_back(i);
      print_all_sum_rec(target, temp_sum, i, output, result);
      result.pop_back();

    } 
    else 
    {
      return;
    }
  }
}

std::vector<std::vector<int>> print_all_sum(int target)
{
  std::vector<std::vector<int>> output;
  std::vector<int> result;
  print_all_sum_rec(target, 0, 1, output, result);
  
  return output;
}

void print(std::vector<std::vector<int>> vec)
{
  for(int i= 0; i< vec.size(); i++)
  {
    std::cout<<"[";
    for(int j= 0; j< vec[i].size(); j++)
    {
      std::cout<<vec[i][j]<<", ";
    }
    std::cout<<"]"<<std::endl;
  }
}

int main()
{
  int target = 5;
  std::cout<<"All combinations of positive numbers that reach "<<target<<":"<<std::endl;
  print(print_all_sum(target));
  return 0;
}
