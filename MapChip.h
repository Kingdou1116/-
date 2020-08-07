#pragma once
class PlayScene;
class MapChip
{
public:
	MapChip(PlayScene* _scene);
	~MapChip();
	void Update(), Draw(), DrawChip(int BX, int BY, bool Mode), BlockMove(int X, int Y, int Arrow);
	int CheckMapChip(int Mode, bool XorY), IsFloor(int PX, int PY, bool IsPlayer = true),
		BlockNumber(bool Mode), NextToBlock(int PX, int PY);
	bool CheckRange(int PX, int PY);
private:
	enum MAPS { NUL, WALL, FLOOR, PLAY, BLOCK, GOAL, OVER };
	enum Direction { LEFT = 1, RIGHT, UP, DOWN };
	static const int CHIP_SIZE = 50, MAPX = 10, MAPY = 10;
	PlayScene* scene;
	int MAP_CHIP[MAPY][MAPX] = {
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,1,0,0,0 },
	{ 0,1,2,2,2,2,2,1,0,0 },
	{ 0,1,2,4,2,2,2,1,0,0 },
	{ 0,1,2,2,3,1,2,1,0,0 },
	{ 0,1,2,2,2,1,5,1,0,0 },
	{ 0,1,2,1,1,1,1,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
	};;
	int hImage;	//‰æ‘œ
};
