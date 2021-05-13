#pragma once
#include<iostream>
#include"Player.h"
#include"Board.h"
#include"Viewer.h"
using namespace std;

class GameManager {
public:
	/* Constructor */
	GameManager();

	bool checkMate(vector<Piece> pieces);
	bool checkDraw();
	bool gameLoop();
	int result();

	/* member varible */
	Player* players[2];	/* two players. 0 : white; 1 : black */
	int current_player;	/* point to current player */
	int state;	/* state of the game. 0 : continue; other : finish */
	int gameResult;	/* 1 : player1 wins; 2 : player2 wins; 3 : draw */
	Board board;
	Viewer viewer;	/* print all information */

};