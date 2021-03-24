#include<iostream>
#include<cstdlib>
#include<unordered_map>
#include<vector>

using namespace std;

bool permCheck(vector<int> &A)
{
	unordered_map<int,int> counts;
	for(int i= 0; i< A.size(); i++) ++counts[A[i]];
	for(int i= 1; i<= A.size(); i++)
	{
		if(counts[i] != 1)
		{
			cout<<"Not a permutation, as "<<i<<" has a count of "<<counts[i]<<endl;
			return false;
		}
	}
	cout<<"Valid permutation detected!"<<endl;
	return true;
}

int main()
{
	vector<int> a = {4,1,3,2};
	vector<int> b = {4,1,3};
	vector<int> c = {4,1,4,2,3};
	permCheck(a);
	permCheck(b);
	permCheck(c);
	return 0;
}