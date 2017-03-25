#include "Boom.h"




Boom::Boom(float x_, float y_)
{
	position.x = x_;
	position.y = y_;
}


Boom::~Boom()
{
}
void Boom::setup(float off) {

	point.setPosition(position);
	point.setFillColor(Color::Magenta);
	point.setRadius(3);
	
	ramt = rand() % 7 + 1;
	for (int i = 0; i < ramt; i++) {
		Particle dot;
		dot.setPosition(this->position.x+off,this->position.y);
		particles.push_back(dot);
	}


}
void Boom::show(RenderWindow &target_) {
	target_.draw(point);
	for (int i = 0; i < particles.size(); i++) {
	
		particles[i].update();
		target_.draw(particles[i].dot);

		if (particles[i].isDead()) {
			particles.erase(particles.begin()+i);
		}
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

void Boom::apply(float randx,float randy){
	for (int i = 0; i < particles.size(); i++) {
		Vector2f acc;
		acc.x = randx;
		acc.y = randy;
		particles[i].applyForce(acc);
	}
}