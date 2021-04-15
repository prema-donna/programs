#include<iostream>
#include<cstdlib>
#include<string>
#include<map>
#include<unordered_map>

std::string convertNumToWords(long int num)
{
  std::map<int,int> valsPowTen;
  int length = 0;
  long int placeholder = num;
  if(num == 0) return "zero";
  while(placeholder > 0)
  {
    int remainder = placeholder % 10;
    placeholder /= 10;
    length++;
    valsPowTen[length] = remainder;
  }
  std::string result;
  std::unordered_map<int,std::string> tens = {{2,"twenty"}, {3,"thirty"}, {4,"forty"}, {5,"fifty"}, {6,"sixty"}, {7,"seventy"}, {8,"eighty"}, {9,"ninety"}};
  std::unordered_map<int,std::string> teens = {{0,"ten"},{1,"eleven"}, {2,"twelve"}, {3,"thirteen"}, {4,"fourteen"}, {5,"fifteen"}, {6,"sixteen"}, {7,"seventeen"}, {8,"eighteen"}, {9,"nineteen"}};
  std::unordered_map<int,std::string> ones = {{1,"one"}, {2,"two"}, {3,"three"}, {4,"four"}, {5,"five"}, {6,"six"}, {7,"seven"}, {8,"eight"}, {9,"nine"}};
  bool teenFound = false;
  for(std::map<int,int>::reverse_iterator it = valsPowTen.rbegin(); it != valsPowTen.rend(); ++it)
  {
    int currLength = it->first;
    int currNum = it->second;
    if(teenFound)
    {
      result += teens[currNum];
      result += ' ';
      teenFound = false;
    }
    if(currLength % 3 == 2 && currNum > 0)
    {
      if(currNum == 1)
      {
        teenFound = true;
        continue;
      }
      else
      {
        result += tens[currNum];
        result += ' ';
        continue;
      }
    }
    if(currNum != 0)
    {
      result += ones[currNum];
      result += ' ';
      if(currLength % 3 == 0) 
      {
        result += "hundred";
        result += ' ';
      }
    }
    if(currLength == 13) result += "trillion ";
    if(currLength == 10) result += "billion ";
    if(currLength == 7) result += "million ";
    if(currLength == 4) result += "thousand ";
  }
  if(result[result.length()-1] == ' ') result.pop_back();
  return result;
}

int main()
{
  long int num = 723498710059642;
  std::cout<<num<<" in words is: "<<convertNumToWords(num)<<std::endl;
  return 0;
}
