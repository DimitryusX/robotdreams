#include <iostream>
#include "Vector2d.h"

Vector2d::Vector2d() : m_x(0.0f), m_y(0.0f) 
{
	count++;
};

Vector2d::Vector2d(float x, float y) : m_x(x), m_y(y) 
{
	count++;
};

void Vector2d::setX(float x)
{
	m_x = x;
};

void Vector2d::setY(float y)
{
	m_y = y;
};

float Vector2d::getX() 
{
	return m_x;
};

float Vector2d::getY() 
{
	return m_y;
};

void Vector2d::add(const Vector2d& other) 
{
	m_x += other.m_x;
	m_y += other.m_y;
}

float Vector2d::length() 
{
	return sqrt(m_x * m_x + m_y * m_y);
}

float Vector2d::operator()() {
	return length();
}

void Vector2d::print()
{
	std::cout << "{" << m_x << ", " << m_y << "}" << std::endl;
}

Vector2d& Vector2d::operator=(const Vector2d& other) 
{
	if (this != &other) {
		m_x = other.m_x;
		m_y = other.m_y;
	}

	return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) 
{
	return Vector2d(m_x + secondVector.m_x, m_y + secondVector.m_y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) 
{
	return Vector2d(m_x - secondVector.m_x, m_y - secondVector.m_y);
}

float& Vector2d::operator[](const unsigned i) 
{
	if (i > 1) {
		throw std::out_of_range("Index out of bounds in Vector2d::operator[]");
	}

	if (i == 0) return m_x;
	
	if (i == 1) return m_y;

	return m_x;
}

std::istream& operator>>(std::istream& input, Vector2d& v)
{
	input >> v.m_x >> v.m_y;
	return input;
}

std::ostream& operator<<(std::ostream& os, Vector2d& v)
{
	os << "{" << v.m_x << ", " << v.m_y << "}" << std::endl;
	return os;
}

Vector2d::~Vector2d() 
{
	count--;
}

int Vector2d::getCount()
{
	return count;
}
