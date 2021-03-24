#include<iostream>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

int tapeEquil(vector<int> &A)
{
	int sum = 0;
	int curr_sum = 0;
	vector<int> allDiffs;
	for(int i= 0; i< A.size(); i++) sum += A[i];
	for(int i= 0; i< A.size()-1; i++)
	{
		curr_sum += A[i];
		int rem_sum = sum - curr_sum;
		allDiffs.push_back(abs(curr_sum-rem_sum));
	}
	int smallestDiff = INT_MAX;
	for(int i= 0; i< allDiffs.size(); i++)
	{
		if(allDiffs[i] < smallestDiff) smallestDiff = allDiffs[i];
	}
	return smallestDiff;	
}

int main()
{
	vector<int> a = {3,1,2,4,3};
	cout<<"Smallest difference in vector is: "<<tapeEquil(a)<<endl;
	return 0;
}