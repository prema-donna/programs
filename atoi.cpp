#include<iostream>
#include<cstdlib>
#include<string>
#include<climits>

using namespace std;

int atoi(string str){
	int sign= 1;
	int base= 0;
	int i= 0;
	
	while(str[i] == ' '){
		i++;
	}
	if(str[i] == '-' || str[i] == '+'){
		sign= 1- 2*(str[i++] == '-');
	}
	while(str[i] >= '0' && str[i] <= '9'){
		if(base > INT_MAX/10 || (base == INT_MAX/10 && str[i]-'0' > 7)){
			if(sign == 1) return INT_MAX;
			else 
				return INT_MIN;
		}
		base= 10*base+(str[i++]-'0');
	}
	
	return base*sign;
}

int main(){
	string str = "   -42";
	
	cout<<"Atoi of "<<str<<" is: "<<atoi(str)<<endl;
	
	return 0;
}