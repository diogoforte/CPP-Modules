#include "../inc/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed w1 = ((a.getY() - c.getY()) * (point.getX() - c.getX()) +
              (c.getX() - a.getX()) * (point.getY() - c.getY())) /
             ((a.getY() - c.getY()) * (b.getX() - c.getX()) +
              (c.getX() - a.getX()) * (b.getY() - c.getY()));

  Fixed w2 = ((c.getY() - b.getY()) * (point.getX() - c.getX()) +
              (b.getX() - c.getX()) * (point.getY() - c.getY())) /
             ((a.getY() - c.getY()) * (b.getX() - c.getX()) +
              (c.getX() - a.getX()) * (b.getY() - c.getY()));

  Fixed w3 = Fixed(1.0f) - w1 - w2;

  return (w1 > 0.0f && w2 > 0.0f && w3 > 0.0f);
}