#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <Windows.h>
#include <time.h>
#include "Particle.h"
#include "Boom.h"


using namespace sf;




float Umap(float value, float istart, float istop, float ostart, float ostop) {

	return ostart + (ostop - ostart)*((value - istart) / (istop - istart));

}


int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	srand(time(NULL));
	int width = 1500;
	int height = 900;

	sf::RenderWindow window(sf::VideoMode(width, height), "Flow");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(sf::Color(51, 51, 51));

	Boom bom(width / 2, height / 2);

	Vector2f mousePositionFloat;


	float xam = 0;
	float yam = 0;

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


			mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

			xam = rand() % 199 + 1; xam = Umap(xam, 1, 199, -0.045, 0.045);
			yam = rand() % 199 + 1; yam = Umap(yam, 1, 199, -0.045, 0.045);
			
			
			bom.setPosition(mousePositionFloat);
			bom.setup(xam*3);
			bom.apply(xam, yam);
			bom.show(window);


			window.display();
		}

	return 0;
}