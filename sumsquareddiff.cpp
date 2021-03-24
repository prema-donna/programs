#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int smallestDivisible(int val)
{
	int num = val;
	while(true)
	{
		bool is_divisible = true;
		for(int i= 1; i<= val; i++)
		{
			if(num % i != 0) is_divisible = false;
		}
		if(is_divisible == true) return num;
		num += val;
	}
	return -1;
}

int main()
{
	int val = 20;
	cout<<"The smallest number that can be divided by all numbers from 1 to "<<val<<" without any remainder is "<<smallestDivisible(val)<<endl;
	return 0;
}