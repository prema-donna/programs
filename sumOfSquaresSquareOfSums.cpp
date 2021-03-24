#include<iostream>
#include<cmath>

using namespace std;

int diffSquareSumsAndSumSquare(int nNum)
{
	int squareOfSum = 0;
	int sumOfSquares = 0;
	
	for(int i= 1; i<= nNum; i++)
	{
		squareOfSum += pow(i,2);
		sumOfSquares += i;
	}
	sumOfSquares = pow(sumOfSquares,2);
	return sumOfSquares-squareOfSum;
}

int main()
{
	int n = 0;
	cout<<"Enter a natural number: ";
	cin>>n;
	cout<<"diffSquareSumsAndSumSquare of first "<<n<<" natural numbers is "<<
	diffSquareSumsAndSumSquare(n)<<endl;
}