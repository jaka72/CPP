#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "ASpell.hpp"


// class ATarget;
// class ASpell;

class Fwoosh : public ASpell // virtual NOT NEEDED!
{
	private:
		// std::string name;	// comes from parent
		// std::string effects;

	public:
		//Constructors
		Fwoosh();
		Fwoosh(Fwoosh const &other);
		~Fwoosh();

		//Overload operator=
		Fwoosh &operator=(Fwoosh const &other);

		// from pure
		Fwoosh* clone() const;   // ???  // where do we delete the returned NEW object
//		MUST BE:
//		virtual ASpell ...

		//Getters // NOT NEEDED, ARE ALREADY IN PARENT!
		// std::string getName() const; // no, is already in ASpell

		//Setters


		//Public member functions

};
