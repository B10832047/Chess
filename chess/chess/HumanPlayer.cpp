#include<iostream>
#include<string>
#include"HumanPlayer.h"
#include"Player.h"
#include"Piece.h"
using namespace std;

/* Constructor */
HumanPlayer::HumanPlayer() {
	pieces.push_back(Piece('K', "d8"));
	pieces.push_back(Piece('Q', "e8"));
	pieces.push_back(Piece('R', "a8"));
	pieces.push_back(Piece('R', "h8"));
	pieces.push_back(Piece('B', "c8"));
	pieces.push_back(Piece('B', "f8"));
	pieces.push_back(Piece('N', "b8"));
	pieces.push_back(Piece('N', "g8"));
	pieces.push_back(Piece('P', "a7"));
	pieces.push_back(Piece('P', "b7"));
	pieces.push_back(Piece('P', "c7"));
	pieces.push_back(Piece('P', "d7"));
	pieces.push_back(Piece('P', "e7"));
	pieces.push_back(Piece('P', "f7"));
	pieces.push_back(Piece('P', "g7"));
	pieces.push_back(Piece('P', "h7"));
}

HumanPlayer::HumanPlayer(int i) {  //區分第二位玩家
	pieces.push_back(Piece('k', "e1"));
	pieces.push_back(Piece('q', "d1"));
	pieces.push_back(Piece('r', "a1"));
	pieces.push_back(Piece('r', "h1"));
	pieces.push_back(Piece('b', "c1"));
	pieces.push_back(Piece('b', "f1"));
	pieces.push_back(Piece('n', "b1"));
	pieces.push_back(Piece('n', "g1"));
	pieces.push_back(Piece('p', "a2"));
	pieces.push_back(Piece('p', "b2"));
	pieces.push_back(Piece('p', "c2"));
	pieces.push_back(Piece('p', "d2"));
	pieces.push_back(Piece('p', "e2"));
	pieces.push_back(Piece('p', "f2"));
	pieces.push_back(Piece('p', "g2"));
	pieces.push_back(Piece('p', "h2"));
}

bool HumanPlayer::OnMove() {
	string cmd, str;
	int index = 0;
	char startX, startY, endX, endY;
	char type = 'x', action;
	bool promote = false;
	cout << "conmend:";
	cin >> cmd;
	startX = cmd[0];
	startY = cmd[1];
	action = cmd[2];
	endX = cmd[3];
	endY = cmd[4];
	string ter;
	ter.push_back(endX);
	ter.push_back(endY);
	if (pieces.at(0).board[startY - '0'][startX - 'a' + 1] == NULL)
	{
		cout << "wrong input." << endl;
		return false;
	}
	else
	{
		pieces[0].board[startY - '0'][startX - 'a' + 1]->posX = startX;
		pieces[0].board[startY - '0'][startX - 'a' + 1]->posY = startY;
		type = pieces[0].board[startY - '0'][startX - 'a' + 1]->type;
		pieces[0].board[startY - '0'][startX - 'a' + 1]->move(action, ter);
	}

	promote = this->promote(type, endY - '0');
	if (promote) {
		bool invalid = false;
		while (!invalid) {
			cout << "Promote type:";
			cin >> str;
			//getline(cin, str);	/* choose which class to promote */
			if (str[0] == 'K' || str[0] == 'k') {
				if (str[1] == 'i') {
					//type = str[0];
					cout << "invalid input." << endl;
				}
				else if (str[1] == 'n') {
					if (str[0] == 'K') {
						type = 'N';
						invalid = true;
					}
					else {
						type = 'n';
						invalid = true;
					}
				}
				else {
					cout << "wrong input." << endl;
					//return false;
				}
			}
			else {
				if (str[0] == 'P' || str[0] == 'p') {
					cout << "invalid input." << endl;
				}
				else if (str[0] == 'Q' || str[0] == 'q' || str[0] == 'B' || str[0] == 'b' || str[0] == 'R' || str[0] == 'r') {
					type = str[0];
					invalid = true;
				}

			}
		}
		this->OnPromote(type, endY - '0', endX - 'a' + 1);
	}
	return true;
}

void HumanPlayer::OnPromote(char type, int y, int x) {
	if (type != 'K' && type != 'k' && type != 'P' && type != 'p') {
		pieces.at(0).board[y][x]->type = type;
	}
}
bool HumanPlayer::promote(char type, int targetY) {
	if (type == 'P' && targetY == 1) {
		return true;
	}
	else if (type == 'p' && targetY == 8) {
		return true;
	}
	return false;
}
