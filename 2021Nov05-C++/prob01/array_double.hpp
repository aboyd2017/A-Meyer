#ifndef __ARRAY_DOUBLE_HPP__
#define __ARRAY_DOUBLE_HPP__

#include <sstream>
#include <string>

const std::string DEFAULT_FILENAME = "doubles.txt";

//-----------------------------------
// ArrayDouble Class
//-----------------------------------

class ArrayDouble
{
private:
	double *_array;
	int _count;

public:
	ArrayDouble (int);
	~ArrayDouble ();

	double & operator[] (int) const;
	void display ();
	void save (const std::string & = DEFAULT_FILENAME);
};



#endif