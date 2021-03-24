#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>
#include<vector>

using namespace std;

int countCombos(int target)
{	
	int small = 1;
	int large = 2;
	if(target <= 1) return target;
	return countCombos(target-small)+countCombos(target-large);	
}

int allStories(int target)
{
	return countCombos(target+1);
}

void determinePath(int target, char* path, int index)
{
	if(target == 0)
	{
		path[index] = '\0';
		cout<<path<<endl;
	}
	if(target >= 1)
	{
		path[index] = '1';
		determinePath(target-1,path,index+1);
	}
	if(target >= 2)
	{
		path[index] = '2';
		determinePath(target-2,path,index+1);
	}
}

void printStories(int target)
{
	char* path = new char[target+1];
	determinePath(target, path, 0);
}

int main()
{
	int target = 8;
	cout<<"Number of combos to build "<<target<<" stories is "<<allStories(target)<<endl;
	printStories(target);
	
	return 0;
}
	