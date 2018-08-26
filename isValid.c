#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isValidSudoku(char board[9][10], int boardRowSize, int boardColSize){
	//check for a duplicate in the same row
	for(int i = 0; i< boardColSize; i++){
		char col = board[i][0];
		//if ((col != '.' || col != '\0') && (col < '1' || col > '9')) return false;
		for(int j = 1; j< boardColSize; j++){
			if (col == board[i][j] && (col != '.' || col != '\0')) return false;
		}
	}
	
	//check for a duplicate in the same column
	for(int j= 0; j< boardRowSize; j++){
		char row = board[0][j];
		//if (row != '.' && (row < '1' || row > '9')) return false;
		for(int i= 1; i< boardRowSize; i++){
			if (row == board[i][j] && row != '.') return false;
		}
	}
	
	//check 3 by 3 for duplicate 
	
	return true;
}

int main(){
char table[9][10]= {{'5','3','.','.','7','.','.','.','.','\0'},
					{'6','.','.','1','9','5','.','.','.','\0'},
					{'.','9','8','.','.','.','.','6','.','\0'},
					{'8','.','.','.','6','.','.','.','3','\0'},
					{'4','.','.','8','.','3','.','.','1','\0'},
					{'7','.','.','.','2','.','.','.','6','\0'},
					{'.','6','.','.','.','.','2','8','.','\0'},
					{'.','.','.','4','1','9','.','.','5','\0'},
					{'.','.','.','.','8','.','.','7','9','\0'}};
					
	int boardRowSize = 9;
	int boardColSize = 9;
	
	if (isValidSudoku(table,boardRowSize,boardColSize) == false){
		printf("Not a valid sudoku table!\n");
	}
	else if (isValidSudoku(table,boardRowSize,boardColSize) == true){
		printf("Sudoku table is valid!\n");
	}
	
	return 0;
}