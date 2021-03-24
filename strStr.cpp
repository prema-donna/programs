#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int strStr(string haystack, string needle){
	int index = haystack.find(needle);
	return index;
}

int main(){
	string haystack = "hello";
	string needle = "ll";
	
	cout<<"strStr hello, ll: "<<strStr(haystack,needle)<<"\n";
	
	return 0;
}