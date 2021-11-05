#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <sstream>
#include <string>

//-----------------------------------
// Exception Class
//-----------------------------------

class Exception
{
public:
  std::string msg;

  // Constructor
  Exception (const std::string &except)
  {
    msg = except;
  }

  std::string getMessage() const
  {
    return msg;
  }
  void setMessage (const std::string &new_except)
  {
    msg = new_except;
  }

protected:
  // Default constructor
  Exception () {}
};



//-----------------------------------
// InvalidArrayLengthException Class
//-----------------------------------

class InvalidArrayLengthException : public Exception
{
public:
  InvalidArrayLengthException (int size)
  {
    std::stringstream ss;
    ss << "Invalid number of elements (" << size << "). Value must be a"
       << " positive integer.";
    setMessage (ss.str ());
  }
};




// you do not need to modify the following class

class IndexOutOfRangeException : public Exception
{
public:
  IndexOutOfRangeException(int ix, int size)
  {
    std::stringstream ss;
    ss << "Invalid index " << ix << " for an array with " << size << " element"
       << (size == 1 ? "" : "s") << ". Value must be between 0 and " << size - 1
       << '.';
    setMessage(ss.str());
  }
};

#endif
