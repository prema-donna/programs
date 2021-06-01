#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>

std::vector<std::string> palindromeSubstrings(std::string s)
{
  std::vector<std::string> potentialPalindromes;
  std::string currString;

  for(int i= 0; i< s.length()-1; i++)
  {
    currString += s[i];
    for(int j= i+1; j< s.length(); j++)
    {
      currString += s[j];
      if(s[i] == s[j])
      {
        potentialPalindromes.push_back(currString);
      }
    }
    currString.clear();
  }

  std::vector<std::string> palindromes;
  for(int i= 0; i< potentialPalindromes.size(); i++)
  {
    currString = potentialPalindromes[i];
    std::reverse(potentialPalindromes[i].begin(),potentialPalindromes[i].end());
    if(currString == potentialPalindromes[i]) palindromes.push_back(currString);
  }
  return palindromes;
}

void print(std::vector<std::string> vec)
{
  for(int i= 0; i< vec.size(); i++)
  {
    for(int j= 0; j< vec[i].length(); j++)
    {
      std::cout<<vec[i][j];
    }
    std::cout<<std::endl;
  }
  std::cout<<"Size of vector: "<<vec.size()<<std::endl;
}

int main()
{
  std::string s = "aottobaakewaifaslabrbaasdkljfewfpjsgssopqpqoccccccasfkjafwefgwag";
  std::cout<<"List of palindromics substrings:"<<std::endl;
  print(palindromeSubstrings(s));
  return 0;
}
