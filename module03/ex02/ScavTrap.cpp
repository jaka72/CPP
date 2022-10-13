/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:38 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 14:28:07 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_damage = 20;
	this->_guard_status = false;
	std::cout << GRE"  Default constructor ScavTrap\n" << RES; 
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_damage = 20;
	this->_guard_status = false;
	std::cout << GRE"  Constructor ScavTrap (" <<RES<< name << ")\n";
};


// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << GRE"  Copy Constructor ScavTrap (" <<RES<< copy._name << ")\n" << RES;
	*this = copy;
}


// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << GRE"  Destructor ScavTrap (" << RES << _name << ")\n"; 
}


// Overloaded operators
ScavTrap &ScavTrap::operator= (const ScavTrap &orig)
{
	std::cout << GRE"Overload operator= ScavTrap (" <<RES<< orig._name << ")\n";
	if (this == &orig)
		return (*this);
	
	this->_name = orig._name;
	this->_hit_pts = orig._hit_pts;;
	this->_energy_pts = orig._energy_pts;
	this->_attack_damage = orig._attack_damage;
	this->_guard_status = orig._guard_status;
	return (*this);
}


// Public member functions
void ScavTrap::guardGate()
{
	std::cout << BLU;
	if (_guard_status == false)
	{
		_guard_status = true;
		std::cout << "\nFunction guardgate(), ON: " << _name << " is in Gate keeper mode\n"; 
	}
	else
	{
		_guard_status = false;
		std::cout << "\nFunction guardgate(), OFF: " << _name << " is not in Gate keeper mode\n"; 
	}
	std::cout << RES;
}



void	ScavTrap::attack(const std::string &target)
{	
	std::cout << LRD;
	if (_energy_pts <= 0 || _hit_pts <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack, because has no" 
			" points left.\n" << RES; 
		return ;
	}
	if (_energy_pts > 0)
	{	
		std::cout << "ScavTrap " << _name << " attacks " << target <<
			", causing him " << _attack_damage << " hit points of damage.\n";
		_energy_pts--;
		std::cout << "   (" << _name << " now has "<<  _energy_pts <<
			" energy points left)\n\n";
	}
}
