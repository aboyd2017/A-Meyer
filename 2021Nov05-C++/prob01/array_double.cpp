#include <iomanip>
#include <fstream>
#include <iostream>
#include "array_double.hpp"
#include "exception.hpp"


//-----------------------------------
// ArrayDouble constructor definition
//-----------------------------------

ArrayDouble::ArrayDouble (int size)
{
  _array = nullptr;
  _count = 0;

  if (size < 0)
  {
    throw InvalidArrayLengthException (size);
  }
  else
  {
    // Valid size value
    _count = size;

    // Check size above 0
    if (size > 0)
    {
      _array = new double [size]{0};
    }
  }
}

//-----------------------------------
// ArrayDouble destructor definition
//-----------------------------------

ArrayDouble::~ArrayDouble ()
{
  // Clean up dynamic array
  delete [] _array;
}

//-----------------------------------
// operator[] override definition
//-----------------------------------

double &ArrayDouble::operator[] (int idx) const
{
  if (idx >= _count || idx < 0)
  {
    throw IndexOutOfRangeException(idx, _count);
  }
  else
  {
    return _array[idx];
  }
}

//-----------------------------------
// ArrayDouble save definition
//-----------------------------------

void ArrayDouble::save (const std::string & filename)
{
  // If _count is greater than zero, append the array to the file
  if (_count > 0)
  {

    std::ofstream outfile;

    outfile.open (filename, std::ios_base::app);

    for (int i = 0; i < _count; i++)
    {
      outfile << ' ' << _array[i];
    }
    
    outfile << '\n';

  }
}

// you do not need to modify this function

void ArrayDouble::display()
{
  if (_count <= 0)
  {
    std::cout << "Array is empty.\n";
  }
  else
  {
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "Array contents:";

    for (int i = 0; i < _count; i++)
    {
      std::cout << ' ' << _array[i];
    }
    std::cout << std::endl;
  }
}






