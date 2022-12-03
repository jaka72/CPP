#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include <iostream>



// #include "ATarget.hpp"
#include "Warlock.hpp"
#include "colors.h"


class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:
		//Constructors
		ASpell();
		ASpell(ASpell const &other);
		ASpell(std::string nm, std::string eff);

		virtual ~ASpell();

		//Overload operator=
		ASpell &operator=(ASpell const &other);

		//Getters
		std::string getName() const;
		std::string getEffects() const;

		// Clone pure method ???
		virtual ASpell* clone() const = 0;   // ???

		//Setters

		//Public member functions
		void launch(const ATarget& trg);

};
