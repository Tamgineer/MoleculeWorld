#include "EatingParticle.h"

void EatingParticle::onCollide(Particle& other) {
	size += other.size;
	other.destroy();
}

void EatingParticle::draw()
{
	DrawCircle(posX, posY, size, RED);
}