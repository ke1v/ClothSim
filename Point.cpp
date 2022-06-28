#include "Point.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include <cmath>
#include <iostream>

// Functino from https://stackoverflow.com/a/4609795
template <typename T> signed int signof(T val) {
	return (T(0) < val) - (val < T(0));
}

Point::Point(sf::Vector2f position, sf::Vector2f prevPosition) 
	: m_Position(position), m_PrevPosition(prevPosition) {
}

Point::Point(sf::Vector2f position) 
	: m_Position(position), m_PrevPosition(position) {
}

void Point::draw(sf::RenderWindow& rwindow) const {
	sf::CircleShape c(radius);
	c.setFillColor(m_State == State::Pinned ? sf::Color::Red : sf::Color::White);
	c.setOrigin(radius, radius);
	c.setPosition(m_Position);

	rwindow.draw(c);
}

void Point::changeState(State state) {
	m_State = state;
}

bool Point::isPoint(sf::Vector2f location) {
	float dx = location.x - m_Position.x;
	float dy = location.y - m_Position.y;
	return std::sqrt(dx*dx + dy*dy) < radius;
}

Point::State Point::getState() const {
	return m_State;
}

void Point::update(float delta, sf::Vector2f acceleration /*= {0.f, 0.f}*/) {
	if (m_State == State::Pinned) return;
	sf::Vector2f tempPosition = m_Position;
	m_Position = m_Position*2.f - m_PrevPosition + acceleration*delta*delta;
	m_PrevPosition = tempPosition;

	// sf::Vector2f v = m_Position - m_PrevPosition;
	// sf::Vector2f d = {v.x*v.x*-signof(v.x), v.y*v.y*-signof(v.y)};
	// if (drag > 1) drag = 1;
	// d *= drag;
	// v += acceleration;
	// v += d;
	// m_PrevPosition = m_Position;
	// m_Position += v;

	// To avoid overflows
	if (m_Position.x > 10000 || m_Position.y > 10000) {
		// Freezes point
		m_PrevPosition = m_Position;
	}
	

}

void Point::offest(sf::Vector2f offset) {
	m_Position += offset;
}

sf::Vector2f Point::getPosition() const {
	return m_Position;
}