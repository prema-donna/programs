#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

std::string reverseSentence(std::string sentence)
{
  std::vector<std::string> allWords;
  std::string currWord;
  
  for(int i= 0; i< sentence.length(); i++)
  {
    if(sentence[i] == ' ')
    {
      allWords.push_back(currWord);
      currWord.clear();
    }
    else
    {
      currWord += sentence[i];
    }
  }
  allWords.push_back(currWord);

  std::string reversedSentence;
  for(int i= allWords.size()-1; i >= 0; i--)
  {
    reversedSentence += allWords[i];
    if(i != 0) reversedSentence += ' ';
  }

  return reversedSentence;
}

void print(std::string s)
{
  for(int i= 0; i < s.length(); i++)
  {
    std::cout<<s[i];
  }
  std::cout<<std::endl;
}

int main()
{
  std::string sentence = "Hello World";
  print(reverseSentence(sentence));
  return 0;
}
