#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int palindromicNum(int val)
{
	int num = val-1;
	int mul_val = 0;
	int product = 0;
	while(num >= 1)
	{
		for(int i = num; i >= 1; i--)
		{
			mul_val = i*num;
			string mul_str = to_string(mul_val);
			string mul_str_rev = mul_str;
			reverse(mul_str_rev.begin(),mul_str_rev.end());
			if(mul_str == mul_str_rev && mul_val >= product) product = mul_val;
		}
		num--;
	}
	return product;
}

int main()
{
	int val = 1000;
	cout<<"The largest palindromic number created by multiplying 2 numbers under "<<val<<" is "<<palindromicNum(val)<<endl;
	return 0;
}