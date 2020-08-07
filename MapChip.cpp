#include "MapChip.h"
#include "DxLib.h"
#include "PlayScene.h"
#include "PushBlock.h"
#include "Count.h"
#include "Player.h"
#include "Keyboard.h"
MapChip::MapChip(PlayScene* _scene) {
	scene = _scene;
	hImage = -1;
}
MapChip::~MapChip() {
	DeleteGraph(hImage);
}
void MapChip::Update() {

}
int MapChip::CheckMapChip(int Mode, bool XorY) {
	for (int X = 0; X < MAPX; X++) {
		for (int Y = 0; Y < MAPY; Y++) {
			switch (MAP_CHIP[Y][X]) {
			case PLAY: {
				if (Mode == PLAY) {
					if (XorY) return X;
					if (!XorY) {
						MAP_CHIP[Y][X] = FLOOR;
						return Y;
					}
				}
			}
			case BLOCK: {
				if (Mode == BLOCK) {
					if (XorY) return X;
					if (!XorY) return Y;
				}
			}
			}
		}
	}
	return 0;
}
int MapChip::BlockNumber(bool Mode) {
	int _GOAL = 0, _Block = 0;
	for (int X = 0; X < MAPX; X++) {
		for (int Y = 0; Y < MAPY; Y++) {
			if (Mode) if (MAP_CHIP[Y][X] == GOAL) _GOAL++;
			else if (MAP_CHIP[Y][X] == BLOCK) _Block++;
		}
	}
	if (Mode)return _GOAL;
	return _Block;
}
int MapChip::IsFloor(int PX, int PY, bool IsPlayer) {
	int LCMD = Keyboard_Get(KEY_INPUT_LEFT), RCMD = Keyboard_Get(KEY_INPUT_RIGHT),
		UCMD = Keyboard_Get(KEY_INPUT_UP), DCMD = Keyboard_Get(KEY_INPUT_DOWN);
	int LX = PX - 1, RX = PX + 1, UY = PY - 1, DY = PY + 1;
	if (IsPlayer) {
		if ((MAP_CHIP[PY][LX] == FLOOR || MAP_CHIP[PY][LX] == GOAL) && LCMD == 1) return LEFT;
		if ((MAP_CHIP[PY][RX] == FLOOR || MAP_CHIP[PY][RX] == GOAL) && RCMD == 1) return RIGHT;
		if ((MAP_CHIP[UY][PX] == FLOOR || MAP_CHIP[UY][PX] == GOAL) && UCMD == 1) return UP;
		if ((MAP_CHIP[DY][PX] == FLOOR || MAP_CHIP[DY][PX] == GOAL) && DCMD == 1) return DOWN;
	}
	else {
		int TO = scene->GetPlayer()->NextToPlayer();
		switch (TO) {
		case RIGHT: {		//ブロックの右に自機//(return:左)
			if ((MAP_CHIP[PY][LX] == FLOOR || MAP_CHIP[PY][LX] == GOAL || MAP_CHIP[PY][LX] == OVER) && LCMD == 1)return LEFT;
			break;
		}
		case LEFT: {		//ブロックの左に自機//(return:右)
			if ((MAP_CHIP[PY][RX] == FLOOR || MAP_CHIP[PY][RX] == GOAL || MAP_CHIP[PY][RX] == OVER) && RCMD == 1)return RIGHT;
			break;
		}
		case DOWN: {		//ブロックの下に自機//(return:上)
			if ((MAP_CHIP[UY][PX] == FLOOR || MAP_CHIP[UY][PX] == GOAL || MAP_CHIP[UY][PX] == OVER) && UCMD == 1)return UP;
			break;
		}
		case UP: {			//ブロックの上に自機//(return:下)
			if ((MAP_CHIP[DY][PX] == FLOOR || MAP_CHIP[DY][PX] == GOAL || MAP_CHIP[DY][PX] == OVER) && DCMD == 1)return DOWN;
			break;
		}
		}
	}
	return 0;
}
//プレイヤーが左にいる&右が押された→右に動く
void MapChip::BlockMove(int PX, int PY, int Arrow) {
	int LX = PX - 1, RX = PX + 1, UY = PY - 1, DY = PY + 1;
	/*普通移動*/ {
		if (MAP_CHIP[PY][LX] == FLOOR && Arrow == LEFT) {
			MAP_CHIP[PY][LX] = BLOCK;
			if (MAP_CHIP[PY][PX] != OVER) MAP_CHIP[PY][PX] = FLOOR;
			else MAP_CHIP[PY][PX] = GOAL;
		}
		if (MAP_CHIP[PY][RX] == FLOOR && Arrow == RIGHT) {
			MAP_CHIP[PY][RX] = BLOCK;
			if (MAP_CHIP[PY][PX] != OVER)MAP_CHIP[PY][PX] = FLOOR;
			else MAP_CHIP[PY][PX] = GOAL;
		}
		if (MAP_CHIP[UY][PX] == FLOOR && Arrow == UP) {
			MAP_CHIP[UY][PX] = BLOCK;
			if (MAP_CHIP[PY][PX] != OVER)MAP_CHIP[PY][PX] = FLOOR;
			else MAP_CHIP[PY][PX] = GOAL;
		}
		if (MAP_CHIP[DY][PX] == FLOOR && Arrow == DOWN) {
			MAP_CHIP[DY][PX] = BLOCK;
			if (MAP_CHIP[PY][PX] != OVER)MAP_CHIP[PY][PX] = FLOOR;
			else MAP_CHIP[PY][PX] = GOAL;
		}
	}
	/*ゴール移動*/ {
		if (MAP_CHIP[PY][LX] == GOAL && Arrow == LEFT) {
			MAP_CHIP[PY][LX] = OVER;
			MAP_CHIP[PY][PX] = FLOOR;
		}
		if (MAP_CHIP[PY][RX] == GOAL && Arrow == RIGHT) {
			MAP_CHIP[PY][RX] = OVER;
			MAP_CHIP[PY][PX] = FLOOR;
		}
		if (MAP_CHIP[UY][PX] == GOAL && Arrow == UP) {
			MAP_CHIP[UY][PX] = OVER;
			MAP_CHIP[PY][PX] = FLOOR;
		}
		if (MAP_CHIP[DY][PX] == GOAL && Arrow == DOWN) {
			MAP_CHIP[DY][PX] = OVER;
			MAP_CHIP[PY][PX] = FLOOR;
		}
	}
}
bool MapChip::CheckRange(int PX, int PY) {
	return PX > 0 && PX < MAPX - 1 && PY > 0 && PY < MAPY - 1;
}
int MapChip::NextToBlock(int PX, int PY) {
	if (MAP_CHIP[PY - 1][PX] == BLOCK ||
		MAP_CHIP[PY - 1][PX] == OVER) return UP;		//自機の上にブロック
	if (MAP_CHIP[PY + 1][PX] == BLOCK ||
		MAP_CHIP[PY + 1][PX] == OVER) return DOWN;		//自機の下にブロック
	if (MAP_CHIP[PY][PX - 1] == BLOCK ||
		MAP_CHIP[PY][PX - 1] == OVER) return LEFT;		//自機の左にブロック
	if (MAP_CHIP[PY][PX + 1] == BLOCK ||
		MAP_CHIP[PY][PX + 1] == OVER) return RIGHT;	//自機の右にブロック
	return 0;
}
void MapChip::Draw() {
	int AirColor = GetColor(222, 222, 222), WallColor = GetColor(222, 0, 0),
		YellowColor = GetColor(222, 222, 0), Black = GetColor(0, 0, 0),
		PinkColor = GetColor(222, 0, 222), SCMD = CheckHitKey(KEY_INPUT_S);
	for (int X = 0; X < MAPX; X++) {
		for (int Y = 0; Y < MAPY; Y++) {
			int LX = X * CHIP_SIZE, RX = (X + 1) * CHIP_SIZE,
				UY = Y * CHIP_SIZE, DY = (Y + 1) * CHIP_SIZE;
			switch (MAP_CHIP[Y][X]) {
			case NUL: {
				DrawBox(LX, UY, RX, DY, AirColor, false);
				DrawFormatString(LX, UY, AirColor, "X:%d", X);
				DrawFormatString(LX, UY + 15, AirColor, "Y:%d", Y);
				break;
			}
			case WALL: {
				DrawBox(LX, UY, RX, DY, WallColor, true);
				DrawFormatString(LX, UY, AirColor, "X:%d", X);
				DrawFormatString(LX, UY + 15, AirColor, "Y:%d", Y);
				break;
			}
			case FLOOR: {
				DrawBox(LX, UY, RX, DY, AirColor, true);
				DrawFormatString(LX, UY, Black, "X:%d", X);
				DrawFormatString(LX, UY + 15, Black, "Y:%d", Y);
				break;
			}
			case GOAL: {
				DrawBox(LX, UY, RX, DY, YellowColor, true);
				DrawFormatString(LX, UY, Black, "X:%d", X);
				DrawFormatString(LX, UY + 15, Black, "Y:%d", Y);
				break;
			}
			case OVER: {
				DrawBox(LX, UY, RX, DY, PinkColor, true);
				DrawFormatString(LX, UY, AirColor, "X:%d", X);
				DrawFormatString(LX, UY + 15, AirColor, "Y:%d", Y);
				break;
			}
			}
		}
	}
}
void MapChip::DrawChip(int BX, int BY, bool Mode) {
	int LX = BX * CHIP_SIZE, UY = BY * CHIP_SIZE,
		RX = (BX + 1) * CHIP_SIZE, DY = (BY + 1) * CHIP_SIZE;
	if (Mode) DrawBox(LX, UY, RX, DY, GetColor(0, 0, 222), true);
	if (!Mode) DrawBox(LX, UY, RX, DY, GetColor(0, 222, 0), true);
	int Black = GetColor(0, 0, 0);
	DrawFormatString(LX, UY, Black, "X:%d", BX);
	DrawFormatString(LX, UY + 15, Black, "Y:%d", BY);
}
