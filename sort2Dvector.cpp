#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<vector>
#include<unordered_set>
#include<ctime>
#include<unordered_map>

using namespace std;

void randomizearr(int arr[100][100]){
	srand(time(NULL));
	for(int i= 0; i< 100; i++){
		for(int j= 0; j< 100; j++){
			arr[i][j] = rand() % 10000;
		}
	}
}

void printarr(int arr[100][100]){
	for(int i= 0; i< 100; i++){
		cout<<"[ ";
		for(int j= 0; j< 100; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}
}

void printSet(unordered_set<int> s){
	cout<<"[";
	for(unordered_set<int>::iterator it = s.begin(); it != s.end(); it++){
		cout<<*it<<" ";
	}
	cout<<"]"<<endl;
}

unordered_set<int> findDups(int arr[100][100]){
	unordered_map<int,int> nums;
	for(int i= 0; i< 100; i++){
		for(int j= 0; j< 100; j++){
			nums[arr[i][j]] = 1;
		}
	}
	unordered_set<int> s;
	for(int i= 0; i< 10000; i++){
		if(nums[i] != 0) s.insert(i);
	}
	return s;
}

int main(){
	int arr[100][100];
	randomizearr(arr);
	//printarr(arr);
	printSet(findDups(arr));
	return 0;
}