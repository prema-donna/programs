#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

std::string reverseStringWordByWord(std::string s)
{
  std::vector<std::string> allWords;
  std::string currString;
  for(int i= s.length()-1; i >= 0; i--)
  {
    if(s[i] == ' ' && currString.length() > 0)
    {
      allWords.push_back(currString);
      currString.clear();
    }
    else
    {
      if(s[i] != ' ') currString += s[i];
      if(i == 0)
      {
        allWords.push_back(currString);
        currString.clear();
      }
    }
  }
  for(std::vector<std::string>::iterator it = allWords.begin(); it != allWords.end(); ++it)
  {
    std::string word = *it;
    for(int i = word.length()-1; i >= 0; i--) currString += word[i];
    currString += ' ';
  }
  currString.pop_back();
  return currString;
}

int main()
{
  std::string allWords = "    mama papa  ba ba   baby "; 
  std::cout<<"Reversed string, all words: "<<reverseStringWordByWord(allWords)<<std::endl;
  return 0;
}
