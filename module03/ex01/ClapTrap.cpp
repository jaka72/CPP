/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:49 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 14:27:34 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


// Constructor Default
ClapTrap::ClapTrap()
{
	std::cout << GRE"Default constructor ClapTrap\n" << RES;
	_name = "Default";
	_hit_pts = 10;
	_energy_pts = 10;
	_attack_damage = 0;
}


// Parameterized constructor
ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hit_pts = 10;
	_energy_pts = 10;
	_attack_damage = 0;
	std::cout << GRE"Constructor ClapTrap (" <<RES<< name << ")\n"; 
}


// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << GRE"Copy constructor ClapTrap (" <<RES<< copy._name << ")\n" << RES; 
	*this = copy;
}


// Overloaded operators
ClapTrap &ClapTrap::operator= (const ClapTrap &orig)
{
	std::cout << GRE"Overload operator= ClapTrap (" <<RES<< orig._name << ")\n";
	if (this == &orig)
		return (*this);
		
	this->_name = orig._name;
	this->_hit_pts = orig._hit_pts;
	this->_energy_pts = orig._energy_pts;
	this->_attack_damage = orig._attack_damage;
	return (*this);
}


// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << GRE"Destructor ClapTrap (" <<RES<< _name << ")\n"; 
}


// Public member functions
void	ClapTrap::attack(const std::string &target)
{	
	std::cout << LRD;
	if (_energy_pts <= 0 || _hit_pts <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack, because has no" 
			" points left.\n" << RES; 
		return ;
	}
	if (_energy_pts > 0)
	{	
		std::cout << "ClapTrap " << _name << " attacks " << target <<
			", causing him " << _attack_damage << " hit points of damage.\n";
		_energy_pts--;
		std::cout << "   (" << _name << " now has "<<  _energy_pts <<
			" energy points left)\n\n" << RES;
	}
}


void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << LMAG;
	std::cout << _name << " takes damage of "
		<< amount << " points\n";
	this->_hit_pts -= amount;
	if (this->_hit_pts > 0)
		std::cout << "   (Now has " << _hit_pts << " hit points, "
				  << _energy_pts << " energy points.)\n\n";
	else
	{
		this->_hit_pts = 0;
		std::cout << "   (Now has zero hit points and died.)\n\n";
	}
	std::cout << RES;
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << GRN;
	if (_energy_pts <= 0)
	{
		std::cout << _name << " can't be repaired, because he has 0 energy" 
			" points.\n" << RES; 
		return ;
	}

	if (_hit_pts <= 0)
	{
		std::cout << _name << " can't be repaired, because he is dead (" 
			<< _hit_pts << " hit points).\n" << RES; 
		return ;
	}

	_hit_pts += amount;
	_energy_pts--;
	std::cout << _name << " repaires himself by amount " 
		<< amount << "!\n";
	std::cout << "   (Now has " << _hit_pts << " hit points, " << _energy_pts << " energy points.)\n\n";
	std::cout << RES;
}
