#pragma once
static const char* WINDOW_NAME = "プロジェクト";
static const float WINDOW_EXTEND = 1.0f; 
static const int WSX = 960;			//ウィンドウ横サイズ
static const int WSY = 720;			//ウィンドウ縦サイズ
static const int WXC = WSX / 2;		//ウィンドウ縦中央
static const int WYC = WSY / 2;		//ウィンドウ横中央
//ゲームモード
enum Mode {

};
//DxLib_Initの前にやる設定
void PreInit();
void AfterInit();