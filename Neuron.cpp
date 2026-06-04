#include "Neuron.h"

float Neuron::stimulus()
{
	return bias;
}

void Neuron::input() {
	//
}

void Neuron::response()
{
	//dead function
}

void Neuron::draw()
{
	DrawCircle(pos.x, pos.y, size, RED);
}
