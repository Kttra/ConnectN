#ifndef SETUPANDPLAY_H
	#define SETUPANDPLAY_H

    void assignValues(int* numRow, int* numCol, int* numPieccesWin, char* argv[]);
    void setUp(char*** board, int* turn, int numRow, int numCol);
    char** makeBoard(int numRow, int numCol);
    void displayBoard(char** board, int numRow, int numCol);
    void getMove(char** board, int* row, int* col, int numRow, int numCol);
    void declareWinner(char** board, int turn);
    void playMove(char** board, int row, int col, int turn);
    void changeTurn(int* turn);

#endif
