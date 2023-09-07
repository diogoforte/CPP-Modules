#include "../inc/Point.hpp"
#include <iostream>

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);

int main() {
  Point a(0.0f, 0.0f);
  Point b(2.0f, 0.0f);
  Point c(0.0f, 2.0f);

  Point Point1(1.0f, 1.0f);
  Point Point2(1.0f, -1.0f);

  std::cout << "Point(1.0, 1.0) is ";
  if (!bsp(a, b, c, Point1))
    std::cout << "not ";
  std::cout << "inside the triangle." << std::endl;
  std::cout << "Point(1.0, -1.0) is ";
  if (!bsp(a, b, c, Point2))
    std::cout << "not ";
  std::cout << "inside the triangle." << std::endl;
}