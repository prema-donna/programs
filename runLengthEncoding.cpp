#include<iostream>
#include<cstdlib>
#include<string>

std::string runLengthEncoding(std::string input)
{
  if(input.empty()) return "";

  int count = 1;
  std::string output;

  for(int i= 0; i< input.length(); i++)
  {
    if(input[i] == input[i+1]) count++;
    else
    {
      std::string charCount = std::to_string(count) + input[i];
      output += charCount;
      count = 1;
    }
  }
  return output;
}

std::string runLengthDecoding(std::string encoded)
{
  if(encoded.empty()) return "";
  std::string decoded;
  std::string numString;
  for(int i= 0; i< encoded.length(); i++)
  {
    if(encoded[i] > '9')
    {
      int valString = std::stoi(numString);
      for(int j = 0; j< valString; j++)
      {
        decoded += encoded[i]; 
      }
      numString = "";
    }
    else
    {
      numString += encoded[i];
    }
  }
  return decoded;
}

int main()
{
  std::cout<<"String aabaacdcdcb is encoded as "<<runLengthEncoding("aabaacdcdcb")<<std::endl;
  std::cout<<"Decoding string "<<runLengthEncoding("aabaacdcdcb")<<" gives us "<<runLengthDecoding(runLengthEncoding("aabaacdcdcb"))<<std::endl;
  return 0;
}
