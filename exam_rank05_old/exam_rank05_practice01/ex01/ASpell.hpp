#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include <string>

class ATarget;

#include "ATarget.hpp"

class ASpell
{
	private:
	// protected:
		std::string name;
		std::string effects;

	public:
		//Constructors
		ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(ASpell const &other);
		virtual ~ASpell();

		//Overload operator=
		ASpell &operator=(ASpell const &other);

		//Getters
		std::string getName() const;
		std::string getEffects() const;

		//Setters

		//Public member functions
		void launch(ATarget const & target) const;


		// pure
		virtual ASpell* clone() const = 0;
};
