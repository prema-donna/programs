#include<stdio.h>
#include<stdlib.h>

int* div_array(int* input_array, int size){
	int product= 1;
	int* output_array = malloc(sizeof(int)*sizeof(input_array));
	
	for(int i=0; i<size; i++){
		product *= input_array[i];
	}
	
	for(int i=0; i<size; i++){
		output_array[i] = product/input_array[i];
	}
	
	return output_array;
}

void print(int* array, int size){
	printf("[");
	for(int i= 0; i<size-1; i++){
		printf("%d, ", array[i]);
	}
	printf("%d]\n",array[size-1]);
}

//Case 1
//input_array [1, 2, 1, 5]
//expected output 

//Case 2- one negative
//input array [1, -2, 3, 4]
//expected output [-24, 12, -8, -6]

//Case 3- 2 negatives in input array
//input array [-1, 2, -3, 4]
//expected output [-24, 12, -8, 6]

//Case 4- large array
//input array [-2, -3, 1, 2, 1, 2]
//expected output [-12, -8, 24, 12, 24, 12]

//Case 5- one element
//input array [9]
//expect output [9]

int main(){
	int input_array[] = {1, 2, 10, 5};
	int size = sizeof(input_array)/sizeof(int);
	int* output_array = div_array(input_array,size);
	
	print(output_array,size);
	
	return 0;
}