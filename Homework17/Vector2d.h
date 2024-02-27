#pragma once
#include <cmath>

class Vector2d {
public:
	Vector2d();
	Vector2d(float x, float y);

	float getX();
	float getY();

	void setX(float x);
	void setY(float y);

	void add(const Vector2d& other);

	float length();

	void print();

	Vector2d& operator=(const Vector2d& other);

	Vector2d operator+(const Vector2d& secondVector);
	Vector2d operator-(const Vector2d& secondVector);

	float operator()();

	float& operator[](const unsigned i);

	// friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
	// friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

	friend std::istream& operator>>(std::istream& input, Vector2d& v);
	friend std::ostream& operator<<(std::ostream& output, Vector2d& v);

	~Vector2d();

	static int getCount();
private:
	float m_x;
	float m_y;

	static int count;
};

/*
Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.m_x + rightVector.m_x, leftVector.m_y + rightVector.m_y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.m_x - rightVector.m_x, leftVector.m_y - rightVector.m_y);
}
*/
