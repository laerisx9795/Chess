#include <iostream>
#include"GameManager.h"

using namespace std;

int main() {

	cout << "           Project2 - Chess          Group 19" << endl;
	cout << "שÝשששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששß" << endl;
	cout << "שר                                                    שר" << endl;
	cout << "שר  ¡½¡½¡½¡½  ¡½    ¡½  ¡½¡½¡½¡½  ¡½¡½¡½¡½  ¡½¡½¡½¡½  שר" << endl;
	cout << "שר  ¡½        ¡½    ¡½  ¡½        ¡½        ¡½        שר" << endl;
	cout << "שר  ¡½        ¡½¡½¡½¡½  ¡½¡½¡½¡½  ¡½¡½¡½¡½  ¡½¡½¡½¡½  שר" << endl;
	cout << "שר  ¡½        ¡½    ¡½  ¡½              ¡½        ¡½  שר" << endl;
	cout << "שר  ¡½¡½¡½¡½  ¡½    ¡½  ¡½¡½¡½¡½  ¡½¡½¡½¡½  ¡½¡½¡½¡½  שר" << endl;
	cout << "שר                                                    שר" << endl;
	cout << "שדשששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששששו" << endl;
	cout << endl;

	/* if user press 0, start the game. */
	/* if user press 1, exit.*/
	while (1) {
		char ch = getchar();
		if (ch == '0') {
			GameManager game;
			while (game.gameLoop());
		}
		else if (ch == '1') {	/* close the application */
			return 0;
		}
	}
}