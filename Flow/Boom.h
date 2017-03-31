#pragma once
#include <SFML\Graphics.hpp>
#include "Particle.h"
#include <vector>


using namespace sf;

class Boom
{
public:
	CircleShape point;
	std::vector<Particle> particles;
	Boom(float, float);
	~Boom();

	void setup(float);
	void show(RenderWindow &);
	void setPosition(Vector2f);
	void setColor(Color);
	void apply(float, float);
protected:
	int ramt;
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;

};

