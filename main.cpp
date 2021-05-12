#include<iostream>
#include"GameManager.h"
using namespace std;

int main() {
	/* if user press 0, start the game. */
	/* if user press 1, exit.*/
	while (1) {
		char ch = getchar();
		if (ch == '0') {
			GameManager game;

			while (game.gameResult == 0) {	/* game loop */
				game.players[game.current_player]->OnMove();	/* move piece */
				if (game.players[game.current_player]->promote()) {	/* Pawn promote */
					game.players[game.current_player]->OnPromote();
				}
				game.gameResult = game.result();	/* check gameover */
				game.viewer.Print();	/* print out board, pieces and other information */
				game.current_player = (game.current_player + 1) % 2;	/* next player */
			}

		}
		else if (ch == '1') {	/* close the application */
			return 0;
		}
	}
}