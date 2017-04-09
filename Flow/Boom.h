#pragma once
#include <SFML\Graphics.hpp>
#include "Particle.h"
#include <vector>
#include <random>

class Boom
{
public:
	sf::CircleShape point;
	std::vector<Particle> particles;
	Boom(float, float);
	~Boom();

	void setup(float);
	void show(sf::RenderWindow &);
	void setPosition(sf::Vector2f);
	void setColor(sf::Color);
	void apply(float, float);
protected:
	int ramt;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;

};

