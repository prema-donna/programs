#include<iostream>
#include<cmath>

using namespace std;

int evenFibonacci(int limit)
{
	int i = 1;
	int j = 1;
	int even_sum = 0;
	while(j <= limit)
	{
		if(j % 2 == 0)
		{
			even_sum += j;
		}
		int temp = j;
		j += i;
		i = temp;
	}
	
	return even_sum;
}

int main()
{
	int limit = 4000000;
	cout<<"Even Fibonacci sum until "<<limit<<" is "<<evenFibonacci(limit)<<endl;
	return 0;
}