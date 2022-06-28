#pragma once
#include "Point.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Stick {
private:
	Point& m_Point1;
	Point& m_Point2;

	float m_Length;

public:
	Stick(Point& point1, Point& point2, float length);

	void Debug();
	void constrainPoints();

	void draw(sf::RenderWindow& rwindow) const;

};