#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_substring(char *longstr, char *small){
	for(int index= 0; index <= strlen(longstr)-strlen(small); index++){
		int sub_index;
		for (sub_index= 0; sub_index< strlen(small); sub_index++){
			if(longstr[index+sub_index] != small[sub_index]) break;
		}
		if (sub_index == strlen(small)) return 1;
	}
	return 0;
}

int main(){
	char* longstr = "My string";
	char* small = "yng";
	
	int substring = is_substring(longstr,small);
	
	if(substring == 1)
		printf("\"Yes\"");
	else if (substring == 0)
		printf("\"No\"");
	
	return 0;
}