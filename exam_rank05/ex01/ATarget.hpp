#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include <iostream>
// #include "ASpell.hpp"
#include "Warlock.hpp"
#include "colors.h"

class ASpell;


class ATarget //: public ASpell
{
	private:
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
