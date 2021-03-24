#include<stdio.h>
#include<string.h>

int checkUnique(char *string){
	for (int i= 0; i<strlen(string); i++){
		char c= string[i];
		for (int j= i+1; j<strlen(string); j++){
			if (c == string[j]) return 0;
		}
	}
	return 1;
}

void printYN(int n){
	if (n == 1) printf("YES");
	else printf("NO");
}

int main(){
	char* s1= "Alon Sterig";
	char* s2= "Alton Sterling";
	char* s3= "abc 123";
	char* s4= "2abc 123def";
	
	int s_1= checkUnique(s1);
	int s_2= checkUnique(s2);
	int s_3= checkUnique(s3);
	int s_4= checkUnique(s4);
	
	printf("Does string 1 contain all unique characters? ");
	printYN(s_1);
	printf("\nDoes string 2 contain all unique characters? ");
	printYN(s_2);
	printf("\nDoes string 3 contain all unique characters? ");
	printYN(s_3);
	printf("\nDoes string 4 contain all unique characters? ");
	printYN(s_4);
	
	return 0;
}