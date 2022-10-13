/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 14:28:01 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


// Constructor Default
FragTrap::FragTrap(): ClapTrap()
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_damage = 30;
	std::cout << GRE"  Default constructor FragTrap\n" << RES; 
}


// Parameterized constructor
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_damage = 30;
	std::cout << GRE"  Constructor FragTrap (" <<RES<< name << ")\n";
};


// Copy constructor
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << GRE"  Copy Constructor FragTrap (" <<RES<< copy._name << ")\n" << RES;
	*this = copy;
}


// Overloaded operators
FragTrap &FragTrap::operator= (const FragTrap &orig)
{
	std::cout << GRE"  Overload operator= FragTrap (" <<RES<< orig._name << ")\n";
	if (this == &orig)
		return (*this);
	this->_name = orig._name;
	this->_hit_pts = orig._hit_pts;
	this->_energy_pts = orig._energy_pts;
	this->_attack_damage = orig._attack_damage;
	return (*this);
}


// Destructor
FragTrap::~FragTrap()
{
	std::cout << GRE"  Destructor FragTrap (" << RES << _name << ")\n"; 
}


// Public member functions
void FragTrap::highFivesGuys(void)
{
	std::cout << CYN"\n FragTrap " << _name << RES << " gives high fives to everybody.\n\n"; 
}


void	FragTrap::attack(const std::string &target)
{	
	std::cout << LRD;
	if (_energy_pts <= 0 || _hit_pts <= 0)
	{
		std::cout << "FragTrap " << _name << " can't attack, because has no" 
			" points left.\n" << RES; 
		return ;
	}
	if (_energy_pts > 0)
	{	
		std::cout << "FragTrap " << _name << " attacks " << target <<
			", causing him " << _attack_damage << " hit points of damage.\n";
		_energy_pts--;
		std::cout << "   (" << _name << " now has "<<  _energy_pts <<
			" energy points left)\n\n";
	}
}
