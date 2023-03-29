#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	cout << "===============" << endl;
	cout << "[몬스터 정보] HP:" << _hp << " Att:" << _attack << " DEF:" << _defence << endl;
	cout << "===============" << endl;
}