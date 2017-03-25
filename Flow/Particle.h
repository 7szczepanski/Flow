#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Particle
{
public:
	CircleShape dot;
	
	Particle();
	~Particle();

	void show(RenderWindow &);
	void setVelocity(float, float);
	void setPosition(float, float);
	void update();
	void applyForce(Vector2f);
	Vector2f getVelocity();
protected:
	int lifespan;
	Vector2f velocity;
	Vector2f acceleration;
	Vector2f position;
};

