#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> makeboard()
{
	vector<string> s;
	for (int i = 0; i < 10; i++)
	{
		string temp;
		switch (i)
		{
		case 0:
			temp = "r n b q k b n r";
			break;
		case 1:
			temp = "p p p p p p p p";
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			temp = "                 ";
			break;
		case 8:
			temp = "P P P P P P P P";
			break;
		case 9:
			temp = "R N B Q K B N R";
			break;
		}
		s.push_back(temp);
	}
	return s;
}
int main()
{
	vector<string> board;
	board=makeboard();
	return 0;
}
