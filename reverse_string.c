#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* reverse_string(char* string){
	
	char* reverse = malloc(sizeof(char)*strlen(string));
	
	for (int i= 0; i<= strlen(string); i++){
		reverse[i] = string[strlen(string)-1-i];
	}
	return reverse;
}

int main(){
	char* string = "abcdefghijk";
	
	char* reversed = reverse_string(string);
	
	for (int i= 0; i<= strlen(reversed); i++){
		printf("%c", reversed[i]);
	}
	
	free(reversed);
	
	return 0;
}