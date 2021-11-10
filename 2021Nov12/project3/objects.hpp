#ifndef __OBJECTS_HPP__
#define __OBJECTS_HPP__

#include "tools/cpputils/graphics/image.h"

//------------------------
// global constants
//------------------------

const graphics::Color COLOR_BLACK   (   0,   0,   0 );
const graphics::Color COLOR_GRAY    (  50,  50,  50 );
const graphics::Color COLOR_WHITE   ( 255, 255, 255 );
const graphics::Color COLOR_PINK    ( 255,  25, 150 );
const graphics::Color COLOR_RED     ( 255,   0,   0 );
const graphics::Color COLOR_DARKRED ( 210,  25,  25 );
const graphics::Color COLOR_ORANGE  ( 255, 127,   0 );
const graphics::Color COLOR_YELLOW  ( 255, 255,   0 );
const graphics::Color COLOR_GREEN   (   0, 200, 100 );
const graphics::Color COLOR_TEAL    (   0, 125, 255 );
const graphics::Color COLOR_BLUE    (   0,   0, 255 );
const graphics::Color COLOR_PURPLE  ( 127,   0, 255 );

//---------------------------
// class declarations
//---------------------------

class SolidObject
{
private:
  int _x_location;
  int _y_location;
  int _width;
  int _height;
  graphics::Image * _image;
  graphics::Color _color;

protected:
  graphics::Image * getImage() const { return _image; }

public:
  SolidObject(int width, int height, graphics::Image * image,
              const graphics::Color & color = COLOR_BLACK)
      : _x_location(0), _y_location(0), _width(width), _height(height),
        _image(image), _color(color) {}

  int getWidth() const { return _width; }
  int getHeight() const { return _height; }
  int getX() const { return _x_location; }
  int getY() const { return _y_location; }

  const graphics::Color & getColor() const { return _color; }

  void setX(int x) { _x_location = x; }
  void setY(int y) { _y_location = y; }

  bool collidesWith(const SolidObject * other) const;
  void draw() const;
};

class Ball : public SolidObject
{
public:
  Ball(int diameter, graphics::Image * image, const graphics::Color & color)
      : SolidObject(diameter, diameter, image, color) {}

  //void draw() const override;
  void draw() const
  {
    getImage()->DrawCircle(getX() + getWidth() / 2,
                           getY() + getHeight() / 2,
                           getWidth() / 2,
                           getColor());
  }
};

class Brick : public SolidObject
{
public:
  Brick(int width, int height, graphics::Image * image,
        const graphics::Color & color)
      : SolidObject(width, height, image, color) {}

  //void draw() const override;
  void draw() const
  {
      getImage()->DrawRectangle(getX(), getY(),
                                getWidth(), getHeight(),
                                getColor());
  }
};

class Paddle : public Brick
{
public:
  Paddle(int height, graphics::Image * image,
         const graphics::Color & color = COLOR_GRAY)
      : Brick(height * 4, height, image, color) {}
};

#endif
