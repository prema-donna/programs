#include<iostream>
#include<cmath>

using namespace std;

char* int_to_string(int n)
{
	unsigned int remainder = abs(n);
	char* output = (char*)malloc(12*sizeof(char));
	char* reversed = (char*)malloc(12*sizeof(char));
	int index = 0;
	if(n == 0)
	{
		output[0] = '0';
		return output+'\0';
	}
	while(remainder > 0)
	{
		unsigned int val = remainder % 10; 
		remainder = remainder / 10;
		char letter = '0'+val;
		reversed[index] = letter;
		index++;
	}
	int rindex = 0;
	if(n < 0)
	{
		output[0] = '-';
		rindex += 1;
	}
	for(int i= index-1; i >= 0; i--)
	{
		output[rindex] = reversed[i];
		rindex++;
	}
	free(reversed);
	return output+'\0';
}

int main()
{
	int test;
	cout<<"Enter integer, positive, or negative"<<endl;
	cin>>test;
	cout<<int_to_string(test);
	return 0;
}
