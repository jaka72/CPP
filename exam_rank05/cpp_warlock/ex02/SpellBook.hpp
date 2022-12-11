#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include <iostream>
#include <vector>

class ASpell;

#include "ASpell.hpp"


class SpellBook
{
	private:
		std::vector<ASpell*>	vect;
		SpellBook(SpellBook const &other);
		SpellBook &operator=(SpellBook const &other);

	public:
		//Constructors
		SpellBook();
		~SpellBook();

		//Overload operator=

		//Getters

		//Setters

		//Public member functions
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);

};

