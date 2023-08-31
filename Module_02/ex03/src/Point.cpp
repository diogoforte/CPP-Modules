#include "../inc/Point.hpp"

Point::Point() : x(0.0f), y(0.0f) {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
  (void)other;
  return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }