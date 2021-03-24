#include<stdio.h>
#include<stdlib.h>

__global__ void add(int *a, int *b, int *c){
	*c = *a + *b;
}

__global__ void subtract(int *a, int *b, int *c){
	*c = *a - *b;
}

__global__ void multiply(int *a, int *b, int *c){
	*c = *a * *b;
}

__global__ void divide(int *a, int *b, int *c){
	*c = *a / *b;
}

int main(void){
	int a, b, c; 			//host copies of a, b, c
	int *d_a, *d_b, *d_c;	//device copies of a, b, c
	int size = sizeof(int);
	
	//Allocate space for device copies of a, b, c
	cudaMalloc((void **)&d_a, size);
	cudaMalloc((void **)&d_b, size);
	cudaMalloc((void **)&d_c, size);
	
	//Setup input values
	a = 2;
	b = 7;
	
	//Copy inputs to device
	cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);
	
	//Launch add() kernel on GPU
	add<<<1,1>>>(d_a,d_b,d_c);
	
	//Copy result back to host
	cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
	printf("%d + %d = %d\n",a,b,c);
	
	//Launch subtract() kernel on GPU
	subtract<<<1,1>>>(d_a,d_b,d_c);
	cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
	printf("%d - %d = %d\n",a,b,c);
	
	//Launch multiply() kernel on GPU
	multiply<<<1,1>>>(d_a,d_b,d_c);
	cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
	printf("%d * %d = %d\n",a,b,c);
	
	//Launch divide() kernel on GPU
	divide<<<1,1>>>(d_a,d_b,d_c);
	cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
	printf("%d / %d = %d\n",a,b,c);
	
	//Cleanup
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
	
	return 0;
}