#pragma once
#include "Particle.h"

class EatingParticle : public Particle
{
public:
	EatingParticle(float posx, float posy, float velx, float vely) : Particle{posx, posy, velx, vely} {};

	void draw() override;
	void onCollide(Particle& other) override;

};

