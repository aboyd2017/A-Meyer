#include <iostream>
#include <string>
#include "sports.hpp"

// TODO
// provide the Competitive class "enroll" function definition here
void Competitive::enroll (const std::string & athlete_name)
{
  if (_athlete1.empty())
  {
    _athlete1 = athlete_name;
  }
  else if (_athlete2.empty())
  {
    _athlete2 = athlete_name;
  }
  else
  {
    std::cout << "Both athletes have already been registered" << std::endl;
  }

}

// the Team class "enroll" function adds the athlete's name received
// in the parameter to one of two teams till both teams are full
void Team::enroll(const std::string & athlete_name)
{
  if (_team1.size() < _team_size)
  {
    _team1.push_back(athlete_name);
  }
  else if (_team2.size() < _team_size)
  {
    _team2.push_back(athlete_name);
  }
  else
  {
    std::cout << "Both teams are full\n";
  }
}

// the Team class "display" function prints out all members of both teams
void Team::display() const
{
  for (int i = 0; i < _team1.size(); i++)
  {
    if (i != 0)
    {
      std::cout << ", ";
    }
    std::cout << _team1[i];
  }
  std::cout << " vs. ";
  for (int i = 0; i < _team2.size(); i++)
  {
    if (i != 0)
    {
      std::cout << ", ";
    }
    std::cout << _team2[i];
  }
}
