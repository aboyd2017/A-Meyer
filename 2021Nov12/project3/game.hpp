#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string>
#include <vector>
#include "tools/cpputils/graphics/image.h"
#include "objects.hpp"

//------------------------
// global constants
//------------------------

const int IMAGE_SIZE = 500;
const int BALL_DIAMETER = 18;
const int PADDLE_HEIGHT = 20;
const int BRICK_HEIGHT = 20;
const int BRICK_WIDTH = 48;
const int BRICK_SPACING = 2;

const int BRICK_ROWS = 5;
const int EMPTY_ROWS = 2;

const int INITIAL_SPEED = 7; // note: must be non-zero

const int STATE_FONT_SIZE = 50;
const int SCORE_FONT_SIZE = 25;

const std::string HIGH_SCORE_FILE = "high_score.txt";

const std::string INITIAL_TEXT = "CLICK TO START";
const std::string PLAYER_LOST_TEXT = "GAME OVER";
const std::string PLAYER_WON_TEXT = "YOU WON";

const int INITIAL_TEXT_X = 80;
const int PLAYER_LOST_TEXT_X = 130;
const int PLAYER_WON_TEXT_X = 150;

//-----------------------------
// class declarations
//-----------------------------

// Runs a Breakout game.
// You do not need to modify this code.
class Game : public graphics::MouseEventListener,
             public graphics::AnimationEventListener
{
private:
  // Represents the state of the game.
  enum GameState
  {
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    LOST = 3,
    WON = 4
  };

  // TODO
  // add a pointer to a `Ball` named `_ball`
  // add a pointer to a 'Paddle` named `_paddle`
  // add a vector of pointers to bricks (`Brick *`) named `_bricks`
  Ball *_ball;
  Paddle *_paddle;
  std::vector <Brick *> _bricks;


  graphics::Image _game_screen;

  // speed will be the same for x/y but one could be traveling in a negative
  // direction while the other is traveling in the positive direction
  int _speed_x;
  int _speed_y;
  GameState _game_state;

  // TODO
  // add three helper methods
  // for all three of these, they take no parameters and return void
  // function names are: `draw`, `checkGameState`, and `moveGamePieces`
  void draw ();
  void moveGamePieces ();
  void checkGameState ();


public:
  Game() : _ball(nullptr), _paddle(nullptr), _game_state(NOT_STARTED),
           _speed_x(INITIAL_SPEED), _speed_y(INITIAL_SPEED) {}
  ~Game();

  // Get ready to play.
  void initialize();

  // Begin the event loop by showing the image.
  void start() { _game_screen.ShowUntilClosed("Breakout"); }

  // Gets mouse events from the image.
  void OnMouseEvent(const graphics::MouseEvent & event) override;

  // Gets animation events from the image.
  void OnAnimationStep() override;
};

#endif
