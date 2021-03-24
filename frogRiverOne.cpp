#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int crossRiver(int x, vector<int> &A)
{
	for(int i= 0; i< A.size(); i++)
	{
		if(x <= A[i]) return i;
	}
	return -1;
}

int main()
{
	vector<int> a = {1,3,1,4,2,3,5,4};
	cout<<"The frog can jump the river at index "<<crossRiver(5,a)<<endl;
	return 0;
}