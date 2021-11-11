#include <iostream>
#include <set>
#include <vector>
#include "game.hpp"

Game::~Game()
{
  _game_screen.RemoveMouseEventListener(*this);
  _game_screen.RemoveAnimationEventListener(*this);

  // TODO
  // delete the memory that was allocated for the `_ball` and `_paddle`
  // as well as all bricks in the `_bricks` vector
  delete _paddle;
  delete _ball;

  for (int i = 0; i < _bricks.size(); ++i)
  {
    delete _bricks[i];
  }

}

void Game::initialize()
{
  _game_screen.Initialize(IMAGE_SIZE, IMAGE_SIZE);

  // TODO
  // allocate memory for the `_paddle`
  // pass the parameters: `PADDLE_HEIGHT` and the address of `_game_screen`
  // to the non-default constructor
  _paddle = new Paddle (PADDLE_HEIGHT, &_game_screen);


  // TODO
  // call mutators to set the x and y values for the `_paddle`
  // set x to place the paddle in the middle of the screen
  // hint: "(IMAGE_SIZE - paddle width) / 2" will place it in the middle
  // set y to "IMAGE_SIZE - BRICK_HEIGHT * 3"
  // this will place the paddle way at the bottom of the game screen
  _paddle->setX ((IMAGE_SIZE - _paddle->getWidth()) / 2);
  _paddle->setY (IMAGE_SIZE - BRICK_HEIGHT * 3);


  // TODO
  // allocate memory for the `_ball`
  // for the non-default constructor, pass the parameters:
  // `BALL_DIAMETER`, the address of `_game_screen`, and whatever color you
  // want your ball to be (colors are defined in the `objects.hpp` file)
  _ball = new Ball (BALL_DIAMETER, &_game_screen, COLOR_PURPLE);

  // TODO
  // call mutators to set the x and y values for the `_ball`
  // set x to place the ball in the middle of the screen
  // hint: "(IMAGE_SIZE - ball width) / 2" will place it in the middle
  // set y to half the IMAGE_SIZE
  // this will place the paddle way at the bottom of the game screen
  _ball->setX ((IMAGE_SIZE - _ball->getWidth()) / 2);
  _ball->setY (IMAGE_SIZE / 2);


  // create a vector of colors
  // these will be used to color the rows of bricks
  std::vector<graphics::Color> colors;
  colors.push_back(COLOR_RED);
  colors.push_back(COLOR_ORANGE);
  colors.push_back(COLOR_GREEN);
  colors.push_back(COLOR_TEAL);
  colors.push_back(COLOR_BLUE);

  // fill the vector of bricks
  // set the x and y of each brick to space them out as 5 rows across
  // the top of the game screen
  for (int i = 0; i < IMAGE_SIZE / (BRICK_WIDTH + BRICK_SPACING); i++)
  {
    for (int j = 0; j < BRICK_ROWS; j++)
    {
      graphics::Color color = colors[j % BRICK_ROWS];
      Brick * brick =
        new Brick(BRICK_WIDTH, BRICK_HEIGHT, &_game_screen, color);
      brick->setX(i * (BRICK_WIDTH + BRICK_SPACING));
      brick->setY((j + EMPTY_ROWS) * (BRICK_HEIGHT + BRICK_SPACING));
      _bricks.push_back(brick);
    }
  }

  // draw all objects onto the game screen
  draw();

  _game_screen.AddMouseEventListener(*this);
  _game_screen.AddAnimationEventListener(*this);
}

void Game::OnMouseEvent(const graphics::MouseEvent & event)
{
  // change state if the game is just beginning
  if (_game_state == NOT_STARTED &&
      event.GetMouseAction() == graphics::MouseAction::kReleased)
  {
    _game_state = IN_PROGRESS;
  }

  // set the new paddle location according to the mouse event
  if (event.GetX() + _paddle->getWidth() <= _game_screen.GetWidth())
  {
    _paddle->setX(event.GetX());
  }
}

void Game::moveGamePieces()
{
  // TODO
  // if the ball has hit the edge of the gameboard, change the direction
  // of travel for the ball (multiply speed by -1)
  // for x, we want to change direction as soon as the ball hits either
  // the left or right wall (left wall is at 0, and right wall is the width
  // of the game screen `_game_screen.GetWidth()`)
  // for y, we want to change direction if it hits the top of the game
  // screen (location 0) or if it collides with the paddle

  // Hit walls (x)
  if (_ball->getX () == 0 || _ball->getX () + _ball->getWidth () == _game_screen.GetWidth ())
  {
    _speed_x *= -1;
  }
  // Hit ceiling (y)
  if (_ball->getY () == 0 || _ball->collidesWith (_paddle))
  {
    _speed_y *= -1;
  }


  // TODO
  // move the ball to its next location
  // simply put, this would be it's current x/y plus the speed for x and y
  // however, we actually want to step the speed up by only one at a time
  // in order to stop it from moving a particular direction once it hits
  // something - this way it doesn't pass through a wall or a brick or the
  // paddle
  // note: the speed of the ball could skip steps
  // for example, if _speed_x is set to 7 then the ball would jump by 7
  // pixels on the game board, but what if a wall was hit at 4 pixels?
  // move one step at a time to be sure it doesn't pass through a wall
  // or the paddle

  for (int i = 0; i < INITIAL_SPEED; ++i)
  {
    bool obj_hit = false;
    //std::cout << i << " : " << _speed_x << " : "  << _speed_y << " : "  << std:: endl;
    if (_speed_x < 0)
    {
      _ball->setX (_ball->getX () - 1);
      if (_ball->getX () == 0)
      {
        obj_hit = true;
      }
    }
    else
    {
      _ball->setX (_ball->getX () + 1);
      if (_ball->getX () + _ball->getWidth () == _game_screen.GetWidth ())
      {
        obj_hit = true;
      }
    }

    if (_speed_y < 0)
    {
      _ball->setY (_ball->getY () - 1);
      if (_ball->collidesWith (_paddle))
      {
        obj_hit = true;
      }
    }
    else
    {
      _ball->setY (_ball->getY () + 1);
      if (_ball->getY () == 0  || _ball->collidesWith (_paddle) ||
            _ball->getY () + _ball->getHeight () == _game_screen.GetHeight())
      {
        obj_hit = true;
      }
    }

    if (obj_hit == true)
    {
      break;
    }
  }

}

void Game::checkGameState()
{
  // check whether any bricks have been hit by the ball
  for (auto it = _bricks.begin(); it != _bricks.end(); )
  {
    if (_ball->collidesWith(*it))
    {
      it = _bricks.erase(it);
      _speed_y *= -1;
    }
    else
    {
      it++;
    }
  }

  // TODO
  // if all bricks have been removed, then change the game state to
  // indicate the player won
  // otherwise
  // if ball has hit the bottom of the game screen, then change the
  // game state to indicate the player lost

  if (_bricks.size() == 0)
  {
    _game_state = WON;
  }

  if (_ball->getY () + _ball->getHeight () == _game_screen.GetHeight ())
  {
    _game_state = LOST;
  }

}

void Game::OnAnimationStep()
{
  if (_game_state != IN_PROGRESS)
  {
    return;
  }
  moveGamePieces();
  checkGameState();

  // redraw the game screen
  draw();
}

void Game::draw()
{
  // TODO
  // to draw the game screen, first erase everything by drawing a new
  // rectangle for the `_game_screen`
  // the `DrawRectangle` function takes 5 parameters:
  // x, y, height, width, and color
  // x and y will be 0, height and width will be that of the _game_screen
  // (it has accessor functions `GetHeight` and `GetWidth`)
  // and for color you can use `COLOR_WHITE` or you can play with it to
  // see if there's another color you like better
  _game_screen.DrawRectangle (0, 0, _game_screen.GetHeight (), _game_screen.GetWidth (), COLOR_WHITE);

  // TODO
  // then redraw your game pieces
  // note that they could have moved x and/or y location, and their new
  // locations will be drawn now
  // hint: call the `draw` function for everything (the ball, paddle,
  // and all of the bricks)
  _ball->draw ();
  _paddle->draw ();

  for (int i = 0; i < _bricks.size(); ++i)
  {
    _bricks[i]->draw ();
  }

  // flush the new image onto the screen
  _game_screen.Flush();
}
