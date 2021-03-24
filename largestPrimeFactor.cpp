#include<iostream>
#include<cmath>

using namespace std;

long int largestPrimeFactor(long int val)
{
	long int pf = 1;
	for(long int i= 3; i<= val/2; i += 2)
	{
		if(val % i == 0)
		{
			bool isPrime = true;
			for(long int j= 2; j<= i/2; j++){
				if(i % j == 0) isPrime = false;
			}
			if(isPrime == true)
			{
				pf = i;
				cout<<"pf = "<<pf<<", ";
			}
		}
	}
	return pf;
}

int main()
{
	long int val = 13195;
	cout<<"The largest prime factor of "<<val<<" is "<<largestPrimeFactor(val)<<endl;
	return 0;
}