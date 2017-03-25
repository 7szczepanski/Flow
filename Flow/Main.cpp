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



int main()
{
	srand(time(NULL));
	int width = 800;
	int height = 800;

	sf::RenderWindow window(sf::VideoMode(width, height), "Flow");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(sf::Color(51, 51, 51));

	Particle dot;
	dot.setPosition(width / 2, height / 2);
	
	Boom bom(width / 2, height / 2);

	Vector2f friction;
	
	friction = dot.getVelocity();
	friction = friction *-1.f;
	friction = friction / 1000.f;
	

	bom.setup();

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(background);

			dot.applyForce(friction);
			dot.update();
			dot.show(window);

			bom.show(window);
			window.display();
		}

	return 0;
}