#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

const int WINDOW_SIZE = 1000;

int main(int, char**) {
	sf::RenderWindow rwindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Verlet Cloth Simulator");

	while (rwindow.isOpen()) {
		sf::Event event;
		while (rwindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rwindow.close();
			}
		}

		rwindow.clear();

		

		rwindow.display();
	}

	return 0;
}
