#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unsigned long int triangleNumberWithNumFactors(int num)
{
	unordered_map<int,int> numFactors;
	vector<int> triangleNums = {1,3};
	int numFactor = 2;
	int currIndex = 2;
	if(num < 1) return 0;
	if(num == 1) return 1;
	while(true)
	{
		currIndex++;
		triangleNums.push_back(triangleNums[currIndex-2]+currIndex);
		for(int i= 2; i<= triangleNums[currIndex-1]/2; i++)
		{
			if(triangleNums[currIndex-1] % i == 0) numFactor++;
		}
		numFactors[triangleNums[currIndex-1]] = numFactor;
		if(numFactor >= num) break;
		numFactor = 2;
	}
	return (unsigned long int)triangleNums[triangleNums.size()-1];
}

int main()
{
	int num;
	cout<<"Set number of factors for a triangle number to reach: ";
	cin>>num;
	cout<<"The triangle number with "<<num<<" or more factors is: "<<triangleNumberWithNumFactors(num)<<endl;
	return 0;
}