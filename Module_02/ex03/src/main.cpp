#include "../inc/Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
  Point a(0.0f, 0.0f);
  Point b(1.0f, 0.0f);
  Point c(0.5f, 1.0f);

  Point testPoint1(0.5f, 0.5f);
  Point testPoint2(0.5f, -0.5f);

  std::cout << "Point(0.5, 0.5) is ";
  if (!bsp(a, b, c, testPoint1)) {
    std::cout << "not ";
  }
  std::cout << "inside the triangle." << std::endl;

  std::cout << "Point(0.5, -0.5) is ";
  if (!bsp(a, b, c, testPoint2)) {
    std::cout << "not ";
  }
  std::cout << "inside the triangle." << std::endl;

  return 0;
}