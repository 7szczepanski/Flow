#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <time.h>
#include "Particle.h"
#include "Boom.h"

/*
1. Przesuñ
2. pobierz pozycje
3. Utwórz obiekt boom na pozycji
4. w obiekcie boom dodaj od 1 do 10 nowych obiektów particle
5. particle ma losow¹ velocity oraz kierunek
*/

using namespace sf;

sf::Color hsv(int hue, float sat, float val)
{
	hue %= 360;
	while (hue<0) hue += 360;

	if (sat<0.f) sat = 0.f;
	if (sat>1.f) sat = 1.f;

	if (val<0.f) val = 0.f;
	if (val>1.f) val = 1.f;

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

int main()
{
	srand(time(NULL));
	int width = 1500;
	int height = 900;

	sf::RenderWindow window(sf::VideoMode(width, height), "Flow");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(sf::Color(51, 51, 51));

	Particle dot;
	dot.setPosition(width / 2, height / 2);
	
	Boom bom(width / 2, height / 2);

	Vector2f friction;
	Vector2f mousePositionFloat;

	friction = dot.getVelocity();
	friction = friction *-1.f;
	friction = friction / 1000.f;
	

	

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}


			bom.check(bom.particles);



			window.clear();
			window.draw(background);
			mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
			dot.applyForce(friction);
			dot.update();
			//dot.show(window);
			bom.setPosition(mousePositionFloat);
			bom.setup();
			bom.setColor(hsv(bom.particles.size() % 360, 1, 1));
			bom.show(window);
			window.display();
		}

	return 0;
}