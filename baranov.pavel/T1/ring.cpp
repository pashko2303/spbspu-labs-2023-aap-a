#include "ring.hpp"
#include <stdexcept>

baranov::Ring::Ring(const point_t & center, const double outRadius, const double inRadius):
  center_(center),
  outRadius_(outRadius),
  inRadius_(inRadius)
{
  if (outRadius < 0 || inRadius < 0)
  {
    throw std::invalid_argument("Invalid ring parameters");
  }
}

double baranov::Ring::getArea() const
{
  return 3.14 * (outRadius_ * outRadius_ - inRadius_ * inRadius_);
}

baranov::rectangle_t baranov::Ring::getFrameRect() const
{
  double height = outRadius_ * 2;
  double width = outRadius_ * 2;
  point_t pos = center_;
  return { width, height, pos };
}

void baranov::Ring::move(const point_t & destPos)
{
  center_ = destPos;
}

void baranov::Ring::move(const double dx, const double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void baranov::Ring::scale(const double ratio)
{
  if (scale < 0)
  {
    throw std::invalid_argument("Invalid scale ratio");
  }
  outRadius_ *= ratio;
  inRadius_ *= ratio;
}

