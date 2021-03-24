#include<iostream>
#include<cstdio>

using namespace std;

int fibonacci(int n){
	int sum = 1;
	int previous = 1;
	int previous2= 0;
	for(int i= 3; i<= n; i++){
		sum = previous2 + previous;
		previous2 = previous;
		previous = sum;
	}
	return sum;
}

int fib_rec(int n){
	if (n == 1) return 0;
	else if(n > 1 && n<= 3) return 1;
	return fib_rec(n-1)+fib_rec(n-2);
}

int main(){
	cout<<"10th term: "<<fibonacci(10)<<endl;
	cout<<"10th term: "<<fib_rec(10);
	
	return 0;
}