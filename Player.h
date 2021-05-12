#pragma once
#include<iostream>
#include<vector>
#include"Piece.h"
using namespace std;

class Player {
public:
	/* Constructor */
	Player();

	virtual void OnMove(/* Board& const board, Position& outFromPos, Position& outToPos */) = 0;
	virtual void OnPromote(/* Board& const board, Position& const pawnPos, PieceType& outType*/) = 0;
	virtual bool promote(/* Board& const board, Position& const pawnPos, PieceType& outType */) = 0;

	/* member variable */
	vector<Piece> pieces;
};