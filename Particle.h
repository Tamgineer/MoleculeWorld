#pragma once
#include "raylib.h"
#include "Raymath.h"

#include <iostream>

class Particle
{
public:

	Vector2 pos{};
	Vector2 vel{};
	Vector2 acc{};

	bool destroyed{ false };

	float size{10};

	Particle(float posx, float posy, float velx, float vely) {
		pos.x = posx;
		pos.y = posy;

		vel.x = velx;
		vel.y = vely;
	};

	virtual void draw();
	void collide(Particle& other);
	virtual void onCollide(Particle& other) { };
	virtual void update();
	void destroy();

};

