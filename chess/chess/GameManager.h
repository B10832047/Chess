#pragma once
#include<iostream>
#include<vector>
#include"Player.h"
#include"Viewer.h"
using namespace std;

class GameManager {
public:
	/* Constructor */
	GameManager();

	int checkMate(Piece*** board);
	bool checkDraw();
	bool gameLoop();
	int result();

	/* member varible */
	Player* players[2];	/* two players. 0 : white; 1 : black */
	int current_player;	/* point to current player */
	int state;	/* state of the game. 0 : continue; other : finish */
	int gameResult;	/* 1 : player1 wins; 2 : player2 wins; 3 : draw */
	Viewer viewer;	/* print all information */

};
