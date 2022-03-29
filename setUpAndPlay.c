#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "setUpAndPlay.h"
#include "inputVal.h"

void assignValues(int* numRow, int* numCol, int* numPiecesWin, char* argv[]){
    //Assigns the values inputted by the user to variables

    *numRow = atoi(argv[1]);
    *numCol = atoi(argv[2]);
    *numPiecesWin = atoi(argv[3]);

    return;
}

//Creates the board
void setUp(char*** board, int* turn, int numRow, int numCol){

	*board = makeBoard(numRow, numCol);
	*turn = 0; //Player 1 is 0, Player 2 is 1
}

//Allocates space for the board
char** makeBoard(int numRow, int numCol){

	char** board = (char**)malloc(numRow * sizeof(char*));
	int i,j;

	for(i = 0; i < numRow; ++i){
		board[i] = (char*)malloc(numCol * sizeof(char));

		for(j = 0; j < numCol; ++j){
			board[i][j] = '*';
		}
	}

	return board;
}

//Prints out the board to the user
void displayBoard(char** board, int numRow, int numCol){
	int row, col;

	for(row = 0; row < numRow; ++row){
		printf("%d ", numRow - 1 - row); //Prints out the row number
		for(col = 0; col < numCol; ++col){
			printf("%c ", board[row][col]); //Prints out the characters in the board
		}
		printf("\n");
	}

	printf("  ");

	for(col = 0; col < numCol; ++col){
        printf("%d ", col); //Prints out the column number
    }

    printf("\n");
}

void getMove(char** board, int* row, int* col, int numRow, int numCol){
    *row = numRow - 1; //Set row to the bottom of the board

	int numArgsRead;

	do{ //Continues to ask user for input until they type in a valid input
		printf("Enter a column between 0 and %d to play in: ", numCol - 1);
		numArgsRead = scanf(" %d", col);
	}while(!isValidMove(numArgsRead, 1, board, row, *col, numRow, numCol));
}

//Plays the move on the board based on whose turn it is
void playMove(char** board, int row, int col, int turn){
	char pieces[] = {'X', 'O'};
	board[row][col] = pieces[turn];
}

//Changes whose turn it is next
void changeTurn(int* turn){
	*turn = (*turn + 1) % 2;
}

//Tells the user who won the game
void declareWinner(char** board, int turn){

		if(turn == 1){
			printf("Player 1 Won!\n");
		}
		else{
			printf("Player 2 Won!\n");
		}

}
