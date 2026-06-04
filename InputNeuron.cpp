#include "InputNeuron.h"

float InputNeuron::stimulus()
{
    return ((pos.x/GetScreenWidth()) * 2) - 1;
}

void InputNeuron::draw()
{
	DrawCircle(pos.x, pos.y, size, ColorFromHSV(240, 1, stimulus() + .5f));
}