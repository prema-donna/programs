#include<stdio.h>
#include<stdlib.h>

void swap(int* array, int index1, int index2){
	int temp = array[index2];
	array[index2] = array[index1];
	array[index1] = temp;
}

int* array(int* ar, int length){
	int start = 0;
	int end = length-1;
	
	for(int i= 0; i< length/2; i++){
		swap(ar,start,end);
		start++;
		end--;
	}
	
	return ar;
}

void print(int* ar, int length){
	printf("Array: ");
	for(int i= 0; i< length-1; i++){
		printf("%d, ",ar[i]);
	}
	printf("%d\n", ar[length-1]);
}

int main(){
	int ar[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = 10;
	printf("Original ");
	print(ar, length);
	printf("Reversed ");
	print(array(ar,length),length);
	
	return 0;
}