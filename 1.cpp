#include "DxLib.h"
#include "Preprocessing.h"
#include "Init.h"
#include "Update.h"
#include "Draw.h"
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	PreInit();
	if (DxLib_Init() == -1) {	// �c�w���C�u��������������
		return -1;			// �G���[���N�����璼���ɏI��
	}
	AppInit();
	//���C������
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		AppUpdate();
		AppDraw();
	}
	DxLib_End();			// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}