#include "Particle.h"
#include <cmath>

#define VELOCITY

void Particle::draw()
{
	DrawCircle(pos.x, pos.y, size, WHITE);
	
#ifdef VELOCITY
	DrawLine(pos.x, pos.y, pos.x + vel.x, pos.y + vel.y, RED);
#endif // VELOCITY

#ifdef ACCELERATION
	DrawLine(pos.x + vel.x, pos.y + vel.y, pos.x + vel.x + acc.x, pos.y + vel.y + acc.y, ORANGE);
#endif // ACCELERATION


}

void Particle::collide(Particle& other)
{
	if (other.destroyed == true) return;

	Vector2 impact = other.pos - pos;

	float d = Vector2Length(impact);

	if (d < (size + other.size)) {

		float overlap = d - (size + other.size);

		// Push the particles out so that they are not overlapping
		Vector2 dir = impact;
		dir = Vector2Normalize(dir) * 0.5f;
		pos -= dir;
		other.pos += dir;

		//// Correct the distance!
		d = size + other.size;
		impact = Vector2Normalize(impact) * d;

		//since all particles are mass of 1 for the time being just make arbitrary value

		float mass = 2;

		Vector2 diff = other.vel - vel;

		//// Particle A (this)
		float numerator = Vector2DotProduct(diff, impact);
		float denominator = mass * d * d;
		Vector2 deltaA = impact;
		//1 is the mass of this particle
		deltaA *= 2 * 1 * (numerator / denominator);
		vel += deltaA;

		//// Particle B (other)
		Vector2 deltaB = impact;
		deltaB *= -2 * 1 * (numerator / denominator);
		other.vel += deltaB;

		onCollide(other);
	}

}

void Particle::update(float delta)
{

	//add some form of friction
	Vector2 force = (Vector2Normalize(vel) * Vector2LengthSqr(vel) / 2) * -0.05f;

	acc += force;

	vel += acc * delta * 0.5f;

	pos += vel * delta;

	//kill acceleration
	acc = acc * 0;

	if (pos.y + size > 450) {
		pos.y = 450 - size;
		vel.y *= -1;
	}

	if (pos.x + size > 800) {
		pos.x = 800 - size;
		vel.x *= -1;
	}

	if (pos.y - size < 0) {
		pos.y = size;
		vel.y *= -1;
	}

	if (pos.x - size < 0) {
		pos.x = size;
		vel.x *= -1;
	}

}

void Particle::destroy() {
	destroyed = true;
}