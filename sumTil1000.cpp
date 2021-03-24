#include<iostream>
#include<cmath>

using namespace std;

int calculateSum35(int limit)
{
	int i = 3;
	int j = 5;
	int sum = 0;
	while(i < limit || j < limit)
	{
		if(i < limit)
		{
			sum += i;
		}
		if(j < limit)
		{
			sum += j;
		}
		i += 3;
		j += 5;
	}
	return sum;
}

int main()
{
	int limit = 1000;
	cout<<"Sum of all multiples of 3 or 5 below "<<limit<<" is "<<calculateSum35(limit)<<endl;
	return 0;
}