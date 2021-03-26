#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<unordered_map>

std::string longestSubString(std::string s, int k)
{
  std::string t;
  std::vector<std::string> allItems;
  int lssl = 0;
  for(int i= 0; i< s.length(); i++)
  {
    if(s[i] == ' ' && t.length() > 0)
    {
      allItems.push_back(t);
      t.clear();
    }
    else if(s[i] != ' ') t += s[i];
  }
  for(std::vector<std::string>::iterator it = allItems.begin(); it != allItems.end(); ++it)
  {
    std::string curr = *it;
    std::unordered_map<char,int> dictionary;
    for(int i= 0; i< curr.length(); i++) dictionary[curr[i]] += 1;
    if(dictionary.size() <= k && lssl < curr.length())
    {
      t = curr;
      lssl = curr.length();
    }
  }
  std::cout<<"Substring: "<<t<<". Length of longest substring = "<<lssl<<std::endl;
  return t;
}

int main()
{
  std::string s = " hello is it me you're looking for? Cause I wonder where you are, and I wonder what you do. Are you somewhere feeling lonely? Or is someone loving you? Tell me how to win your heart, for I haven't got a clue. But let me start by saying, I love you.";
  longestSubString(s, 7); 
  return 0;
}
