#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>

std::vector<std::vector<int>> zeroMatrix(std::vector<std::vector<int>> matrix)
{
  std::unordered_multimap<int,int> zeroes;
  for(int i= 0; i< matrix.size(); i++)
  {
    for(int j= 0; j< matrix[i].size(); j++)
    {
      if(matrix[i][j] == 0) zeroes.insert(std::pair<int,int>(i,j));
    }
  }
  for(std::unordered_multimap<int,int>::iterator it = zeroes.begin(); it != zeroes.end(); ++it)
  {
    int row = it->first;
    int col = it->second;
    for(int i= 0; i< matrix.size(); i++) matrix[i][col] = 0; //zero the col
    for(int j= 0; j< matrix[row].size(); j++) matrix[row][j] = 0; //zero the row
  }
  return matrix;
}

void print(std::vector<std::vector<int>> res)
{
  for(int i= 0; i< res.size(); i++)
  {
    std::cout<<"{";
    for(int j= 0; j< res[i].size(); j++)
    {
      std::cout<<res[i][j]<<",";
    }
    std::cout<<"}"<<std::endl;
  }
}

int main()
{
  std::vector<std::vector<int>> vec = {{1,0,3,2,4,5},{0,3,5,2,1,8},{6,5,4,3,2,1},{9,3,5,6,2,0},{12,5,6,7,0,2}};
  print(vec);
  print(zeroMatrix(vec));
  return 0;
}
