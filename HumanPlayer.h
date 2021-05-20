#pragma once
#include<iostream>
#include"Player.h"
using namespace std;

class HumanPlayer :public Player {
public:
	/* Constructor */
	HumanPlayer();
	HumanPlayer(int i);	/* for second player */

	virtual bool OnMove() override;
	void OnPromote(char type, int y, int x) override;
	bool promote(char type, int targetY) override;
};