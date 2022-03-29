#include <stdlib.h>
#include "cleanUp.h"

//Frees the board
void cleanUp(char*** board, int numRow){

	int row;

	for(row = 0; row < numRow; ++row){
		free((*board)[row]);
	}
	free(*board);

	*board = NULL;

}
