#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "===============" << endl;
	cout << "[���� ����] HP:" << _hp << " Att:" << _attack << " DEF:" << _defence << endl;
	cout << "===============" << endl;
}