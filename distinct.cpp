#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>

using namespace std;

int distinct_nums(vector<int> &A)
{
	unordered_map<int,int> allInts;
	for(int i= 0; i< A.size(); i++) allInts[A[i]]++;
	int count = 0;
	for(unordered_map<int,int>::iterator it = allInts.begin(); it != allInts.end(); ++it) count++;
	return count;
}

int main()
{
	vector<int> a= {2,1,1,2,3,1};
	cout<<"Number of distinct numbers in array is "<<distinct_nums(a)<<endl;
	return 0;
}