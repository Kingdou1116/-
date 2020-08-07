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
	case Left: return Right;		//自機の左にブロックがあるならブロックの右は自機
	case Right: return Left;		//自機の右にブロックがあるならブロックの左は自機
	case Up: return Down;			//自機の上にブロックがあるならブロックの下は自機
	case Down: return Up;			//自機の下にブロックがあるならブロックの上は自機
	}
	return 0;
}
void Player::Draw() {
	bool Player = true;
	scene->GetMapChip()->DrawChip(X, Y, Player);
}
