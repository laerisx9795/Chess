#include<iostream>
#include<string>
#include"HumanPlayer.h"
#include"piece.h"
using namespace std;

/* Constructor */
HumanPlayer::HumanPlayer() {
	pieces.push_back(Piece('K', "d8")); 
	pieces.push_back(Piece('Q', "e8"));
	pieces.push_back(Piece('R', "a8"));
	pieces.push_back(Piece('R', "h8"));
	pieces.push_back(Piece('B', "c8"));
	pieces.push_back(Piece('B', "f8"));
	pieces.push_back(Piece('N', "b8"));
	pieces.push_back(Piece('N', "g8"));
	pieces.push_back(Piece('P', "a7"));
	pieces.push_back(Piece('P', "b7"));
	pieces.push_back(Piece('P', "c7"));
	pieces.push_back(Piece('P', "d7"));
	pieces.push_back(Piece('P', "e7"));
	pieces.push_back(Piece('P', "f7"));
	pieces.push_back(Piece('P', "g7"));
	pieces.push_back(Piece('P', "f7"));
}

HumanPlayer::HumanPlayer(int i) {  //區分第二位玩家
	pieces.push_back(Piece('k', "e1"));
	pieces.push_back(Piece('q', "d1"));
	pieces.push_back(Piece('r', "a1"));
	pieces.push_back(Piece('r', "h1"));
	pieces.push_back(Piece('b', "c1"));
	pieces.push_back(Piece('b', "f1"));
	pieces.push_back(Piece('n', "b1"));
	pieces.push_back(Piece('n', "g1"));
	pieces.push_back(Piece('p', "a2"));
	pieces.push_back(Piece('p', "b2"));
	pieces.push_back(Piece('p', "c2"));
	pieces.push_back(Piece('p', "d2"));
	pieces.push_back(Piece('p', "e2"));
	pieces.push_back(Piece('p', "f2"));
	pieces.push_back(Piece('p', "g2"));
	pieces.push_back(Piece('p', "f2"));
}

bool HumanPlayer::OnMove() {
	string cmd, str;
	int index = 0;
	char startX, startY , endX, endY;
	char type, action;
	bool promote = false;
	getline(cin, cmd);
	/*startX = cmd[0];
	startY = cmd[1];
	action = cmd[2];
	endX = cmd[3];
	endY = cmd[4];*/
	index = cmd.find_first_of(' ');
	str = cmd.substr(0, index);	/* get type of piece */
	if (str[0] == 'K' || str[0] == 'k') {
		if (str[1] == 'i') {
			type = str[0];
		}
		else if (str[1] == 'n') {
			if (str[0] == 'K') {
				type = 'N';
			}
			else {
				type = 'n';
			}
		}
		else {
			cout << "wrong input." << endl;
			return false;
		}
	}
	else {
		type = str[0];
	}
	cmd = cmd.substr(index + 1, cmd.size() - index);
	if (cmd.size() == 5) {
		/* current position of the piece */
		if (cmd[0] >= 'a' && cmd[0] <= 'z') {
			startX = cmd[0];
		}
		if (cmd[1] >= '0' && cmd[1] <= '9') {
			startY = cmd[1];
		}
		/* target position and action of the piece */
		if (cmd[2] >= 'a' && cmd[2] <= 'z') {
			endX = cmd[2];
		}
		else if (cmd[2] == '-' || cmd[2] == 'x') {	/* move or capture */
			action = cmd[2];
		}
		if (cmd[3] >= '0' && cmd[3] <= '9') {
			endY = cmd[3];
		}
		else if (cmd[3] >= 'a' && cmd[3] <= 'z') {
			endX = cmd[3];
		}
		if (cmd[4] == '+') {	/* checkmate */
			action = cmd[4];
		}
		else if (cmd[4] >= '0' && cmd[4] <= '9') {
			endY = cmd[4];
		}
	}
	string ter;
	ter += (endX + endY);
	if (pieces.at(0).board[startY - '0'][startX - 'a' + 1] == NULL)
	{
		cout << "wrong input." << endl;
		return false;
	}
	else
	{
		pieces.at(0).board[startY - '0'][startX - 'a' + 1] -> move(action, ter);
	}
	
	promote = this->promote(type, endY - '0');
	if (promote) {
		getline(cin, str);	/* choose which class to promote */
		if (str[0] == 'K' || str[0] == 'k') {
			if (str[1] == 'i') {
				type = str[0];
			}
			else if (str[1] == 'n') {
				if (str[0] == 'K') {
					type = 'N';
				}
				else {
					type = 'n';
				}
			}
			else {
				cout << "wrong input." << endl;
				return false;
			}
		}
		else {
			type = str[0];
		}
		this->OnPromote(type, startY - '0', startX - 'a' + 1);
	}
	return true;
}

void HumanPlayer::OnPromote(char type, int y, int x) {
	if (type != 'K' && type != 'k' && type != 'P' && type != 'p') {
		pieces.at(0).board[y][x]->type = type;
	}
}
bool HumanPlayer::promote(char type, int targetY) {
	if (type == 'P' && targetY == 1) {
		return true;
	}else if (type =='p' && targetY == 8) {
		return true;
	}
	return false;
}