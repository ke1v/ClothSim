#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <vector>

#include "Point.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Stick.hpp"

const int WINDOW_SIZE = 1000;

int main(int, char**) {
	int width, height, wind, pin;
	std::cin >> width;
	std::cin >> height;
	std::cin >> wind;
	std::cin >> pin;
	int spacing = 800/width;
	sf::RenderWindow rwindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Verlet Cloth Simulator");
	sf::Clock clock;

	std::vector<Point> points;
	std::vector<Stick> sticks;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			// points.push_back(Point({i*100.f+150.f, j*100.f+100.f}, {i*100.f+140.f, j*100.f+90.f}));
			points.push_back(Point({i*spacing+100.f, j*spacing+100.f}));
			if (j == 0 && i % pin == 0) points[i*height+j].changeState(Point::State::Pinned);
		}
	}

	for (int i = 0; i < points.size()-1; i++) {
		if (i % width != width-1) {
			sticks.push_back(Stick(points[i], points[i+1], spacing));
		}
		if (i + width < points.size()) {
			sticks.push_back(Stick(points[i], points[i+width], spacing));
		}
	}

	bool start = false;

	while (rwindow.isOpen()) {
		// 60 tps lock
		if (clock.getElapsedTime().asSeconds() < 0.01667f) continue;
		sf::Time delta = clock.restart();

		std::cout << "FPS: " << 1/delta.asSeconds() << std::endl;

		sf::Event event;
		while (rwindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rwindow.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::U) {
					start = true;
					std::cout << "Start" << std::endl;
				}
				if (event.key.code == sf::Keyboard::D) {
					points.erase(points.begin());
				}
			}
		}

		rwindow.clear();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			
		}

		if (start) {
			for (auto& s : sticks) {
				s.constrainPoints();
			}

			for (auto& p : points) {
				p.update(delta.asSeconds(), {(float)wind, 100.f});
			}

			for (auto& s : sticks) {
				s.constrainPoints();
			}
		}

		for (auto& s : sticks) {
			s.draw(rwindow);
		}
		for (auto& p : points) {
			p.draw(rwindow);
		}

		rwindow.display();
	}

	return 0;
}
