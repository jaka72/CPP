#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "SpellBook.hpp"
#include "ATarget.hpp"
#include "colors.h"


// class ATarget;
// class ASpell;

class Warlock
{
	private:
		std::string 			_name;
		std::string 			_title;
		// std::vector<ASpell*>	vect;
		SpellBook				spellbook;


		Warlock();
		Warlock(Warlock const &other);
		Warlock &operator=(Warlock const &other);


	public:
		//Constructors
		Warlock(std::string name, std::string title);
		~Warlock();


		// Getters
		const std::string& getName() const;
		const std::string& getTitle() const;

		// Setters
		void setTitle(std::string str);

		void introduce() const;


		// functions
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget& trg);


};
