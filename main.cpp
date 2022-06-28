#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

#include "Point.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Stick.hpp"

const int WINDOW_SIZE = 1000;

int main(int, char**) {
	sf::RenderWindow rwindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Verlet Cloth Simulator");
	sf::Clock clock;
	Point point1(sf::Vector2f(200.f, 200.f));
	point1.changeState(Point::State::Pinned);
	Point point2(sf::Vector2f(100.f, 200.f));
	// point2.changeState(Point::State::Pinned);
	Point point3(sf::Vector2f(150.f, 250.f));

	Stick stick1(point1, point3, 100.f);
	Stick stick2(point2, point3, 100.f);

	bool start = false;

	while (rwindow.isOpen() && clock.getElapsedTime().asSeconds() < 0.01667f) {
		// 60 tps lock
		sf::Time delta = clock.restart();

		sf::Event event;
		while (rwindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rwindow.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::V) {
					point1.DisplaySpeed();
				}
				if (event.key.code == sf::Keyboard::U) {
					start = true;
				}
				if (event.key.code == sf::Keyboard::D) {
					stick1.Debug();
				}
			}
		}

		rwindow.clear();

		if (start) {
			point1.update(delta.asSeconds(), {0.f, 100.f});
			point2.update(delta.asSeconds(), {0.f, 100.f});
			point3.update(delta.asSeconds(), {0.f, 100.f});

			stick1.constrainPoints();
			stick2.constrainPoints();
		}

		// std::cout << "(" << point1.getPosition().x << ", " << point1.getPosition().y << ")" << std::endl;
		point1.draw(rwindow);
		point2.draw(rwindow);
		point3.draw(rwindow);
		stick1.draw(rwindow);
		stick2.draw(rwindow);
		rwindow.display();
	}

	return 0;
}
