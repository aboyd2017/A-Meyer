#include <iostream>
#include "cellphone.hpp"


// TODO
// provide your Cellphone "display" function definition here
Cellphone::Cellphone (const std::string & type, const std::string & number)
{
	_type = type;
	_number = number;
	_speaker = NULL;
}

void Cellphone::display () const
{
	std::cout << _type << std::endl;
	std::cout << _number << std::endl;
	if (_speaker != NULL)
	{
		std::cout << _speaker->getName () << " speaker";
	}
	else
	{
		std::cout << "No speaker attached";
	}
}