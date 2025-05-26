#pragma once

#include "Particle.h"
class Bond
{
public:
	Bond(Particle& a, Particle& b, float length, float k) : a(a), b(b), length(length), k(k) {};

	virtual void draw();
	virtual void update();


private:
	float length;
	float k;

	Particle& a;
	Particle& b;
};

