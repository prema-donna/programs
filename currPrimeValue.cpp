#include<iostream>

using namespace std;

int determineNthPrime(int n)
{
	if(n < 1) return 0;
	if(n == 1) return 2;
	int currPrimeIndex = 2;
	int currPrimeValue = 3;
	while(currPrimeIndex < n)
	{
		bool isPrime = true;
		currPrimeValue += 2;
		for(int i = 2; i< currPrimeValue/2; i++)
		{
			if(currPrimeValue % i == 0) isPrime = false; 
		}
		if(isPrime == false) continue;
		else currPrimeIndex++;
	}
	return currPrimeValue;
}

int main()
{
	int n;
	cout<<"Please enter the term of the prime number that you want to see: ";
	cin>>n;
	cout<<"The "<<n<<"th prime is "<<determineNthPrime(n)<<endl;
	return 0;
}