#include "Piece.h"
//vector<vector<Piece*>> Piece::board = vector<vector<Piece*>>(10, vector<Piece*>(10, NULL));
Piece*** initializeBoard() {

	Piece*** tempBoard = (Piece***)malloc(sizeof(Piece**) * 10);
	cout << "Initializing tempBoard..." << endl;
	for (int i = 0; i < 10; i++) {

		tempBoard[i] = (Piece**)malloc(sizeof(Piece*) * 10);
		for (int j = 0; j < 10; j++) {

			tempBoard[i][j] = NULL;
		}
	}
	cout << "Initializing finished. " << endl;
	return tempBoard;
}
Piece*** Piece::board = initializeBoard();
