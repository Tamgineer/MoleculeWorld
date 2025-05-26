#include "EatingParticle.h"

void EatingParticle::onCollide(Particle& other) {
	size += other.size;
	other.destroy();
}

void EatingParticle::draw()
{
	DrawCircle(pos.x, pos.y, size, RED);
}