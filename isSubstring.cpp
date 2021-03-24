#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char* is_subString(char* mainString, char* subString)
{
	bool subStringFound = false;
	for(int i= 0; i< strlen(mainString)-strlen(subString); i++)
	{
		char* segString = (char*)malloc(strlen(subString)-1);
		int subIndex = 0, numSameChars = 0;
		for(int j= i; j< i+strlen(subString)-1; j++)
		{
			segString[subIndex] = mainString[j];
			subIndex++;
		}
		for(int j= 0; j< strlen(subString); j++)
		{
			if(segString[j] == subString[j]) numSameChars++;
		}
		if(numSameChars == subIndex)
		{
			subStringFound = true;
		}
	}
	if(subStringFound)
	{
		return "Yes";
	}
	return "No";
}

int main()
{
	char* mainString = (char*)malloc(1000);
	char* subString = (char*)malloc(1000);
	printf("Please enter the main string: ");
	fgets(mainString, 1000, stdin);
	printf("Please enter the substring: ");
	fgets(subString, 1000, stdin);
	printf("%s",is_subString(mainString,subString));
	return 0;
}