#include "../inc/Point.hpp"

float area(const Point &a, const Point &b, const Point &c) {
  const Fixed ax = a.getX();
  const Fixed ay = a.getY();
  const Fixed bx = b.getX();
  const Fixed by = b.getY();
  const Fixed cx = c.getX();
  const Fixed cy = c.getY();

  Fixed area = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2.0f;
  if (area < 0) {
    area = area * -1;
  }
  return area.toFloat();
}

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
  if (point.getX() == a.getX() || point.getX() == b.getX() ||
      point.getX() == c.getX() || point.getY() == a.getY() ||
      point.getY() == b.getY() || point.getY() == c.getY()) {
    return false;
  }

  float abc = area(a, b, c);
  float pbc = area(point, b, c);
  float pac = area(point, a, c);
  float pab = area(point, a, b);

  return roundf((abc - (pbc + pac + pab)) * 10000) == 0;
}
