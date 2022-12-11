#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	private:

	public:
		//Constructors
		Fwoosh();
		Fwoosh(std::string name, std::string effects);
		Fwoosh(Fwoosh const &other);
		~Fwoosh();

		//Overload operator=
		Fwoosh &operator=(Fwoosh const &other);

		//Getters

		//Setters

		//Public member functions


		// from pure
		ASpell* clone() const;
};
