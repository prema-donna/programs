#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>

std::vector<std::vector<char>> mineSweeper(int height, int width, int numberOfMines)
{
  double probMine = numberOfMines/(double)(height*width);
  std::vector<std::vector<char>> board;
  srand(time(NULL));
  if(numberOfMines > height*width) numberOfMines = height*width;

  for(int i= 0; i< width; i++)
  {
    std::vector<char> row;
    for(int j= 0; j< height; j++)
    {
      double value = (double)(rand() % 100)/(100*probMine);
      if(value < 0.95 && numberOfMines > 0)
      {
        row.push_back('M');
        numberOfMines--;
      }
      else
      {
        row.push_back('0');
      }
    }
    board.push_back(row);
  }

  if(numberOfMines > 0)
  {
    while(numberOfMines > 0)
    {
      for(int i= 0; i< width; i++)
      {
        for(int j= 0; j< height; j++)
        {
          double value = (double)(rand() % 100)/(100*probMine);
          if(value < 0.95 && numberOfMines > 0 && board[i][j] != 'M')
          {
            board[i][j] = 'M';
            numberOfMines--;
          }
        }
      }
    }
  }

  return board;
}

void print(std::vector<std::vector<char>> vec)
{
  for(int i= 0; i< vec.size(); i++)
  {
    for(int j= 0; j< vec[i].size(); j++)
    {
      std::cout<<vec[i][j]<<" ";   
    }
    std::cout<<std::endl;
  }
}

int main()
{
  int height = 9;
  int width = 9;
  int numberOfMines = 30;

  std::cout<<"Minesweeper board of "<<height<<" by "<<width<<" with "<<numberOfMines<<" mines:"<<std::endl;
  print(mineSweeper(height,width,numberOfMines));

  return 0;
}
