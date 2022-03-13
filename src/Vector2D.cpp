#include "Vector2D.hpp"

Vector2D::Vector2D() { x = y = 0.0f; }

Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2D& Vector2D::add(const Vector2D& vector) {
	this->x += vector.x;
	this->y += vector.y;
	return *this;
}
Vector2D& Vector2D::subtract(const Vector2D& vector) {
	this->x -= vector.x;
	this->y -= vector.y;
	return *this;
}
Vector2D& Vector2D::multiply(const Vector2D& vector) {
	this->x *= vector.x;
	this->y *= vector.y;
	return *this;
}
Vector2D& Vector2D::divide(const Vector2D& vector) {
	this->x /= vector.x;
	this->y /= vector.y;
	return *this;
}

Vector2D& operator+(Vector2D& vector1, const Vector2D& vector2) {
	return vector1.add(vector2);
}
Vector2D& operator-(Vector2D& vector1, const Vector2D& vector2) {
	return vector1.subtract(vector2);
}
Vector2D& operator*(Vector2D& vector1, const Vector2D& vector2) {
	return vector1.multiply(vector2);
}
Vector2D& operator/(Vector2D& vector1, const Vector2D& vector2) {
	return vector1.divide(vector2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vector) {
	return this->add(vector);
}
Vector2D& Vector2D::operator-=(const Vector2D& vector) {
	return this->subtract(vector);
}
Vector2D& Vector2D::operator*=(const Vector2D& vector) {
	return this->multiply(vector);
}
Vector2D& Vector2D::operator/=(const Vector2D& vector) {
	return this->divide(vector);
}	

std::ostream& Vector2D::operator << (std::ostream& stream, const Vector2D& vector) {
	stream << "(" << vector.x << "," << vector.y << ")"; 
	return stream;
}