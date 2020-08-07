#include "App.h"
#include "PlayScene.h"
#include "DxLib.h"
#include "config.h"
PlayScene* Scene = nullptr;
void AppFirst() {
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	SetOutApplicationLogValidFlag(FALSE); // ログを出さない
	SetDrawScreen(DX_SCREEN_BACK);
	SetMainWindowText(WINDOW_NAME);
	SetWindowSizeExtendRate(WINDOW_EXTEND);
	ChangeWindowMode(WINDOW_MODE); // Windowモードの場合
}
void AppInit() {
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
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