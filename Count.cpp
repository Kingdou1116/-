#include "Count.h"
//���E���E�b��60����
static const int Second = 60, Minute = 60, Hour = 60;
//�b���J�E���g
static int cnt = 0;
void Count() {
	cnt++;
	if (cnt >= Second * Minute * Hour) cnt = 0;	//1���Ԃ������烊�Z�b�g
}
bool Interval(int Number) {
	return cnt % Number == 0;
}
