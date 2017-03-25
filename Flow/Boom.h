#pragma once
#include <SFML\Graphics.hpp>
#include "Particle.h"
#include <vector>
#include <random>

using namespace std;
using namespace sf;

class Boom
{
public:
	CircleShape point;
	vector<Particle> particles;
	Boom(float, float);
	~Boom();

	void setup();
	void show(RenderWindow &);
	void check(vector<Particle> &);
protected:
	int ramt;
	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;

};

