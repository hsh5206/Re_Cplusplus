#include "Game.h"

#include <iostream>
using namespace std;

#include "Player.h"
#include "Field.h"

Game::Game() : _player(nullptr), _field(nullptr)
{

}

Game::~Game()
{
	if (_player)
		delete _player;

	if (_field)
		delete _field;
}

void Game::Init()
{
	_field = new Field();
}

void Game::Update()
{
	if (_player == nullptr)
		CreatePlayer();

	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}

	_field->Update(_player);
}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "-------------- 캐릭터 생성 --------------" << endl;
		cout << "캐릭터 선택 : 기사(1), 궁수(2), 마법사(3)" << endl;
		cout << "-----------------------------------------" << endl;
		int playertype;
		cin >> playertype;

		switch (playertype)
		{
		case PT_Knight:
			_player = new Knight();
			break;
		case PT_Archer:
			_player = new Archer();
		case PT_Mage:
			break;
			_player = new Mage();
			break;
		default:
			break;
		}
	}
}