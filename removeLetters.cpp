#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char* removeAcd(char* input)
{
  int i = 0;
  int oIndex = 0;
  while(input[i] != '\0')
  {
    if(input[i] != 'a' && input[i] != 'c' && input[i] != 'd')
    {
      input[oIndex] = input[i];
      oIndex++;
    }
    i++;
  }
  input[oIndex] = '\0';
  input = (char*)realloc(input,oIndex);
  return input;
}

void print(char* string)
{
  int i = 0;
  while(string[i] != '\0')
  {
    printf("%c", string[i]);
    i++;
  }
  printf("\n");
}

int main()
{
  char* string = (char*)malloc(30);
  char stackString[30] = "3adc2ieadsjdadvnas0q3ir1fajf";
  for(int i= 0; i< 30; i++) string[i] = stackString[i];
  print(removeAcd(string));
  return 0;
}
