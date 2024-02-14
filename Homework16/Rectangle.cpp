#include "Rectangle.h"

Rectangle::Rectangle() : m_length(1.0f), m_height(1.0f) {}

Rectangle::Rectangle(float initialLength, float initialHeight)
    : m_length(initialLength), m_height(initialHeight) {}

float Rectangle::getArea() {
    return m_length * m_height;
}

float Rectangle::getPerimeter() {
    return 2.0f * (m_length + m_height);
}