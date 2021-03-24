#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string dict[8]= {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void letterCombinations(string digits, vector<string>& output, string item, int index){
	if(index==digits.length()){
		output.push_back(item);
		return;
	}

	int num= digits[index]-'2';
	for(int i= 0; i<dict[num].length(); i++){
		letterCombinations(digits,output,item+dict[num][i],index+1);
	}
} 

void print(vector<string> output){
	for(int i= 0; i<output.size(); i++){
		cout<<"['";
		for(int j= 0; j<output[0].size(); j++){
			cout<<output[i][j];
		}
		cout<<"'], ";
	}
}

int main(){
	string numbers = "2953654";
	vector<string> output;
	string item = "";
	int index= 0;
	letterCombinations(numbers,output,item,index);
	
	print(output);
	
	return 0;
}