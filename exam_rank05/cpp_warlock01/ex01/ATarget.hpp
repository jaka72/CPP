#pragma once

/*
**==========================
**		Includes
**==========================
*/


#include <iostream>

class ASpell;

#include "ASpell.hpp"

class ATarget
{
	private:
	//protected:
		std::string type;

	public:
		//Constructors
		ATarget();
		ATarget(std::string type);
		ATarget(ATarget const &other);
		virtual ~ATarget();

		//Overload operator=
		ATarget &operator=(ATarget const &other);

		//Getters
		std::string const & getType() const;
		//Setters

		//Public member functions
		void getHitBySpell(ASpell const & spell) const;

		// pure
		virtual ATarget *clone() const = 0;

};
