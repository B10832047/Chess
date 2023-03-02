#pragma once
#include<iostream>
#include"Piece.h"
using namespace std;

class Viewer {
public:
	/* Constructor */
	Viewer();

	void Print(int result, Piece*** board);
};
