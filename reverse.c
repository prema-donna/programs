#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int reverse(int x){
	int length= 1;
	int div = 10;
	int num = x;
	int reversed = 0;
	int unit = 1;
	
	while(1){
		if(abs(num/pow(div,length)) >= div)
			length++;
		else
			break;
	}
	
	int max_unit = pow(div,length);
	int div_val = max_unit;
	
	while (unit <= max_unit){
		int digit = num / div_val;
		reversed += digit*unit;
		num %= div_val;
		unit *= div;
		div_val /= 10;
	}
	
	printf("Length: %d\n",length+1);
	
	return reversed;
}

int main(){
	int original = -1234567;
	
	printf("Reversed number: %d\n",reverse(original)); 
	
	return 0;
}