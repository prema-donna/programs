#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int m = matrix.size(); //rows
  int n = m ? matrix[0].size() : 0; //columns
  int u = 0; //rightward
  int d = m - 1; //downward
  int l = 0; //leftward
  int r = n - 1; //rightward
  int p = 0; //counter

  vector<int> order(m * n); //result vector
  while (u <= d && l <= r) {
    for (int col = l; col <= r; col++) {
        order[p++] = matrix[u][col];
    }
    if (++u > d) {
        break;
    }
    for (int row = u; row <= d; row++) {
        order[p++] = matrix[row][r];
    }
    if (--r < l) {
        break;
    }
    for (int col = r; col >= l; col--) {
        order[p++] = matrix[d][col];
    }
    if (--d < u) {
        break;
    }
    for (int row = d; row >= u; row--) {
        order[p++] = matrix[row][l];
    }
    if (l++ > r) {
        break;
    }
  }
  return order;
}

int main()
{
  vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
  vector<int> res = spiralOrder(matrix);
  
  std::cout<<"Printing in spiral order: ";
  for(int i= 0; i< 12; i++)
  {
    std::cout<<res[i]<<", ";
  }
  std::cout<<std::endl; 
  
  return 0;
}
