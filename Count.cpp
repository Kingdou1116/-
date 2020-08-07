#include "Count.h"
//時・分・秒を60分割
static const int Second = 60, Minute = 60, Hour = 60;
//秒数カウント
static int cnt = 0;
void Count() {
	cnt++;
	if (cnt >= Second * Minute * Hour) cnt = 0;	//1時間たったらリセット
}
bool Interval(int Number) {
	return cnt % Number == 0;
}
