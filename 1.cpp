#include "DxLib.h"
#include "App.h"
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	AppFirst();
	if (DxLib_Init() == -1) {		// ＤＸライブラリ初期化処理
		return -1;			// エラーが起きたら直ちに終了
	}
	AppInit();
	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		AppUpdate();
		AppDraw();
	}
	AppRelease();
	DxLib_End();			// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
