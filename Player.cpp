#include "Player.h"
#include "DxLib.h"
#include "PlayScene.h"
#include "MapChip.h"
Player::Player(PlayScene* _scene, MapChip* _scene2) {
	scene = _scene;
	scene2 = _scene2;
	hImage = -1;
	bool _X = true, _Y = false;
	int Player = 3;
	X = scene->GetMapChip()->CheckMapChip(Player, _X);
	Y = scene->GetMapChip()->CheckMapChip(Player, _Y);

}
Player::~Player() {
	DeleteGraph(hImage);
}
void Player::Update() {
	if (scene->GetMapChip()->CheckRange(X, Y)) {
		static const int Left = 1, Right = 2, Up = 3, Down = 4;
		switch (scene->GetMapChip()->IsFloor(X, Y)) {
		case Left: {
			X--;
			break;
		}
		case Right: {
			X++;
			break;
		}
		case Up: {
			Y--;
			break;
		}
		case Down: {
			Y++;
			break;
		}
		}
	}
}
int Player::NextToPlayer() {
	static const int Left = 1, Right = 2, Up = 3, Down = 4;
	switch (scene->GetMapChip()->NextToBlock(X, Y)) {
	case Left: return Right;		//���@�̍��Ƀu���b�N������Ȃ�u���b�N�̉E�͎��@
	case Right: return Left;		//���@�̉E�Ƀu���b�N������Ȃ�u���b�N�̍��͎��@
	case Up: return Down;			//���@�̏�Ƀu���b�N������Ȃ�u���b�N�̉��͎��@
	case Down: return Up;			//���@�̉��Ƀu���b�N������Ȃ�u���b�N�̏�͎��@
	}
	return 0;
}
void Player::Draw() {
	bool Player = true;
	scene->GetMapChip()->DrawChip(X, Y, Player);
}
