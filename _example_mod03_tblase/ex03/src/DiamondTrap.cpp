/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 11:22:15 by tblaase       #+#    #+#                 */
/*   Updated: 2022/10/14 13:05:30 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "DiamondTrap.hpp"
#include "../include/DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap")
{
	this->_name = "defaultDT";
	this->_hit_pts = FragTrap::_hit_pts;
	this->_energy_pts = ScavTrap::_energy_pts;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "      DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "      DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hit_pts = FragTrap::_hit_pts;
	this->_energy_pts = ScavTrap::_energy_pts;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "      DiamondTrap Constructor for the name " << this->_name << " called" << std::endl;
}

// Deconstructors
DiamondTrap::~DiamondTrap()
{
	std::cout << "      DiamondTrap Deconstructor for " << this->_name << " called" << std::endl;
}

// Overloaded Operators
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name = src._name + "_clap_trap";
	this->_hit_pts = src._hit_pts;
	this->_energy_pts = src._energy_pts;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

// Public Methods
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << this->_name <<
	" and i am originated from the ClapTrap named " << ClapTrap::_name << "." <<
	std::endl;
}

// Getter

// Setter


// jaka ////////////////////////////
// Public member functions
// Getter
void DiamondTrap::print_values()
{
	std::cout << "\nName: " << _name << "\n";
	std::cout << "  hit_pts:       " << _hit_pts << " (from Frag)\n"; 
	std::cout << "  energy_pts:    " << _energy_pts << " (from Scav)\n"; 
	std::cout << "  attack_damage: " << _attack_dmg << " (from Frag)\n\n"; 
}
