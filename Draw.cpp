#include "Draw.h"
#include "DxLib.h"
#include "Count.h"
void AppDraw() {
	ClearDrawScreen();	//����ʂ̕`���S�ď���
	/*���������ɏ�����`��*/ {
		DrawBox(200, 200, 300, 300, GetColor(222, 222, 222), true);
	}/*����*/
	ScreenFlip();		//����ʂƕ\��ʂ̓���
}
