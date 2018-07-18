#include<iostream>
#include<stdlib.h>
#include<string>
#include<math.h>

using namespace std;

public boolean allUnique(string s, int start, int end){
	Set<Character> set= new HashSet<>();
	for (int i= start; i< end; i++){
		Character ch= s.charAt(i);
		if (set.contains(ch)) return false;
		set.add(ch);
	}
	return true;
}

public int lengthOfLongestSubstring(string s){
	int n= s.length();
	int ans= 0;
	for (int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(allisUnique(s,i,j))ans= max(ans,j-i);
	return ans;
}

public static void main(){
	string s1 = "abcabcbb";
	cout<<"length of Longest substring, s1, no repeat: "<<lengthOfLongestSubstring(s1)<<endl;
	string s2 = "bbbbbb";
	cout<<"length of Longest substring, s2, no repeat: "<<lengthOfLongestSubstring(s2)<<endl;
	string s3 = "pwwkew";
	cout<<"length of longest substring, s3, no repeat: "<<lengthOfLongestSubstring(s3)<<endl;
	string s4 = "";
	cout<<"length of longest substring, s4, no repeat: "<<lengthOfLongestSubstring(s4)<<endl;
	
}