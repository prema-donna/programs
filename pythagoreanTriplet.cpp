#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

long long int pythagoreanTriplet(int targetSum)
{
  vector<vector<int>> triplets;
  int a;
  int b;
  double c;
  for(int i= 1; i<= targetSum/2; i++)
  {
    a = i;
    for(int j= a+1; j<= targetSum/2+1; j++)
    {
      b = j;
      c = sqrt(pow(a,2)+pow(b,2));
      if(fmod(c,1.0) == 0)
      {
        triplets.push_back({a,b,(int)c});
      }
    }
  }

  for(int i= 0; i< triplets.size(); i++)
  {
    int sum = 0;
    for(int j= 0; j< triplets[i].size(); j++)
    {
      sum += triplets[i][j];
    }
    if(sum == targetSum)
    {
      cout<<"a = "<<triplets[i][0]<<", b = "<<triplets[i][1]<<
            ", c = "<<triplets[i][2]<<endl; 
      return (long long int)triplets[i][0]*triplets[i][1]*triplets[i][2];
    }
  }
  return 0;
}

int main()
{
  int targetSum;
  cout<<"Enter targetSum (i.e. 1000): ";
  cin>>targetSum;
  cout<<"Product of pythagorean triplet is:"<<
      pythagoreanTriplet(targetSum)<<endl;
  return 0;
}
