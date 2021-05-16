#include<iostream>
#include<string>
#include"HumanPlayer.h"
using namespace std;

/* Constructor */
HumanPlayer::HumanPlayer() {
	pieces.push_back(Piece("King"));
	pieces.push_back(Piece("Queen"));
	pieces.push_back(Piece("Rook"));
	pieces.push_back(Piece("Rook"));
	pieces.push_back(Piece("Bishop"));
	pieces.push_back(Piece("Bishop"));
	pieces.push_back(Piece("Knight"));
	pieces.push_back(Piece("Knight"));
	for (int i = 0; i < 8; i++) {
		pieces.push_back(Piece("Pawn"));
	}
}

void HumanPlayer::OnMove() {
	string cmd, type;
	int index = 0;
	int startX = 0, startY = 0, endX = 0, endY = 0;
	char action;
	bool promote = false;
	getline(cin, cmd);
	index = cmd.find_first_of(' ');
	type = cmd.substr(0, index);	/* get type of piece */
	cmd = cmd.substr(index + 1, cmd.size() - index);
	if (cmd.size() == 5) {
		/* current position of the piece */
		if (cmd[0] >= 'a' && cmd[0] <= 'z') {
			startX = cmd[0] - 'a';
		}
		if (cmd[1] >= '0' && cmd[1] <= '9') {
			startY = cmd[1] - '0';
		}
		/* target position and action of the piece */
		if (cmd[2] >= 'a' && cmd[2] <= 'z') {
			endX = cmd[2] - 'a';
		}
		else if (cmd[2] == '-' || cmd[2] == 'x') {	/* move or capture */
			action = cmd[2];
		}
		if (cmd[3] >= '0' && cmd[3] <= '9') {
			endY = cmd[3] - '0';
		}
		else if (cmd[3] >= 'a' && cmd[3] <= 'z') {
			endX = cmd[3] - 'a';
		}
		if (cmd[4] == '+') {	/* checkmate */
			action = cmd[4];
		}
		else if (cmd[4] >= '0' && cmd[4] <= '9') {
			endY = cmd[4] - '0';
		}
		for (int i = 0; i < pieces.size(); i++) {
			if (pieces.at(i).type == type) {	/* find the piece */
				if (pieces.at(i).positionX.back() == startX && pieces.at(i).positionY.back() == startY) {
					/* call this piece's function to action */
					/* promote */
					promote = this->promote(type, endY);
					if (promote) {
						getline(cin, cmd);	/* choose which class to promote */
						//this->OnPromote();
						/* call this piece's function to promote */
					}
				}
			}
		}
	}
	else {
		cout << "wrong input." << endl;
	}
}
//void HumanPlayer::OnPromote() {
//	string cmd;
//	getline(cin, cmd);
//}
bool HumanPlayer::promote(string type, int targetY) {
	if (type == "Pawn") {
		if (targetY == 0 || targetY == 7) {
			return true;
		}
	}
	return false;
}