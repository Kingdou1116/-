#include "Random.h"
#include <time.h>
#include <stdlib.h>
void ResetNum() {
	srand((unsigned int)time(NULL));
}
int Random(int max, int min) {
	if (max < min) {
		int X = max;
		max = min;
		min = X;
	}
	max++;
	int range = max - min;
	return rand() % range + min;
}
