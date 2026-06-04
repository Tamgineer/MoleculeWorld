#pragma once

#include "Particle.h"

class Neuron : public Particle
{
public:
	Neuron(float posx, float posy, float velx, float vely) : Particle(posx, posy, velx, vely) {}

	virtual float stimulus();
	virtual void input();
	virtual void response();
	void draw() override;

	float bias{ 1.0f };
	float value{};
};