#pragma once

/*
**==========================
**		Includes
**==========================
*/
#include "ASpell.hpp"


// class ATarget;
// class ASpell;

class Hokus : public ASpell // virtual NOT NEEDED!
{
	private:
		// std::string name;	// comes from parent
		// std::string effects;

	public:
		//Constructors
		Hokus();
		Hokus(Hokus const &other);
		~Hokus();

		//Overload operator=
		Hokus &operator=(Hokus const &other);

		// from pure
		Hokus* clone() const;   // ???  // where do we delete the returned NEW object?
//		MUST BE:
//		virtual ASpell ...

		//Getters // NOT NEEDED, ARE ALREADY IN PARENT!
		// std::string getName() const; // no, is already in ASpell

		//Setters


		//Public member functions

};
