#ifndef __SPORTS_HPP__
#define __SPORTS_HPP__

#include <iostream>
#include <string>
#include <vector>

//------------------------------
// constants
//------------------------------

const int TEAM_SIZE = 4;

//------------------------------
// Sport class declaration
//------------------------------

class Sport
{
public:
  // TODO
  // provide the Sport class pure virtual functions here
  virtual void enroll (const std::string & athlete_name) = 0;
  virtual void display () const = 0;

};

//------------------------------
// Competitive class declaration
//------------------------------

// TODO
// provide your Competitive class here
class Competitive : public Sport
{
private:
  std::string _athlete1;
  std::string _athlete2;

public:
  void enroll (const std::string & athlete_name);
  void display () const {std::cout << _athlete1 << " vs. " << _athlete2;}
};


//------------------------------
// Team class declaration
//------------------------------

class Team : public Sport
{
private:
  int _team_size;
  std::vector<std::string> _team1;
  std::vector<std::string> _team2;

public:
  Team(int size) : _team_size(size) {}
  void enroll(const std::string & athlete_name);
  void display() const;
};

//------------------------------
// Athlete class declaration
//------------------------------

// TODO
// provide your Athlete class here
class Athlete
{
private:
  std::string _name;

public:
  Athlete (const std::string & athlete_name) {_name = athlete_name;}
  void join (Sport * sport) {sport->enroll (_name);}
};



#endif
