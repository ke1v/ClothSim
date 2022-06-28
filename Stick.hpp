#pragma once
#include "Point.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Stick {
private:
	Point* m_Point1;
	Point* m_Point2;

	float m_Length;

public:
	Stick(Point* point1, Point* point2, float length);

	bool hasPoint(const Point& p) const;
	void constrainPoints();

	bool operator==(const Stick s) const;

	void draw(sf::RenderWindow& rwindow) const;

};