#ifndef INPUTVAL_H
	#define INPUTVAL_H

	#include <stdbool.h>

    void checkArgs(int argc, char* argv[], int numArgsNeeded);
    bool isValidMove(int numArgsRead, int numArgsNeeded,  char** board, int* row, int col, int numRow, int numCol);
    bool isValidFormatting(int numArgsRead, int numArgsNeeded);
    bool moveRestraintsMet( char** board, int* row, int col, int numRow, int numCol);
    bool moveInsideBoard(int row, int col, int numRow, int numCol);
    bool isBlankSpace(char** board, int *row, int col);

#endif
