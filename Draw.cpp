#include "Draw.h"
#include "DxLib.h"
#include "Count.h"
void AppDraw() {
	ClearDrawScreen();	//— ‰æ–Ê‚Ì•`‰æ‚ğ‘S‚ÄÁ‹
	/*¥¥‚±‚±‚Éˆ—‚ğ•`‚­*/ {
		DrawBox(200, 200, 300, 300, GetColor(222, 222, 222), true);
	}/*££*/
	ScreenFlip();		//— ‰æ–Ê‚Æ•\‰æ–Ê‚Ì“ü‘Ö
}
