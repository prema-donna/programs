#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

vector<pair<int,int>> Question2(int max_sum, vector<pair<int,int>> foreground, vector<pair<int,int>> background){
	int largest = 0;
	int pair1 = 0;
	int pair2 = 0;
	vector<pair<int,int>> final;
	for(int i= 0; i< foreground.size(); i++){
		int curr = foreground[i].second;
		for(int j= 0; j< background.size(); j++){
			int sum = curr+background[j].second;
			if(sum <= max_sum && sum > largest){
				largest = sum;
			}
		}
	}
	for(int i= 0; i< foreground.size(); i++){
		int curr = foreground[i].second;
		for(int j= 0; j< background.size(); j++){
			int sum = curr+background[j].second;
			if(sum == largest){
				pair1 = foreground[i].first;
				pair2 = background[j].first;
				final.push_back(make_pair(pair1, pair2));
			}
		}
	}
	
	return final;
}

void print(vector<pair<int,int>> vec){
	for(int i= 0; i< vec.size(); i++){
		cout<<"["<<vec[i].first<<","<<vec[i].second<<"]"<<endl;
	}
}

int main(){
	int fore_array_1a[] = {1,2,3};
	int fore_array_1b[] = {2,4,6};
	int bg_array_1a = 1;
	int bg_array_1b = 2;
	int fore_array_2a[] = {1,2,3};
	int fore_array_2b[] = {8,7,14};
	int bg_array_2a[] = {1,2,3};
	int bg_array_2b[] = {6,1,12};
	vector<pair<int,int>> fore1;
	vector<pair<int,int>> fore2;
	vector<pair<int,int>> bg1;
	vector<pair<int,int>> bg2;
	
	for(int i= 0; i< sizeof(fore_array_1a)/sizeof(int); i++){
		fore1.push_back(make_pair(fore_array_1a[i],fore_array_1b[i]));
		fore2.push_back(make_pair(fore_array_2a[i],fore_array_2b[i]));
		bg2.push_back(make_pair(bg_array_2a[i],bg_array_2b[i]));
	}
	bg1.push_back(make_pair(bg_array_1a,bg_array_1b));
	
	cout<<"Example:"<<endl;
	print(Question2(7, fore1, bg1));
	cout<<"Multi-Solution:"<<endl;
	print(Question2(20, fore2, bg2));
	
	return 0;
}