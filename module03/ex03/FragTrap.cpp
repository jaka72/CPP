/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/17 12:35:44 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(): ClapTrap()
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_damage = 30;
	std::cout << GRE"   Default constructor FragTrap (" <<RES<< _name << ") \n" << RES; 


	// temp
	//temp = 44;
}

// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_pts = 100;
	this->_energy_pts = 100;
	this->_attack_damage = 30;
	_name = name;
	std::cout << GRE"   Constructor FragTrap (" <<RES<< name << ")\n";
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << GRE"   Copy Constructor FragTrap \n" << copy._name << ")\n" << RES;
	*this = copy;
}


// Destructor
FragTrap::~FragTrap()
{
	std::cout << GRE"   Destructor FragTrap (" << RES << _name << ")\n"; 
}


// Overloaded operators
FragTrap &FragTrap::operator= (const FragTrap &orig)
{
	std::cout << GRE"   Overload operator= ClapTrap (" <<RES<< orig._name << ")\n";
	if (this == &orig)
		return (*this);

	this->_hit_pts = orig._hit_pts;;
	this->_energy_pts = orig._energy_pts;
	this->_attack_damage = orig._attack_damage;
	this->_guard = orig._guard;
	this->_name = orig._name;
	return (*this);
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




// Public member functions
void FragTrap::highFivesGuys(void)
{
	std::cout << CYN"\nFunction highFivesGuys() called from FragTrap " << _name << RES << "\n\n"; 
}


// Getters
int FragTrap::get_hit_points()
{
	return (this->_hit_pts);
}


int FragTrap::get_attack_damage()
{
	return (this->_attack_damage);
}
