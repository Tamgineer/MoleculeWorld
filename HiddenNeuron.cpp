#include "HiddenNeuron.h"

float HiddenNeuron::stimulus()
{
	return value;
}

void HiddenNeuron::draw() {
	DrawCircle(pos.x, pos.y, size, ColorFromHSV(fmod(stimulus(), 360), 1, 1));
}