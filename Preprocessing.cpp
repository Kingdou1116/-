#include "Preprocessing.h"
#include "DxLib.h"
void PreInit() {
	SetGraphMode(WSX, WSY, 32);		//�E�B���h�E�T�C�Y��ݒ肷��
	SetOutApplicationLogValidFlag(FALSE);	//���O�͏o���Ȃ�
	SetDrawScreen(DX_SCREEN_BACK);	//����ʂ�`��Ώۂ�
	SetMainWindowText(WINDOW_NAME);
	SetWindowSizeExtendRate(WINDOW_EXTEND);
	ChangeWindowMode(TRUE);			//�E�B���h�E���[�h�ɂ���
}
void AfterInit() {
	SetAlwaysRunFlag(TRUE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
}
