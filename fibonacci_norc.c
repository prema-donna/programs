#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n){
	if (n<1)
		return 0;
	else if(n<3){
		return 1;
	}
	int first = 1;
	int second = 1;
	int sum = 0;
	for(int i= 3; i<=n; i++){
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}

int main(){
	printf("0th value of Fibonacci series: %d\n",fibonacci(0));
	printf("1st value of Fibonacci series: %d\n",fibonacci(1));
	printf("2nd value of Fibonacci series: %d\n",fibonacci(2));
	printf("3rd value of Fibonacci series: %d\n",fibonacci(3));
	printf("4th value of Fibonacci series: %d\n",fibonacci(4));
	printf("5th value of Fibonacci series: %d\n",fibonacci(5));
	printf("6th value of Fibonacci series: %d\n",fibonacci(6));
	printf("7th value of Fibonacci series: %d\n",fibonacci(7));
	printf("8th value of Fibonacci series: %d\n",fibonacci(8));
	printf("9th value of Fibonacci series: %d\n",fibonacci(9));
	printf("10th value of Fibonacci series: %d\n",fibonacci(10));
	printf("11th value of Fibonacci series: %d\n",fibonacci(11));
	printf("12th value of Fibonacci series: %d\n",fibonacci(12));
	printf("13th value of Fibonacci series: %d\n",fibonacci(13));
	
	return 0;
}
