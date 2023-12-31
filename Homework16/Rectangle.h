#pragma once

class Rectangle {
private:
    float m_length;
    float m_height;

public:
    Rectangle();
    Rectangle(float initialLength, float initialHeight);

    float getArea();
    float getPerimeter();
};