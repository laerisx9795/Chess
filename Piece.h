#pragma once
#include<iostream>
using namespace std;

class Piece {
public:
	/* Constructor */
	Piece();

	/* member variable */
	string type = "";	/* King, Queen, Rook, Bishop, kNight, Pawn */
};