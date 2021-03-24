#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int countDiv(int lowerBound, int higherBound, int divisor)
{
	vector<int> divisibleNums;
	for(int i= lowerBound; i<= higherBound; i++)
	{
		if(i % divisor == 0) divisibleNums.push_back(i);
	}
	return divisibleNums.size();
}

int main()
{
	int lowerBound = 6;
	int higherBound = 11;
	int divisor = 2;
	cout<<"Between "<<lowerBound<<" and "<<higherBound<<", there are "<<
	countDiv(lowerBound,higherBound,divisor)<<" numbers that are divisible by "<<divisor<<endl;
	return 0;
}