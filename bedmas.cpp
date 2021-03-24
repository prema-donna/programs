#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int bedmas(string a){
	string s;
	vector<int> of_ints;
	vector<pair<char,int>> operations;
	vector<int> left_bracket_pos;
	vector<int> right_bracket_pos;
	int sum = 0;
	for(int i= 0; i< a.length(); i++){
		if(a[i] != '(' && a[i] != ')' && a[i] != '+' && a[i] != '-' && a[i] != '*' && a[i] != '/' && a[i] != '^' && a[i] != ' '){
			s += a[i];
		}
		else if(s != ""){
			of_ints.push_back(stoi(s));
			s = "";
			/* if(c ! = '(' || c != ')') operations.push_back(a[i],i);
			else if(c == '(') left_bracket_pos.push_back(i);
			else right_bracket_pos.push_back(i); */
		}
	}
	int oii = 0;
	for(int i= 0; i< a.length(); i++){
		if(a[i] == '^' && a[i-1] != ')'){
			sum += (int)pow(of_ints[oii],of_ints[oii+1]);
			oii += 2;
		}
		else if(a[i] == '^' && a[i-1] == ')'){
			sum = (int)pow(sum,of_ints[oii]);
			oii += 1;
		}
		else if(a[i] == '/' && a[i-1] != ')'){
			sum += (of_ints[oii]/of_ints[oii+1]);
			oii += 2;
		}
		else if(a[i] == '/' && a[i-1] == ')'){
			sum /= of_ints[oii];
			oii += 1;
		}
		else if(a[i] == '*' && a[i-1] != ')'){
			sum += (of_ints[oii]*of_ints[oii+1]);
			oii += 2;
		}
		else if(a[i] == '*' && a[i-1] == ')'){
			sum *= of_ints[oii];
			oii += 1;
		}
		else if(a[i] == '+' && a[i-1] != ')'){
			sum += (of_ints[oii]+of_ints[oii+1]);
			oii += 2;
		}
		else if(a[i] == '+' && a[i-1] == ')'){
			sum += of_ints[oii];
			oii += 1;
		}
		else if(a[i] == '-' && a[i-1] != ')'){
			sum += (of_ints[oii]-of_ints[oii+1]);
			oii += 2;
		}
		else if(a[i] == '-' && a[i-1] == ')'){
			sum -= of_ints[oii];
			oii += 1;
		}
	}
	return sum;
}

int main(){
	string a = "15/5 ";
	cout<<a<<"= "<<bedmas(a)<<endl;
	return 0;
}