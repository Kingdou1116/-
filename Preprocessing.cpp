#include "Preprocessing.h"
#include "DxLib.h"
void PreInit() {
	SetGraphMode(WSX, WSY, 32);		//ウィンドウサイズを設定する
	SetOutApplicationLogValidFlag(FALSE);	//ログは出さない
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	SetMainWindowText(WINDOW_NAME);
	SetWindowSizeExtendRate(WINDOW_EXTEND);
	ChangeWindowMode(TRUE);			//ウィンドウモードにする
}
void AfterInit() {
	SetAlwaysRunFlag(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
}
