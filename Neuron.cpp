#include "Neuron.h"

float Neuron::stimulus()
{
	return pos.x;
}

void Neuron::response()
{
	//dead function
}

void Neuron::draw()
{
	DrawCircle(pos.x, pos.y, size, ColorFromHSV(240, 1, stimulus() / GetScreenWidth()));
}
