#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>

using namespace std;

int oddOccurrencesInArray(vector<int> &A)
{
	unordered_map<int,int> occurrences;
	for(int i= 0; i< A.size(); i++)
	{
		occurrences[A[i]]++;
	}
	for(unordered_map<int,int>::iterator it = occurrences.begin(); it != occurrences.end(); ++it)
	{
		if(it->second == 1) return it->first;
	}
	return -1;
}

int main()
{
	vector<int> allNums = {9,3,9,3,9,7,9};
	cout<<"Unique element in array is: "<<oddOccurrencesInArray(allNums)<<endl;
	return 0;
}