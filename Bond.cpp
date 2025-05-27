#include "Bond.h"

void Bond::draw() {

	if ((Vector2Distance(a.pos, b.pos) - length) > 0) {
		DrawLine(a.pos.x, a.pos.y, b.pos.x, b.pos.y, PURPLE);
	}
	else {
		DrawLine(a.pos.x, a.pos.y, b.pos.x, b.pos.y, GREEN);
	}

}

void Bond::update() {
	
	Vector2 force = b.pos - a.pos;
	float x = Vector2Length(force) - length;

	force = Vector2Normalize(force);
	force *= k * x;
	a.acc += force * GetFrameTime();
	force *= -1;
	b.acc += force * GetFrameTime();

}