#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "ASpell.hpp"


class Fireball : public ASpell
{
	private:

	public:
		//Constructors
		Fireball();
		Fireball(Fireball const &other);
		~Fireball();

		//Overload operator=
		Fireball &operator=(Fireball const &other);

		//Getters

		//Setters

		//Public member functions

		// Pure
		Fireball* clone() const;
};
