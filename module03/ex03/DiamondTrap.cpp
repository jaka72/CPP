/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:23:51 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/11 16:17:53 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
// DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << GRE"     Default constructor DiamondTrap \n" << RES; 

    FragTrap abc;
    ScavTrap ert;

    this->_hit_pts = abc._hit_pts;
    this->_energy_pts = ert._energy_pts;
}


// DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name")
{
	std::cout << GRE"     Parameterized constructor DiamondTrap \n" << RES; 
    this->_name = name;
}


DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << GRE"Copy constructor DiamondTrap \n" << RES; 
	*this = copy;
}

DiamondTrap &DiamondTrap::operator= (const DiamondTrap &orig)
{
    if (this == &orig)
        return (*this);

// THESE ARE AMBIGUOUS BECAUSE OF DOUBLE INHERITANCE OF SAME VARIABLES
    // this->_name = orig._name;
	// this->_hit_pts = orig._hit_pts;
	// this->_energy_pts = orig._energy_pts;
	// this->_attack_damage = orig._attack_damage;
	return (*this);
}


DiamondTrap::~DiamondTrap()
{
	std::cout << GRE"     Destructor DiamonDTrap (" <<RES<< _name << ")\n"; 
}