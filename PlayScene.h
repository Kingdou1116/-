#pragma once
class Player;
class MapChip;
class PushBlock;
class PlayScene
{
public:
	PlayScene();
	~PlayScene();
	void Update(), Draw();
	Player* GetPlayer() { return player; }
	MapChip* GetMapChip() { return mapchip; }
	PushBlock* GetPushBlock() { return pushblock; }
private:
	Player* player;
	MapChip* mapchip;
	PushBlock* pushblock;
};
