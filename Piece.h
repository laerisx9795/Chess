#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Piece {
public:
	/* Constructor */
	Piece();

	/* member variable */
	string type = "";	/* King, Queen, Rook, Bishop, kNight, Pawn */
	vector<int>positionX;
	vector<int>positionY;
};