#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2){
	int m= nums1.size();
	int n= nums2.size();
	
	if(m >= n){
		vector<int> mergedArray;
		for(int i= 0; i< m; i++){
			for(int j= 0; j< n; j++){
				if(nums1[i] <= nums2[j])
					mergedArray.push_back(nums1[i]);
				else
					mergedArray.push_back(nums2[j]);
			}
		}
		if((m+n)%2 != 0){
			double median= mergedArray[(mergedArray.size()+1)/2];
			return median;
		}
		else{
			double median= (mergedArray[mergedArray.size()/2]+mergedArray[(mergedArray.size()+1)/2])/2;
			return median;
		}
	}
	
	return 0;
}
int main(){
	vector<int> nums1= {1,3};
	vector<int> nums2= {2};
	
	cout<<"Median of the two vectors is: "<<findMedianSortedArrays(nums1,nums2)<<endl;
	
	return 0;
}