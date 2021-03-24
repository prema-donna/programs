#include<iostream>
#include<vector>

using namespace std;

unsigned long int sumPrimes(unsigned long int limit)
{
  if (limit < 2) return 0;
  if (limit == 2) return 2;
  vector<unsigned long int> primes = {2};
  unsigned long int currNum = 3;
  for(unsigned long int i= 3; i< limit; i +=2)
  {
    bool isPrime = true;
    for(unsigned long int j= 2; j< i/2; j++)
    {
      if(i % j == 0)
      {
        isPrime = false;
        break;
      }
    }
    if(isPrime) primes.push_back(i);
  }
  unsigned long int sum = 0;
  for(unsigned long int i= 0; i< primes.size(); i++)
  {
    sum += primes[i];
  }
  return sum;
}

int main()
{
  unsigned long int limit;
  cout<<"Please list a natural number limit (i.e. 2000000): ";
  cin>>limit;
  cout<<"The sum of primes below "<<limit<<" is: "<<sumPrimes(limit)<<endl;
  return 0;
}
