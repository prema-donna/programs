#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_palindrome(char string[]){
for (int i= 0; i< strlen(string)/2; i++){
	if (string[i] != string[strlen(string)-1-i]) 
		return 0;
}
	return 1;
}
int main(){
	
	char string[] = "aa";
	
	int palindrome = is_palindrome(string);
	
	if (palindrome == 1){
		printf("String is a palindrome");
	}
	
	else{
		printf("String is not a palindrome");
	}
	
	return 0;
}


