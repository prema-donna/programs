#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int kadane(vector<int> vals)
{
	int currMax = INT_MIN;
	int currSum = 0;
	for(int i= 0; i< vals.size(); i++)
	{
		currSum += vals[i];
		if(currMax < currSum) currMax = currSum;
		if(currSum < 0) currSum = 0;
	}
	return currMax;
}

int main()
{
	vector<int> vals = {-2,-3,4,-1,-2,1,5,-3};
	cout<<"Maximum sum is: "<<kadane(vals)<<endl;
	
	vector<int> vals2 = {-13,-3,-25,-20,-3,-16,-23,-12,-15,-4,-7};
	cout<<"Maximum sum is: "<<kadane(vals2)<<endl;
	
	return 0;
}
	