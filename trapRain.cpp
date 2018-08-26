#include<iostream>
#include<cstdlib>

using namespace std;

int trap(int A[], int n){
	int left= 0;
	int right= n-1;
	int res= 0;
	int maxleft= 0;
	int maxright= 0;
	
	while(left <= right){
		if(A[left] <= A[right]){
			if(A[left] >= maxleft){
				maxleft= A[left];
			}
			else{
				res += maxleft-A[left];
			}
			left++;
		}
		else{
			if(A[right] >= maxright){
				maxright= A[right];
			}
			else{
				res += maxright-A[right];
			}
			right--;
		}
	}
	
	return res;
}

int main(){
	int input[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int size = 12;
	
	cout<<"The most amount of rain that can be collected is "<<trap(input,size)<<" units\n";
	
	return 0;
}