#include "PlayScene.h"
#include "Player.h"
#include "MapChip.h"
#include "PushBlock.h"
#include "Count.h"
#include "DxLib.h"
#include "Keyboard.h"
PlayScene::PlayScene() {
	mapchip = new MapChip(this);
	player = new Player(this, mapchip);
	pushblock = new PushBlock(this, mapchip, player);
}
PlayScene::~PlayScene() {
	if (mapchip != nullptr)delete mapchip;
	if (player != nullptr)delete player;
	if (pushblock != nullptr)delete pushblock;
}
void PlayScene::Update() {
	Count();
	Keyboard_Update();
	mapchip->Update();
	pushblock->Update();
	player->Update();
}
void PlayScene::Draw() {
	pushblock->Draw();
	mapchip->Draw();
	player->Draw();
}
