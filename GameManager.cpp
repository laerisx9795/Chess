#include<iostream>
#include"GameManager.h"
#include"HumanPlayer.h"
using namespace std;

GameManager::GameManager() {
	players[0] = new HumanPlayer;
	players[1] = new HumanPlayer;
	current_player = 0;
	state = 0;
	gameResult = 0;
}