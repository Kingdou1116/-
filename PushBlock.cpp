#include "PushBlock.h"
#include "DxLib.h"
#include "PlayScene.h"
#include "MapChip.h"
#include "Player.h"
PushBlock::PushBlock( PlayScene* _scene, MapChip* _scene2, Player* _scene3) {
	scene = _scene;
	scene2 = _scene2;
	scene3 = _scene3;
	hImage = -1;
	bool _X = true, _Y = false;
	int Block = 4;
	X = scene->GetMapChip()->CheckMapChip(Block, _X);
	Y = scene->GetMapChip()->CheckMapChip(Block, _Y);
	X = scene->GetMapChip()->CheckMapChip(Block, _X);
	Y = scene->GetMapChip()->CheckMapChip(Block, _Y);
	int Goal = true, Push = false;
	Goals = scene->GetMapChip()->BlockNumber(Goal);
	Blocks = scene->GetMapChip()->BlockNumber(Push);
}
PushBlock::~PushBlock() {
	DeleteGraph(hImage);
}
void PushBlock::Update() {
	if (scene->GetMapChip()->CheckRange(X, Y)) {
		static const int Left = 1, Right = 2, Up = 3, Down = 4;
		int Arrow = scene->GetMapChip()->IsFloor(X, Y, false);
		switch (Arrow) {
		case Left: {
			scene->GetMapChip()->BlockMove(X, Y, Left);		//¶
			X--;
			break;
		}
		case Right: {
			scene->GetMapChip()->BlockMove(X, Y, Right);	//‰E
			X++;
			break;
		}
		case Up: {
			scene->GetMapChip()->BlockMove(X, Y, Up);		//ã
			Y--;
			break;
		}
		case Down: {
			scene->GetMapChip()->BlockMove(X, Y, Down);		//‰º
			Y++;
			break;
		}
		}
	}
}
void PushBlock::Draw() {
	bool Block = false;
	scene->GetMapChip()->DrawChip(X, Y, Block);
	DrawFormatString(600, 50, GetColor(222, 222, 222), "%d", scene->GetPlayer()->NextToPlayer());
}
