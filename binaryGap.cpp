#include<iostream>
#include<cstdlib>
#include<vector>
#include<cmath>

using namespace std;

int length_of_zeroes_in_binary(int N)
{
	int two_pow = 0;
	while(pow(2,++two_pow) <= N);
	string binary(two_pow,'0');
	binary[0] = '1';
	N -= (int)pow(2,--two_pow);
	for(int i= 1; i< binary.length(); i++)
	{
		if(N == 0) break;
		if(pow(2,--two_pow) <= N)
		{
			binary[i] = '1';
			N -= (int)pow(2,two_pow);
		}
	}
	vector<int> gaps;
	int num_zeroes = 0;
	for(int i= 1; i<= binary.length(); i++)
	{
		if (binary[i-1] == '0') num_zeroes++;
		else
		{
			gaps.push_back(num_zeroes);
			num_zeroes = 0;
		}
	}
	if(num_zeroes != 0) gaps.push_back(num_zeroes);
	num_zeroes = -1;
	for(int i= 0; i< gaps.size(); i++)
	{
		if(gaps[i] > num_zeroes) num_zeroes = gaps[i];
	}
	return num_zeroes;
}

int main()
{
	int num;
	cout<<"Enter number: "<<endl;
	cin>>num;
	cout<<"Longest binary gap for "<<num<<": "<<length_of_zeroes_in_binary(num)<<endl;
	return 0;
}