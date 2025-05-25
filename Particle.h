#pragma once
#include "raylib.h"
#include <iostream>

class Particle
{
public:
	float posX{};
	float posY{};
	float velX{};
	float velY{};

	bool destroyed{ false };

	float size{10};

	Particle(float posx, float posy, float velx, float vely) : posX(posx), posY(posy), velX(velx), velY(vely) {};

	virtual void draw();
	void collide(Particle& other);
	virtual void onCollide(Particle& other) { };
	virtual void update();
	void destroy();

};

