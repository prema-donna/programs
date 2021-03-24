#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;

int calculator(int one, char op, int two)
{
	if(op == '^') return (int)pow(one,two);
	else if(op == '/') return one/two;
	else if(op == '*') return one*two;
	else if(op == '%') return one%two;
	else if(op == '+') return one+two;
	else if(op == '-') return one-two;
	else if(op == '&') return one&two;
	else if(op == '|') return one|two;
	
	return 0;
}

int main(){

	while(1){
		int one;
		int two;
		char op;
		string quit;
		cout<<"Enter a simple mathematical operation with only integers"<<endl;
		cin>>one>>op>>two;
		cout<<"Result: "<<calculator(one,op,two)<<endl;
		cout<<"Type Q to quit, or type anything to do another operation"<<endl;
		cin>>quit;
		if(quit == "Q" || quit == "q" || quit == "Quit" || quit == "quit" || quit == "QUIT" || quit == "exit" || quit == "EXIT" || quit == "Exit") return 0;
	}
	
	return 0;
}