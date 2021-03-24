#include<stdio.h>
#include<stdlib.h>

void is_prime(int n){
	int num = 2;
	int num_primes = 0;
	printf("List of primes: ");
	while(num <= n){
		int count = 0;
		for(int i= 1; i<= num; i++){
			if(num%i == 0) count++;
		}
		if(count == 2){ 
			printf("%d,", num);
			num_primes++;
		}
		num++;
	}
	printf("\nNumber of primes: %d", num_primes);
}

int main(){
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	is_prime(n);
	
	return 0;
}