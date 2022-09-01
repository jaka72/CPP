#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		&wp;

	public:

		HumanA(std::string name, Weapon &wp_orig);

		~HumanA();

		void	attack();
};

#endif
