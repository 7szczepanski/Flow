#include "Particle.h"



Particle::Particle()
{
	dot.setFillColor(setColor(1,lifespan,1));
	dot.setRadius(6);
	lifespan = 255;
}


Particle::~Particle()
{
}

void Particle::update() {
	velocity += acceleration;
	position += velocity;
	dot.setPosition(position);

	acceleration = acceleration *0.f;
	lifespan -= 1;
}

void Particle::show(RenderWindow &target_) {
	target_.draw(dot);
}

void Particle::setPosition(float x, float y) {
	position.x = x;
	position.y = y;

	dot.setPosition(position);
}

void Particle::setVelocity(float x, float y) {
	velocity.x = x;
	velocity.y = y;
}

void Particle::applyForce(Vector2f force) {
	acceleration += force;
}

Vector2f Particle::getVelocity() {
	return velocity;
}

bool Particle::isDead() {

	if (lifespan < 0) {
		return true;
	}
	else {
		return false;
	}

}

Color Particle::setColor(int hue, float sat, float val) {

	hue %= 360;
	while (hue < 0) hue += 360;

	if (sat < 0.f) sat = 0.f;
	if (sat > 1.f) sat = 1.f;

	if (val < 0.f) val = 0.f;
	if (val > 1.f) val = 1.f;

	int h = hue / 60;
	float f = float(hue) / 60 - h;
	float p = val*(1.f - sat);
	float q = val*(1.f - sat*f);
	float t = val*(1.f - sat*(1 - f));

	switch (h)
	{
	default:
	case 0:
	case 6: return sf::Color(val * 255, t * 255, p * 255);
	case 1: return sf::Color(q * 255, val * 255, p * 255);
	case 2: return sf::Color(p * 255, val * 255, t * 255);
	case 3: return sf::Color(p * 255, q * 255, val * 255);
	case 4: return sf::Color(t * 255, p * 255, val * 255);
	case 5: return sf::Color(val * 255, p * 255, q * 255);
	}
}
