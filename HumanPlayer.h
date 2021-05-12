#pragma once
#include<iostream>
#include"Player.h"
using namespace std;

class HumanPlayer :public Player {
public:
	/* Constructor */
	HumanPlayer();

	virtual void OnMove() override;
	void OnPromote()override;
	bool promote() override;
};