#ifndef __CELLPHONE_HPP__
#define __CELLPHONE_HPP__

#include <string>

//------------------------------
// Speaker class declaration
//------------------------------

class Speaker
{
private:
  std::string _name;

public:
  Speaker(const std::string & name) : _name(name) {}
  std::string getName() const { return _name; }
};

//------------------------------
// Cellphone class declaration
//------------------------------

// TODO
// provide your Cellphone class here
class Cellphone
{
private:
  std::string _type;
  std::string _number;
  Speaker * _speaker;

public:
  Cellphone (const std::string & type, const std::string & number);
  void pair (Speaker * speaker) { _speaker = speaker;}
  void display () const;
};


#endif
