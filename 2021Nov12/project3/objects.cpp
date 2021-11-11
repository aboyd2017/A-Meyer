#include "objects.hpp"

bool SolidObject::collidesWith(const SolidObject * other) const
{
  bool collides = true;

  if (_width == 0 || _height == 0 || other->getWidth() == 0 ||
      other->getHeight() == 0)
  {
    // empty
    collides = false;
  }
  else if (_x_location + _width < other->getX() ||
      other->getX() + other->getWidth() < _x_location)
  {
    collides = false;
  }
  else if (_y_location + _height < other->getY() ||
      other->getY() + other->getHeight() < _y_location)
  {
    collides = false;
  }
  return collides;
}
