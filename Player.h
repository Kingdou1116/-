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
	int hImage;	//�摜
	int X, Y;	//���W
	PlayScene* scene;
	MapChip* scene2;
};
