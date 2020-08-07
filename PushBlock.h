#pragma once
class PlayScene;
class MapChip;
class Player;
class PushBlock
{
public:
	PushBlock(PlayScene* _scene, MapChip* _scene2, Player* _scene3);
	~PushBlock();
	void Update(), Draw();
private:
	int hImage;	//�摜
	int X, Y;	//���W
	int Goals, Blocks;
	PlayScene* scene;
	MapChip* scene2;
	Player* scene3;
};
