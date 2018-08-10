#include<iostream>
#include<cstdlib>

using namespace std;

int generalizedGCD(int num, int* arr)
{
    // WRITE YOUR CODE HERE 
    int largest_number = -1;
    int good_count = 0;
    
    for(int i= 0; i<num; i++){
        if (arr[i] > largest_number){
            largest_number = arr[i];
        }
    }
    while(largest_number > 1){
        for(int i= 0; i<num; i++){
            if(arr[i] >= largest_number && arr[i] % largest_number == 0){
                good_count++;
            }
        }
        if(good_count == num){
            return largest_number;
        }
        else{
            good_count = 0;
            largest_number--;  
        } 
    }
    return 1;
}

void print(int* array,int num){
	cout<<"Array: ";
	for(int i= 0; i<num-1; i++){
		cout<<array[i]<<",";
	}
	cout<<array[num-1]<<"\n";
}

int main(){
	int num = 5;
	int arr[] = {2, 4, 6, 8, 10};
	print(arr,num);
	cout<<"Greatest Common Denominator for the Array: "<<generalizedGCD(num,arr)<<"\n";
	
	int arr2[] = {1, 3, 4, 5, 80};
	print(arr2,num);
	cout<<"Greatest Common Denominator for the Array: "<<generalizedGCD(num,arr2)<<"\n";
	
	return 0;
}