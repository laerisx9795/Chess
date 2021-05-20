#pragma once
#include<iostream>
using namespace std;
//last
class Piece {
public:
	static Piece* board[10][10];
	char posX;
	char posY;
	char type;
	int movingTimes = 0;
	/* Constructor */
	Piece(char type, string pos)
	{
		this->type = type;
		posX = pos[0];
		posY = pos[1];
		board[posY][posX] = this;
	}
	void move(char oper, string ter)
	{
		int a = this->posX - 'a' + 1; // change posX format
		int b = ter[0] - 'a' + 1; // change posX format
		if (a > b)
		{
			swap(a, b);
		}
		int c = posY - '0';
		int d = ter[1] - '0';
		if (c > d)
		{
			swap(c, d);
		}
		int diffX, diffY;
		if (ter[0] >= 'a' && ter[0] <= 'h') //calculat diffX and diffY, and check whether ter is invalid
		{
			diffX = ter[0] - posX;
			if (diffX < 0)
			{
				diffX *= -1;
			}
		}
		else
		{
			cout << "invalid destinate" << endl;
			return;
		}
		if (ter[1] > '0' && ter[1] < '9')
		{
			diffY = ter[1] - this->posY;
			if (diffY < 0)
			{
				diffY *= -1;
			}
		}
		else
		{
			cout << "invalid destinate" << endl;
			return;
		}

		int checkWay = 0;//there is no piece on the way to terminate
		if (diffY == 0)  // only posX change
		{
			for (int i = 1; i < diffX; i++)
			{
				if (board[c][a + i] != NULL)
				{
					checkWay = 1;
					break;
				}
			}
		}
		if (diffX == 0)  // only posY change
		{
			for (int i = 1; i < diffY; i++)
			{
				if (board[c + i][a] != NULL)
				{
					checkWay = 1;
					break;
				}
			}
		}
		if (diffX != 0 && diffY != 0 && diffX == diffY)  // moving with diagonal
		{
			for (int i = 1; i < diffX; i++)
			{
				if (board[c + i][a + i] != NULL)
				{
					checkWay = 1;
					break;
				}
			}
		}


		if (oper == '-')  //move
		{
			if (board[ter[1] - '0'][ter[0] - 'a' + 1] == NULL) //judgment whether terminate is NULL before we move
			{
				if (this->type == 'K' || type == 'k')
				{
					if (diffX + diffY == 1 && checkWay == 0) // judgment whether the moving is valid
					{
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid moving, please enter again" << endl;
						return;
					}
				}
				else if (type == 'Q' || type == 'q')
				{
					if ((diffX / diffY == 1 || diffX == 0 || diffY == 0) && checkWay == 0)
					{
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid moving, please enter again" << endl;
						return;
					}
				}
				else if (type == 'R' || type == 'r')
				{
					if ((diffX == 0 || diffY == 0) && checkWay == 0)
					{
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid moving, please enter again" << endl;
						return;
					}
				}
				else if (type == 'B' || type == 'b')
				{
					if (diffX / diffY == 1 && checkWay == 0)
					{
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid moving, please enter again" << endl;
						return;
					}
				}
				else if (type == 'N' || type == 'n')
				{
					if ((diffX == 2 && diffY == 1) || (diffX == 1 && diffY == 2))
					{
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid moving, please enter again" << endl;
						return;
					}
				}
				else if (type == 'P') // bigger blow
				{
					if (movingTimes == 0)
					{
						if (diffX == 0 && (ter[1] - posY == -1 || ter[1] - posY == -2 && checkWay == 0))
						{
							movingTimes++;
							posX = ter[0];
							posY = ter[1];
						}
						if (ter[1] - posY == -2 && posX - 'a' + 2 < 9 && board[posY][posX - 'a' + 2]->type == 'p')  //Passant Capturing
						{
							delete board[ter[1] - '0'][ter[0] - 'a' + 1];
							board[posY][posX - 'a' + 2]->posX = ter[0];
							board[posY][posX - 'a' + 2]->posY = ter[1] + 1;
						}
						else if (ter[1] - posY == -2 && posX - 'a' > 0 && board[posY][posX - 'a']->type == 'p')
						{
							delete board[ter[1] - '0'][ter[0] - 'a' + 1];
							board[posY][posX - 'a']->posX = ter[0];
							board[posY][posX - 'a']->posY = ter[1] + 1;
						}
					}
					else
					{
						if (diffX == 0 && ter[1] - posY == -1)
						{
							movingTimes++;
							posX = ter[0];
							posY = ter[1];
						}
						else
						{
							cout << "invalid moving, please enter again" << endl;
							return;
						}
					}
				}
				else if (type == 'p')
				{
					if (movingTimes == 0)
					{
						if (diffX == 0 && (ter[1] - posY == 1 || ter[1] - posY == 2 && checkWay == 0))
						{
							movingTimes++;
							posX = ter[0];
							posY = ter[1];
						}
						if (ter[1] - posY == 2 && posX - 'a' + 2 < 9 && board[posY][posX - 'a' + 2]->type == 'P')  //Passant Capturing
						{
							delete board[ter[1] - '0'][ter[0] - 'a' + 1];
							board[posY][posX - 'a' + 2]->posX = ter[0];
							board[posY][posX - 'a' + 2]->posY = ter[1] - 1;
						}
						else if (ter[1] - posY == 2 && posX - 'a' > 0 && board[posY][posX - 'a']->type == 'P')
						{
							delete board[ter[1] - '0'][ter[0] - 'a' + 1];
							board[posY][posX - 'a']->posX = ter[0];
							board[posY][posX - 'a']->posY = ter[1] - 1;
						}
					}
					else
					{
						if (diffX == 0 && ter[1] - posY == 1)
						{
							movingTimes++;
							posX = ter[0];
							posY = ter[1];
						}
						else
						{
							cout << "invalid moving, please enter again" << endl;
							return;
						}
					}
				}
			}
			else
			{
				cout << "invalid moving" << endl;
				return;
			}
		}

		else if (oper == 'x')  //killing
		{
			if (board[ter[1] - '0'][ter[0] - 'a' + 1] != NULL) //judgment whether terminate is NULL before we move
			{
				if (type == 'k')
				{
					if (diffX + diffY == 1 && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'A' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'Z') // judgment whether the moving is valid
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'K')
				{
					if (diffX + diffY == 1 && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'a' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'z') // judgment whether the moving is valid
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'q')
				{
					if ((diffX / diffY == 1 || diffX == 0 || diffY == 0) && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'A' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'Z')
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'Q')
				{
					if ((diffX / diffY == 1 || diffX == 0 || diffY == 0) && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'a' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'z')
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'r')
				{
					if ((diffX == 0 || diffY == 0) && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'A' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'Z')
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'R')
				{
					if ((diffX == 0 || diffY == 0) && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'a' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'z')
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'b')
				{
					if (diffX / diffY == 1 && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'A' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'Z')
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'B')
				{
				if (diffX / diffY == 1 && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'a' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'z')
				{
					delete board[ter[1] - '0'][ter[0] - 'a' + 1];
					board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
					posX = ter[0];
					posY = ter[1];
				}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'n')
				{
					if ((diffX == 2 && diffY == 1) || (diffX == 1 && diffY == 2) && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'A' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'Z')
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'N')
				{
				if ((diffX == 2 && diffY == 1) || (diffX == 1 && diffY == 2) && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'a' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'z')
				{
					delete board[ter[1] - '0'][ter[0] - 'a' + 1];
					board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
					posX = ter[0];
					posY = ter[1];
				}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				else if (type == 'p') // bigger blow
				{
					if (movingTimes == 0)
					{
						if (diffX == 0 && (ter[1] - posY == 1 || ter[1] - posY == 2) && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'A' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'Z')
						{
							movingTimes++;
							delete board[ter[1] - '0'][ter[0] - 'a' + 1];
							board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
							posX = ter[0];
							posY = ter[1];
						}
						if (ter[1] - posY == 2 && posX - 'a' + 2 < 9 && board[posY][posX - 'a' + 2]->type == 'P')  //Passant Capturing
						{
							delete board[ter[1] - '0'][ter[0] - 'a' + 1];
							board[posY][posX - 'a' + 2]->posX = ter[0];
							board[posY][posX - 'a' + 2]->posY = ter[1] - 1;
						}
						else if (ter[1] - posY == 2 && posX - 'a' > 0 && board[posY][posX - 'a']->type == 'P')
						{
							delete board[ter[1] - '0'][ter[0] - 'a' + 1];
							board[posY][posX - 'a']->posX = ter[0];
							board[posY][posX - 'a']->posY = ter[1] - 1;
						}
					}
					else
					{
						if (diffX == 0 && ter[1] - posY == -1 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'A' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'Z')
						{
							movingTimes++;
							delete board[ter[1] - '0'][ter[0] - 'a' + 1];
							board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
							posX = ter[0];
							posY = ter[1];
						}
						else
						{
							cout << "invalid killing, please enter again" << endl;
							return;
						}
					}
				}
				else if (type == 'P')
				{
				if (movingTimes == 0)
				{
					if (diffX == 0 && (ter[1] - posY == -1 || ter[1] - posY == -2) && checkWay == 0 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'a' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'z')
					{
						movingTimes++;
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					if (ter[1] - posY == -2 && posX - 'a' + 2 < 9 && board[posY][posX - 'a' + 2]->type == 'p')  //Passant Capturing
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[posY][posX - 'a' + 2]->posX = ter[0];
						board[posY][posX - 'a' + 2]->posY = ter[1] + 1;
					}
					else if (ter[1] - posY == -2 && posX - 'a' > 0 && board[posY][posX - 'a']->type == 'p')
					{
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[posY][posX - 'a']->posX = ter[0];
						board[posY][posX - 'a']->posY = ter[1] + 1;
					}
				}
				else
				{
					if (diffX == 0 && ter[1] - posY == -1 && board[ter[1] - '0'][ter[0] - 'a' + 1]->type >= 'a' && board[ter[1] - '0'][ter[0] - 'a' + 1]->type <= 'z')
					{
						movingTimes++;
						delete board[ter[1] - '0'][ter[0] - 'a' + 1];
						board[ter[1] - '0'][ter[0] - 'a' + 1] = this;
						posX = ter[0];
						posY = ter[1];
					}
					else
					{
						cout << "invalid killing, please enter again" << endl;
						return;
					}
				}
				}
			}
			else
			{
				cout << "invalid action" << endl;
				return;
			}
		}
	}
};