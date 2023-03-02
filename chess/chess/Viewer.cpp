#include"Viewer.h"
#include"Piece.h"
using namespace std;


Viewer::Viewer() 
{

}

void Viewer::Print(int result, Piece*** board)
{
	system("CLS");
	cout << "  abcdefgh" << endl << endl;
	for (int i = 1; i < 9; i++) {
		cout << i << ' ';
		for (int j = 1; j < 9; j++) {
			if (board[i][j] == NULL) 
			{
				cout << " ";
			}
			else 
			{
				cout << board[i][j]->type ;
			}
		}
	//	cout << (char)(i + 96);
		cout << endl;
	}
	cout << endl;
	switch (result) 
	{
	case 2:
		cout << "player2 wins" << endl;
		break;
	case 1:
		cout << "player1 wins" << endl;
		break;
	case 0:
		break;
	}
}
