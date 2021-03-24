#include<iostream>
#include<stdlib.h>

using namespace std;

double myPow(double x, int n){
	int exponent = n;
	double base = x;
	double total = base;
	if (exponent == 0) return 1.0;
	else if(exponent<0){
		int n_exp = -exponent;
		double i_base = 1.0/base;
		double i_total= i_base;
		while(n_exp > 1){
			i_total*=i_base;
			--n_exp;
		}
		return i_total;
	}
	else{
		while(exponent > 1){
			total *= base;
			--exponent;
		}
	}
	return total;
}

int main(){
	cout<<"3**4= "<<myPow(3.0,4)<<endl;
	cout<<"2**-5= "<<myPow(2.0,-5)<<endl;
	cout<<"1.234**15= "<<myPow(1.234,15)<<endl;
	cout<<"-1**7= "<<myPow(-1.0,7)<<endl;
	cout<<"0**0="<<myPow(0,0)<<endl;
	cout<<"0.25**3= "<<myPow(0.25,3)<<endl;
	cout<<"0.5**-2= "<<myPow(0.5,-2)<<endl;
	return 0;
}