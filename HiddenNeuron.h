#pragma once

#include "Neuron.h"

class HiddenNeuron : public Neuron {
public:
	HiddenNeuron(float posx, float posy, float velx, float vely) : Neuron(posx, posy, velx, vely) {}

	float stimulus() override;
	void draw() override;
};