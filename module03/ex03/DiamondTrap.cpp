/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:23:51 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/17 15:38:16 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{

    FragTrap frag;
    ScavTrap scav;

	this->_name				= "default";
	this->_hit_pts 			= frag.get_hit_points();
	this->_attack_damage 	= frag.get_attack_damage();
    this->_energy_pts 		= scav.get_energy_points();
    //this->attack 			= ScavTrap::attack;		// not needed
	std::cout << GRE"      Default constructor DiamondTrap (" <<RES<< _name << ")\n" << RES; 
}


// Parameterized constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	FragTrap frag;
    ScavTrap scav;
	
    this->_name 			= name;
	this->_hit_pts 			= frag.get_hit_points();
	this->_attack_damage 	= frag.get_attack_damage();
    this->_energy_pts 		= scav.get_energy_points();
	std::cout << GRE"      Parameterized constructor DiamondTrap (" <<RES<< _name << ") \n" << RES; 
}


// Copy constructor			// THIS WAS MAYBE MISSING IN THE VOG-PUSH, error on Linux ???
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << GRE"      Copy constructor DiamondTrap \n" << RES; 
	*this = copy;
}


// Overload operator=
DiamondTrap &DiamondTrap::operator= (const DiamondTrap &orig)
{
	std::cout << GRE"      Overload operator= DiamondTrap (" <<RES<< orig._name << ")\n";
    if (this == &orig)
        return (*this);

    this->_name 			= orig._name;
	this->_hit_pts 			= orig._hit_pts;
	this->_energy_pts 		= orig._energy_pts;
	this->_attack_damage 	= orig._attack_damage;
	return (*this);
}


// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << GRE"      Destructor DiamonDTrap (" <<RES<< _name << ")\n"; 
}



// void	DiamondTrap::attack(const std::string &target)
// {	
// 	std::cout << LRD;
// 	if (_energy_pts <= 0 || _hit_pts <= 0)
// 	{
// 		std::cout << "ScavTrap " << _name << " can't attack, because has no" 
// 			" points left.\n" << RES; 
// 		return ;
// 	}
// 	if (_energy_pts > 0)
// 	{
// 		std::cout << "ScavTrap " << _name << " attacks " << target <<
// 			", causing him " << _attack_damage << " hit points of damage.\n";
// 		_energy_pts--;
// 		std::cout << "   (" << _name << " now has "<<  _energy_pts <<
// 			" energy points left)\n\n";
// 	}
// }



// Public member functions
// Getter
void DiamondTrap::print_values()
{
	std::cout << "\nName: " << _name << "\n";
	std::cout << "  hit_pts:       " << _hit_pts << " (from Frag)\n"; 
	std::cout << "  energy_pts:    " << _energy_pts << " (from Scav)\n"; 
	std::cout << "  attack_damage: " << _attack_damage << " (from Frag)\n\n"; 
}


void DiamondTrap::attack(const std::string &name)
{
	ScavTrap::attack(name);
}


void DiamondTrap::WhoAmI()
{
	std::cout << "DiamondTrap _name: " << this->_name << "\n";
	std::cout << "Grandparent _name: " << ScavTrap::_name << "\n\n";
}
