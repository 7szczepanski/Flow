#include "Particle.h"



Particle::Particle()
{
	dot.setFillColor(Color::Cyan);
	dot.setRadius(2);
}


Particle::~Particle()
{
}

void Particle::update() {
	velocity += acceleration;
	position += velocity;
	dot.setPosition(position);

	acceleration = acceleration *0.f;
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