#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int largestRectangleArea(vector<int>& height){
	int ret = 0;
	height.push_back(0);
	vector<int> index;
	
	for(int i= 0; i< height.size(); i++){
		while(index.size()> 0 && height[index.back()]>= height[i]){
			int h= height[index.back()];
			index.pop_back();
			int sidx= index.size()> 0 ? index.back(): -1;
			if(h*(i-sidx-1)> ret){
				ret= h*(i-sidx-1);
			}
		}
		index.push_back(i);
	}
	return ret;
}

int main(){
	vector<int> rec= {2,1,5,6,2,3};
	
	cout<<"largest rectangle area: "<<largestRectangleArea(rec)<<endl;
	
	return 0;
}