/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:38 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/09 11:31:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_damage = 20;
	this->_guard = false;
	std::cout << GRE"Default constructor ScavTrap\n" << RES; 
}


// Parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_damage = 20;
	this->_guard = false;
	_name = name;
	std::cout << GRE"Constructor ScavTrap (" <<RES<< name << ")\n";
};


// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)	// TEST THIS!, WHY ClapTrap(copy), WHAT IS THIS copy ???
{
	std::cout << GRE"Copy Constructor ScavTrap \n" << RES;
	*this = copy;
}


// Overloaded operators
ScavTrap &ScavTrap::operator= (const ScavTrap &orig)
{
	this->_hit_pts = orig._hit_pts;;
	this->_energy_pts = orig._energy_pts;
	this->_attack_damage = orig._attack_damage;
	this->_guard = orig._guard;
	this->_name = orig._name;
	return (*this);
}


// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << GRE"Destructor ScavTrap (" << RES << _name << ")\n"; 
}


// Public member functions
void ScavTrap::guardGate()
{
	std::cout << BLU;
	if (_guard == false)
	{
		_guard = true;
		std::cout << "\nFunction guardgate(), ON: " << _name << " is in Gate keeper mode\n"; 
	}
	else
	{
		_guard = false;
		std::cout << "\nFunction guardgate(), OFF: " << _name << " is not in Gate keeper mode\n"; 
	}
	std::cout << RES;
}
