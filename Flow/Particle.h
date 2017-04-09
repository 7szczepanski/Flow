#pragma once
#include <SFML\Graphics.hpp>

class Particle
{
public:
	sf::CircleShape dot;
	
	Particle(float);
	~Particle();

	void show(sf::RenderWindow &);
	void setVelocity(float, float);
	void setPosition(float, float);
	void update();
	void applyForce(sf::Vector2f);
	sf::Vector2f getVelocity();
	bool isDead();
	sf::Color setColor(int, float, float);
protected:
	int lifespan;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f position;
};

