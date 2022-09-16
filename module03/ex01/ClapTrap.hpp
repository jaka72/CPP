#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include "colors.h"

/*
	It is best practice to initialize the members immediately
			ie:	int hitpoints{20}
				ClapTrap = default;
	But it is only allowed from c++11
*/
class ClapTrap
{
	// private:		//	IF THIS IS THE BASE CLASS FOR AN INHERITED CLASS
	protected:		// 		THEN IT MUST BE protected, OR IT GIVES ERROR ????
		std::string	m_name;
		int			hit_pts;
		int			energy_pts;
		int			attack_damage;
		bool		guard;

	public:
	// Constructors:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		
	// Destructor	
		virtual ~ClapTrap();	// WHY SHOULD HERE BE VIRTUAL ???
		// ~ClapTrap();	// WHY SHOULD HERE BE VIRTUAL ???
		
	// Overloaded operators
		ClapTrap &operator= (const ClapTrap &claptrap);

	// Public member functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void print_hit_pts();	// just for testing

};

#endif
