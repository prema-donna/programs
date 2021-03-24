#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<limits>

using namespace std;

int minAvgTwoSlice(vector<int> &A)
{
	unordered_map<int,double> minSumAtIndex;
	for(int i= 0; i< A.size()-1; i++)
	{
		vector<double> allSums;
		int sum = A[i];
		int currLength = 1;
		double average = 0.0;
		for(int j=i+1; j< A.size(); j++)
		{
			sum += A[j];
			currLength++;
			average = (double)sum/currLength;
			allSums.push_back(average);
		}
		double minSum = numeric_limits<double>::max();
		for(int j= 0; j< allSums.size(); j++)
		{
			if(allSums[j] < minSum) minSum = allSums[j];
		}
		minSumAtIndex[i] = minSum;
	}
	double minAvg = numeric_limits<double>::max();
	int index = -1;
	for(unordered_map<int,double>::iterator it= minSumAtIndex.begin(); it != minSumAtIndex.end(); ++it)
	{
		if(it->second < minAvg)
		{
			minAvg = it->second;
			index = it->first;
		}
	}
	return index;
}

int main()
{
	vector<int> a = {4,2,2,5,1,5,8};
	cout<<"The slice that contains the smallest average is "<<minAvgTwoSlice(a)<<endl;
	return 0;
}