#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include "inputVal.h"

//Checks if user typed correct number of inputs
void checkArgs(int argc, char* argv[], int numArgsNeeded){

    if(numArgsNeeded > argc){ //Number of arguments entered is less than the required number
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }

    else if(numArgsNeeded < argc){ //Number of arguments entered is more than the required number
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }

    return;

}

//Checks if user's move is valid
bool isValidMove(int numArgsRead, int numArgsNeeded,  char** board, int* row, int col, int numRow, int numCol){

	return isValidFormatting(numArgsRead, numArgsNeeded) &&
				 moveRestraintsMet(board, row, col, numRow, numCol);
}

bool isValidFormatting(int numArgsRead, int numArgsNeeded){
	/* check if the format on the entered input is correct
		@numArgsRead: the number of format specifiers filled in by scanf
		@numArgsNeeded: the number of format specifiers you expected to be filled in
		@returns: true if the format is correct and false otherwise
		@side effects: consumes all characters on the standard input
		*/
	char newLine = '\n';
	bool isValid = true; //Assumes the format is correct

	if(numArgsRead != numArgsNeeded){ //Did not fill in all the format specifiers
		isValid = false;//Format is not correct
	}

	do{
		scanf("%c", &newLine); //Reads the next character from the standard input
		if(!isspace(newLine)){ //If it isn't white space
			isValid = false; //There is extra input there so format isn't valid
		}
	}while(newLine != '\n'); //Keeps reading characters until it reaches the new line character

	return isValid;
}

//Checks if user's move is valid
bool moveRestraintsMet(char** board, int* row, int col, int numRow, int numCol){

	return moveInsideBoard(*row, col, numRow, numCol) && isBlankSpace(board, row, col);
}

//Checks if user's move is inside the board
bool moveInsideBoard(int row, int col, int numRow, int numCol){

	return row >= 0 && row < numRow && col >= 0 && col < numCol;
}

//Checks if there is space for the move in the board
bool isBlankSpace(char** board, int* row, int col){
	int numRow = *row + 1; //Total number of rows

    do{
        if(board[*row][col] == '*'){ //If the spot is open, move is valid
            return true;
        }
        else{ //Moves up a row if location is not open
            *row = *row - 1;

            if(*row < 0){ //Row is negative, so there is no open spaces
                *row = numRow - 1;
                return false;
            }
        }
    }while(board[*row][col] != '*');

    return true;
}
