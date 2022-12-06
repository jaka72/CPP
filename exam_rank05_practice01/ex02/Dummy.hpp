#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include "ATarget.hpp"

class Dummy : public ATarget
{
	private:

	public:
		//Constructors
		Dummy();
		Dummy(Dummy const &other);
		~Dummy();

		//Overload operator=
		Dummy &operator=(Dummy const &other);

		//Getters

		//Setters

		//Public member functions


		// from pure
		// NOT SURE IF IT HAS TO BE VIRTUAL HERE, OR ONLY IN PARENT ???
			    ATarget* clone() const; // ??? what is the return type?
//		virtual ATarget* clone() const; // ??? what is the return type?
};
