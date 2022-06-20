#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Point {

	enum State {
		Pinned = 0,
		Free,
	};

	sf::Vector2f m_Position;
	sf::Vector2f m_Velocity;
	sf::Vector2f m_Acceleration;

	Point(sf::Vector2f position, sf::Vector2f velocity = {0.f, 0.f}, sf::Vector2f acceleration = {0.f, 0.f});

	void update();
	void changeState(State state);

	void draw(sf::RenderWindow& rwindow);
};