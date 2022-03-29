#ifndef WIN_H
	#define WIN_H

	#include <stdbool.h>

    bool isGameOver(char** board, int numRow, int numCol, int numPiecesWin);
    bool win(char** board, int numRow, int numCol, int numPiecesWin);
    bool rowWin(char** board, int numRow, int numCol, int numPiecesWin);
    bool isSame(char* board, char userPiece, char opponentPiece, int len, int numPiecesWin);
    bool vertWin(char** board, int numRow, int numCol, int numPiecesWin, char userPiece, char opponentPiece);
    bool diagWin(char** board, int numRow, int numCol, int numPiecesWin);
    bool leftDiagWin(char** board, int numRow, int numCol, int numPiecesWin, char piece);
    bool rightDiagWin(char** board, int numRow, int numCol, int numPiecesWin, char piece);
    bool tie(char** board, int numRow, int numCol);

#endif
