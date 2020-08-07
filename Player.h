#pragma once
class PlayScene;
class MapChip;
class Player
{
public:
	Player(PlayScene* _scene, MapChip* _scene2);
	~Player();
	void Update(), Draw();
	int NextToPlayer();
private:
	int hImage;	//‰æ‘œ
	int X, Y;	//À•W
	PlayScene* scene;
	MapChip* scene2;
};
