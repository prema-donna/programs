#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<climits>

void print(std::vector<std::vector<int>> vec)
{
  for(int i= 0; i< vec.size(); i++)
  {
    std::cout<<"Position Vector "<<i+1<<": {"<<vec[i][0]<<", "<<vec[i][1]<<", "<<vec[i][2]<<"}"<<std::endl;
  }
}

bool triangle(std::vector<int> &A)
{
  if (A.size() < 3) return false;
  std::map<int,int> sortedValues;
  std::vector<std::vector<int>> potentialTriangles;
  for(int i= 0; i< A.size(); i++)
  {
    sortedValues[A[i]] = i;
  }
  int p = INT_MIN, q = INT_MIN, r = INT_MIN;
  std::vector<int> currTriangle;
  for(std::map<int,int>::iterator it = sortedValues.begin(); it != sortedValues.end(); ++it)
  {
    if(p == INT_MIN)
    {
      p = it->first;
      currTriangle.push_back(it->second);
    }
    else if(q == INT_MIN)
    {
      q = it->first;
      currTriangle.push_back(it->second);
    }
    else if(r == INT_MIN)
    {
      r = it->first;
      currTriangle.push_back(it->second);
      if(p + q > r)
      {
        std::cout<<"Vector "<<potentialTriangles.size()+1<<": A triangle can be made with p= "<<p<<" q="<<q<<" r="<<r<<std::endl;
        potentialTriangles.push_back(currTriangle);
      }
      currTriangle[0] = currTriangle[1];
      currTriangle[1] = currTriangle[2];
      currTriangle.pop_back();
      p = q;
      q = r;
      r = INT_MIN;
    }
  }
  if(potentialTriangles.size() > 0)
  {
    print(potentialTriangles);
    return true;
  }
  std::cout<<"No potential triangles"<<std::endl;
  return false;
}

int main()
{
  std::vector<int> values = {10,2,5,1,8,20};
  triangle(values);
  values = {5, 4, 3, 1, 2};
  triangle(values);
  return 0;
}
