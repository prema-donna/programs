#include<iostream>
#include<vector>

bool searchNumInGrid(std::vector<std::vector<int>> grid, int target) {
    int m = grid.size(), n = grid[0].size();
    std::vector<int> lIdx = {0, 0};
    std::vector<int> rIdx = {m-1, n-1};
    int lVal = grid[lIdx[0]][lIdx[1]], rVal = grid[rIdx[0]][rIdx[1]];
    if(lVal == rVal) return lVal == target ? true : false;
    while(lVal <= rVal){
        if(lVal == target || rVal == target) return true;
        if(lVal < target){
            if(lIdx[1] == n-1){
                lIdx[0]++;
                lIdx[1] = -1;
            }
            if(lIdx[0] == m) break;
            lVal = grid[lIdx[0]][++lIdx[1]];
        }
        if(rVal > target){
            if(rIdx[1] == 0){
                rIdx[0]--;
                rIdx[1] = n;
            }
            if(rIdx[0] == -1) break;
            rVal = grid[rIdx[0]][--rIdx[1]];
        }
    }
    return false;
}

void print(bool res, int target){
  if(!res) std::cout<<target<<" not found in grid"<<std::endl;
  else std::cout<<target<<" was successfully found in grid"<<std::endl;
}

int main()
{
  std::vector<std::vector<int>> vec = {{1, 2, 4, 6}, {12, 13, 17, 18}, {24, 32, 36, 48}};
  int target = 7;
  print(searchNumInGrid(vec, target),target);
  
  target = 6;
  print(searchNumInGrid(vec, target),target);
  
  return 0;
}
