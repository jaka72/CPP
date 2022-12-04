#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include <iostream>
// #include "Warlock.hpp"
#include "colors.h"

class ASpell;

#include "ASpell.hpp"

class ATarget //: public ASpell
{
	protected:
		std::string type;

	public:
		//Constructors
		ATarget();
		ATarget(ATarget const &other);
		ATarget(std::string tp);
		virtual ~ATarget();

		//Overload operator=
		ATarget &operator=(ATarget const &other);

		//Getters
		const std::string& getType() const;


		// Clone pure function
		virtual ATarget* clone() const = 0;   // ???


		//Setters

		//Public member functions
		void getHitBySpell(const ASpell& asp) const;

};
