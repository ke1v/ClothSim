#include "Stick.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include <cmath>
#include <iostream>

Stick::Stick(Point& point1, Point& point2, float length)
    : m_Point1(point1), m_Point2(point2), m_Length(length) {
}

void Stick::constrainPoints() {
    if (m_Point1.getState() == Point::State::Pinned && m_Point2.getState() == Point::State::Pinned) return;

    float dy = m_Point2.getPosition().y-m_Point1.getPosition().y;
    float dx = m_Point2.getPosition().x-m_Point1.getPosition().x;
    float dist = sqrt(dy * dy + dx * dx);
    float diff = m_Length - dist;
    float ratio = diff / dist;
    sf::Vector2f offset = {dx * ratio, dy * ratio};
    
    if (m_Point1.getState() == Point::State::Pinned) {
        m_Point2.offest(offset);
    } else if (m_Point2.getState() == Point::State::Pinned) {
        m_Point1.offest(-offset);
    } else {
        offset /= 2.f;
        m_Point2.offest(offset);
        m_Point1.offest(-offset);
    }
}

void Stick::Debug() {
    float dy = m_Point2.getPosition().y-m_Point1.getPosition().y;
    float dx = m_Point2.getPosition().x-m_Point1.getPosition().x;
    float dist = sqrt(dy * dy + dx * dx);
    float diff = m_Length - dist;
    float ratio = diff / dist / 2;
    sf::Vector2f offset = {dx * ratio, dy * ratio};
    std::cout << offset.x << ", " << offset.y << std::endl;
}

void Stick::draw(sf::RenderWindow &rwindow) const {
    sf::Vertex va[2] = {
        m_Point1.getPosition(),
        m_Point2.getPosition(),
    };
    
    rwindow.draw(va, 2, sf::Lines);
}