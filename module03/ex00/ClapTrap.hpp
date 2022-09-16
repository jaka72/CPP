#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>



/*
	It is best practice to initialize the members immediately
			ie:	int hitpoints{20}
				ClapTrap = default;
	But it is only allowed from c++11
*/
class ClapTrap
{
	private:
		std::string	m_name;
		int			hit_pts;
		int			energy_pts;
		int			attack_damage;

	public:
	// Constructors:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		
	// Destructor	
		~ClapTrap();
		
	// Overloaded operators
		ClapTrap &operator= (const ClapTrap &claptrap);

	// Public member functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
