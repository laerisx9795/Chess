#include<iostream>
#include"GameManager.h"
#include"HumanPlayer.h"
#include<vector>
using namespace std;

GameManager::GameManager() {
	players[0] = new HumanPlayer;
	players[1] = new HumanPlayer;
	current_player = 0;
	state = 0;
	gameResult = 0;
}

int GameManager::checkMate(Piece* board[][10]) {
	bool K = false;
	bool k = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j]->type == 'K') {
				K = true;
			}
			else if (board[i][j]->type == 'k') {
				k = true;
			}
		}
	}
	if (K && !k) {	/* player2 lose */
		return 1;
	}
	else if (!K && k) {	/* player1 lose */
		return 2;
	}
	else {
		return 0;
	}
}
bool GameManager::checkDraw() {
	return false;
}
bool GameManager::gameLoop() {
	if (state == 0) {	/* game loop */
		while (!players[current_player]->OnMove());	/* move piece */
		//if (players[current_player]->promote()) {	/* Pawn promote */
		//	players[current_player]->OnPromote();
		//}
		state = result();	/* check gameover */	
		viewer.Print(state);	/* print out board, pieces and other information */
		current_player = (current_player + 1) % 2;	/* next player */
		return true;
	}
	else {
		gameResult = state;
		viewer.Print(gameResult);	/* print out board, pieces and other information */
		return false;
	}
}
int GameManager::result() {
	if (checkMate(players[0]->pieces.at(0).board) == 2) {	/* player1's King isn't exist -> player2 wins */
		return 2;
	}
	else if (checkMate(players[1]->pieces.at(0).board) == 1) {	/* player2's King isn't exist -> player1 wins */
		return 1;
	}
	else if (checkDraw()) {	/* draw */
		return 3;
	}
	else {	/* continue */
		return 0;
	}
}