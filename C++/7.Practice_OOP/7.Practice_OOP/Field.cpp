#include "Field.h"

#include <stdlib.h>
#include "Monster.h"
#include "Player.h"

Field::Field() : _monster(nullptr)
{

}

Field::~Field()
{
	if (_monster)
		delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();

	StartBattle(player);
}

void Field::CreateMonster()
{
	int randValue = 1 + rand() % 3;

	switch (randValue)
	{
	case MT_Slime:
		_monster = new Slime();
		break;
	case MT_Orc:
		_monster = new Orc();
		break;
	case MT_Skeleton:
		_monster = new Skeleton();
		break;
	default:
		break;
	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		// 공격
		_monster->OnAttacked(player);
		if (_monster->IsDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}

		// 방어
		player->OnAttacked(_monster);
		if (player->IsDead())
		{
			player->PrintInfo();
			break;
		}
	}
}