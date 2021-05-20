#pragma once
#include<iostream>
#include<vector>
#include"Piece.h"
using namespace std;

class Player {
public:
	/* Constructor */
	Player();

	virtual bool OnMove(/* Board& const board, Position& outFromPos, Position& outToPos */) = 0;
	virtual void OnPromote(char type, int y, int x) = 0;
	virtual bool promote(char type, int targetY) = 0;

	/* member variable */
	vector<Piece> pieces;
};