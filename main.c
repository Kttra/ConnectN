#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "inputVal.h"
#include "setUpAndPlay.h"
#include "win.h"
#include "cleanUp.h"

void playConnect(int numRow, int numCol, int numPiecesWin);

int main(int argc, char* argv[]){

	int numRow, numCol, numPiecesWin;

    checkArgs(argc, argv, 4); //Checks if user inputted correct number of arguments

    assignValues(&numRow, &numCol, &numPiecesWin, argv); //Assigns the user inputs to variables

    playConnect(numRow, numCol, numPiecesWin); //Starts the game

    return 0;
}

//Starts the game
void playConnect(int numRow, int numCol, int numPiecesWin){
    char** board = NULL;
    int row, col;
    int turn = 0;

    setUp(&board, &turn, numRow, numCol); //Creates the board

    //Continues the game until someone wins or ends in a tie
    while(!isGameOver(board, numRow, numCol, numPiecesWin)){
		displayBoard(board, numRow, numCol);
		getMove(board, &row, &col, numRow, numCol); //Asks user for their move
		playMove(board, row, col, turn); //Plays the move in the board
		changeTurn(&turn); //Switches players
    }

    displayBoard(board, numRow, numCol); //Shows the board
    declareWinner(board, turn); //Tells the user who won
    cleanUp(&board, numRow); //Frees the board

}





