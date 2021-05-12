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

	bool checkMate();
	int result();
	void setup();

	/* member varible */
	Player* players[2];	/* two players. 0 : white; 1 : black */
	int current_player;	/* point to current player */
	int state;	/* state of the game. */
	int gameResult;	/* result of this game. 0 : continue; 1 : player1 wins; 2 : player2 wins; 3 : draw */
	Board board;
	Viewer viewer;	/* print all information */

};