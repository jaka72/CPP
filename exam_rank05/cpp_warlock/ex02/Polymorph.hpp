#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	private:

	public:
		//Constructors
		Polymorph();
		Polymorph(Polymorph const &other);
		~Polymorph();

		//Overload operator=
		Polymorph &operator=(Polymorph const &other);

		//Getters

		//Setters

		//Public member functions

		// from pure
		Polymorph* clone() const;

};
