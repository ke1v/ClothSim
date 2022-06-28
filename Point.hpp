#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Point {
public:
	enum State {
		Free = 0,
		Pinned,
	};

private:
	sf::Vector2f m_PrevPosition;
	sf::Vector2f m_Position;

	State m_State = Free;

public:
	Point(sf::Vector2f position, sf::Vector2f prevPosition);
	Point(sf::Vector2f position);

	sf::Vector2f getPosition() const;
	State getState() const;
	void offest(sf::Vector2f offset);
	void DisplaySpeed() const;

	void update(float delta, sf::Vector2f acceleration = {0.f, 0.f});
	void changeState(State state);

	void draw(sf::RenderWindow& rwindow) const;
};