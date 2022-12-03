#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
	private:
		//std::string type;  // protected in parent

	public:
		//Constructors
		Dummy();
		Dummy(Dummy const &other);
		~Dummy();

		//Overload operator=
		Dummy &operator=(Dummy const &other);

		// from pure
		Dummy* clone() const;

		//Getters

		//Setters

		//Public member functions

};
