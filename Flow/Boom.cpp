#include "Boom.h"
#include <iostream>


using namespace std;


Boom::Boom(float x_, float y_)
{
	position.x = x_;
	position.y = y_;
}


Boom::~Boom()
{
}
void Boom::setup() {

	point.setPosition(position);
	point.setFillColor(Color::Magenta);
	point.setRadius(3);
	
	ramt = rand() % 5 + 1;
	for (int i = 0; i < ramt; i++) {
		Particle dot;
		dot.setPosition(this->position.x,this->position.y);
		particles.push_back(dot);
	}


}
void Boom::show(RenderWindow &target_) {
	target_.draw(point);
	for (int i = 0; i < particles.size(); i++) {
		float ax, ay;
		ax = (rand() % 10 + (-10));
		ay = (rand() % 10 + (-10));
		ax = ax* 0.001;
		ay = ay* 0.001;
		Vector2f acc = Vector2f(ax, ay);
		particles[i].applyForce(acc);
		particles[i].update();
		target_.draw(particles[i].dot);
	}
}

void Boom::check(vector<Particle> &particles) {
	if (particles.size() > 5) {
		particles.erase(particles.begin(), particles.begin()+2);
	}
}

void Boom::setPosition(Vector2f vec) {
	position = vec;
}

void Boom::setColor(Color col) {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].dot.setFillColor(col);
	}
}