#include "Boom.h"



double unirandi(float start, float end) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(start, end);
	return dist(mt);
}

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
	float rad = unirandi(1, 3);
	ramt = unirandi(1,4);
	for (int i = 0; i < ramt; i++) {
		Particle dot(rad);
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

