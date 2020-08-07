#include "App.h"
#include "PlayScene.h"
#include "DxLib.h"
#include "config.h"
PlayScene* Scene = nullptr;
void AppFirst() {
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	SetOutApplicationLogValidFlag(FALSE); // ���O���o���Ȃ�
	SetDrawScreen(DX_SCREEN_BACK);
	SetMainWindowText(WINDOW_NAME);
	SetWindowSizeExtendRate(WINDOW_EXTEND);
	ChangeWindowMode(WINDOW_MODE); // Window���[�h�̏ꍇ
}
void AppInit() {
	SetDrawScreen(DX_SCREEN_BACK);	//����ʂ�`��Ώۂ�
	SetAlwaysRunFlag(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	Scene = new PlayScene;
}
void AppUpdate() {
	Scene->Update();
}
void AppDraw() {
	ClearDrawScreen();
	Scene->Draw();
	ScreenFlip();
}
void AppRelease() {
	delete Scene;
}