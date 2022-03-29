#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "win.h"
#include "setUpAndPlay.h"
#include "cleanUp.h"

//Checks if a player has won
bool win(char** board, int numRow, int numCol, int numPiecesWin){
	return  rowWin(board, numRow, numCol, numPiecesWin) ||
            vertWin(board, numRow, numCol, numPiecesWin, 'O', 'X') ||
            vertWin(board, numRow, numCol, numPiecesWin, 'X', 'O') ||
            diagWin(board, numRow, numCol, numPiecesWin);
}

//Stops the game if someone won
bool isGameOver(char** board, int numRow, int numCol, int numPiecesWin){

	return win(board, numRow, numCol, numPiecesWin) ||  tie(board, numRow, numCol);
}


//Checks if a player won in the horizontal rows
bool rowWin(char** board, int numRow, int numCol, int numPiecesWin){
	int row;

	for(row = 0; row < numRow; ++row){ //If the pieces in the row are the same, someone won
		if(isSame(board[row], 'X', 'O', numCol, numPiecesWin) || isSame(board[row], 'O', 'X', numCol, numPiecesWin)){
			return true;
		}
	}

	return false; //No one won
}

//Checks if the correct number of pieces are the same to see if someone won
bool isSame(char* board, char userPiece, char opponentPiece, int len, int numPiecesWin){
	int i, numPieces = 0;

	for(i = 0; i < len; ++i){
		if(board[i] == userPiece){
			numPieces++; //Number of pieces that were the same in that row
		}
		else if(board[i] == opponentPiece || board[i] == '*'){
            numPieces = 0; //Resets counter because there is a gap
        }
        if(numPieces >= numPiecesWin){ //A player won
            return true;
		}
	}

	return false; //No one won
}

//Checks if a player won in the vertical columns
bool vertWin(char** board, int numRow, int numCol, int numPiecesWin, char userPiece, char opponentPiece){
	int col, row;
	int numPieces = 0; //Number of pieces are the same

    for(col = 0; col < numCol; col++){
        for(row = 0; row < numRow; row++){
            if(board[row][col] == userPiece){
                    numPieces++; //Total number of user pieces that are the same
            }
            else if(board[row][col] == opponentPiece || board[row][col] == '*'){
                numPieces = 0; //Resets counter
            }

            if(numPieces == numPiecesWin){//A player won
                return true;
            }

        }
        numPieces = 0; //Resets counter
    }
	return false; //No one won
}

//Checks if a user won diagonally
bool diagWin(char** board, int numRow, int numCol, int numPiecesWin){

	return leftDiagWin(board, numRow, numCol, numPiecesWin, 'O') || leftDiagWin(board, numRow, numCol, numPiecesWin, 'X') || rightDiagWin(board, numRow, numCol, numPiecesWin, 'O')|| rightDiagWin(board, numRow, numCol, numPiecesWin, 'X');
}

bool leftDiagWin(char** board, int numRow, int numCol, int numPiecesWin, char piece){
/*
Checks the center diagonal and top diagonals to see if a player won
X   X   X
	X   X
		X
*/

    int numPieces = 0, count;
    int row, col;

    //The start of the check changes depending on numRow and numCol
    if(numRow < numCol){
        count = 1;
    }
    else{
        count = 0;
    }

    for(count = count; count < numCol; count++){
        for(row = 0, col = count; col < numCol; ++row, ++col){
            if(board[row][col] == piece){
                numPieces++; //Number of pieces that are the same
            }
            else{ //There is a gap '*' or other character, so counter is reset
                numPieces = 0;
            }
            if(numPieces == numPiecesWin){
                return true; //A player won
            }
        }
        numPieces = 0; //Reset counter after for next diagonal
    }

/*
Checks the bottom diagonals to see if a player won
*
X	*
X	x	*
*/

    //The start of the check changes depending on numRow and numCol
    if(numRow < numCol){
        count = 0;
    }
    else{
        count = 1;
    }

    for(count = count; count < numRow; count++){
        for(col = 0, row = count; row < numRow; ++row, ++col){
            if(board[row][col] == piece){
                numPieces++; //Number of pieces that are the same
            }
            else if(numPieces == numPiecesWin){
                return true; //A player won
            }
            else{ //There is a gap '*' or other character, so counter is reset
                numPieces = 0;
            }
        }
        numPieces = 0; //Resets counter after for next diagonal
    }

	return false; //No one won
}

bool rightDiagWin(char** board, int numRow, int numCol, int numPiecesWin, char piece){
/*
Checks the center diagonal and top diagonals to see if a player won
X   X   X
X	X
X
*/

    int numPieces = 0, count;
    int row, col, n;


    //The start of the check changes depending on numRow and numCol
    if(numRow > numCol){
        n = 2;
    }
    else{
        n = 1;
    }

    for(count = numRow - n; count >= 0; count--){
        for(col = 0, row = count; row >= 0; --row, ++col){
            if(board[row][col] == piece){
                numPieces++; //Number of pieces that are the saame
            }
            else{ //There is a gap '*' or other character, so counter is reset
                numPieces = 0;
            }
            if(numPieces == numPiecesWin){
                return true; //A player won
            }
        }
        numPieces = 0; //Reset counter after for next diagonal
    }

/*
Checks the bottom diagonals to see if a player won
        *
	*   X
*	X	X
*/

    //The start of the check changes depending on numRow and numCol
    if(numRow < numCol){
        count = 1;
    }
    else{
        count = 0;
    }


    for(count = count; count < numCol; count++){
        for(row = numRow - 1, col = count; col < numCol; row--, col++){
            if(board[row][col] == piece){
                numPieces++; //Number of pieces that are the same
            }
            else{ //There is a gap '*' or other character, so counter is reset
                numPieces = 0;
            }
            if(numPieces == numPiecesWin){
                return true; //A player won
            }
        }
        numPieces = 0; //Reset counter after for next diagonal
    }

	return false; //No one won
}

bool tie(char** board, int numRow, int numCol){

	int row, col;

	//Checks that there are no blank spaces
	for(row = 0; row < numRow; ++row){
		for(col = 0; col < numCol; ++col){
			if(board[row][col] == '*'){ //There's a blank space, so game continues
				return false;
			}
		}
	}

	displayBoard(board, numRow, numCol); //Displays board to the user
	printf("Tie game!");


    cleanUp(&board, numRow); //Frees the board

    exit(0); //Ends the game because there are no more blank spaces

    return true;
}

