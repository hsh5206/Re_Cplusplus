#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "===============" << endl;
	cout << "[�÷��̾� ����] HP:" << _hp << " Att:" << _attack << " DEF:" << _defence << endl;
	cout << "===============" << endl;
}