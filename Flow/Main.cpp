#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <Windows.h>
#include <time.h>
#include "Particle.h"
#include "Boom.h"

double unirand(float start, float end) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(start, end);
	return dist(mt);
}

float Umap(float value, float istart, float istop, float ostart, float ostop) {

	return ostart + (ostop - ostart)*((value - istart) / (istop - istart));

}


int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	srand(time(NULL));
	constexpr int width{ 1280 };
	constexpr int height{ 720 };

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(width, height), "Flow",sf::Style::Default,settings);
	sf::RectangleShape background(sf::Vector2f(width, height));
	background.setFillColor(sf::Color(51, 51, 51));
	std::vector<Boom> cluster;
	for (int i = 0; i < 7; i++) {
		Boom particle(width / 2, height / 2);
		cluster.push_back(particle);
	}
	
	sf::Vector2f mousePositionFloat;

	float xam{ 0 }, yam{ 0 }, offset{ 0 };

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
			for (int i = cluster.size() - 1; i >= 0; i--) {
				xam = unirand(-0.065, 0.065);
				yam = unirand(-0.065, 0.065);
				offset = unirand(-0.195, 0.195);

				cluster[i].setPosition(mousePositionFloat);
				cluster[i].setup(offset);
				cluster[i].apply(xam, yam);
				cluster[i].show(window);
			}
			window.display();
		}

	return 0;
}