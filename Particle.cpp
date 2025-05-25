#include "Particle.h"
#include <cmath>


void Particle::draw()
{
	DrawCircle(posX, posY, size, WHITE);
}

void Particle::collide(Particle& other)
{
	if (other.destroyed == true) return;

	float distX = posX - other.posX;
	float distY = posY - other.posY;
	float distance = std::sqrt((distX * distX) + (distY * distY));

	if (distance <= size + other.size) {
		
		float midpointx = (posX + other.posX) / 2;
		float midpointy = (posY + other.posY) / 2;

		velX += posX - midpointx;
		velY += posY - midpointy;

		onCollide(other);
	}

}

void Particle::update()
{

	posX += velX * GetFrameTime();
	posY += velY * GetFrameTime();

	if (posY + size > 450) {
		posY = 450 - size;
		velY *= -1;
	}

	if (posX + size > 800) {
		posX = 800 - size;
		velX *= -1;
	}

	if (posY - size < 0) {
		posY = size;
		velY *= -1;
	}

	if (posX - size < 0) {
		posX = size;
		velX *= -1;
	}

}

void Particle::destroy() {
	destroyed = true;
}