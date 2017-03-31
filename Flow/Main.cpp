#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <Windows.h>
#include <time.h>
#include "Particle.h"
#include "Boom.h"


using namespace sf;



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
	int width = 1080;
	int height = 720;

	sf::RenderWindow window(sf::VideoMode(width, height), "Flow");
	sf::RectangleShape background(Vector2f(width, height));
	background.setFillColor(sf::Color(51, 51, 51));
	std::vector<Boom> bums;
	for (int i = 0; i < 5; i++) {
		Boom bom(width / 2, height / 2);
		bums.push_back(bom);
	}
	

	Vector2f mousePositionFloat;


	float xam = 0;
	float yam = 0;

	float xamb = 0;
	float yamb = 0;

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
			for (int i = bums.size() - 1; i >= 0; i--) {
				xam = unirand(-0.065, 0.065);//rand() % 199 + 1; xam = Umap(xam, 1, 199, -0.045, 0.045);
				yam = unirand(-0.065, 0.065);//yam = rand() % 199 + 1; yam = Umap(yam, 1, 199, -0.045, 0.045);


				bums[i].setPosition(mousePositionFloat);
				bums[i].setup(xam);
				bums[i].apply(xam, yam);
				bums[i].show(window);
			}
	


			window.display();
		}

	return 0;
}