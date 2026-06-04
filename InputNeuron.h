#pragma once

#include "Neuron.h"

class InputNeuron : public Neuron {
public:

	InputNeuron(float posx, float posy, float velx, float vely) : Neuron(posx, posy, velx, vely) {}

	float stimulus() override;
	void draw() override;
};