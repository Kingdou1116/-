#include "Change.h"
#include "Random.h"
#include "Keyboard.h"
#include "Count.h"
void UpdateNum() {
	ResetNum();
	Keyboard_Update();
	Count();
}