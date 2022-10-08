/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:38 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/08 19:13:50 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
	IN THE BASE CLASS THE MEMBERS ARE INITIALIZED AFTER FUNC()
	BUT HERE IN INHERITED CLASS THEY ARE INITIALIZED AS MEMBERS ???
*/
// Default constructor
ScavTrap::ScavTrap(): ClapTrap()		// some vars are from parent class
{										// some are from this class (int _guard)
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_damage = 20;
	this->_guard = false;
	std::cout << GRE"Default constructor ScavTrap\n" << RES; 
}

/*
	WHY IS IT GOOD TO HAVE THE SAME name IN THE ClapTrap ARGUMENT ???
	IT CREATES HIS PARENT, A Claptrap, BUT IT'S INVISIBLE.
	THE INVISIBLE PARENT CAN HAVE THE SAME name. 
	IT CAN ALSO HAVE ANOTHER STRING OR EMPTY - IN CREATES A ClapTrap OBJECT
	WITH ANOTHER NAME OR DEFAULT.

	You can override parent members, like _hit_pts = 100;
	Otherwise, _hit_pts will have value 10, which comes from parent Claptrap 
*/

// Parameterized constructor
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_damage = 20;
	this->_guard = false;
	_name = name;
	std::cout << GRE"Constructor ScavTrap called (" <<RES<< name << ")\n";
	//std::cout << "...Constructor ScavTrap called for this->_name " << this->_name << "\n";
	//std::cout << "...Constructor ScavTrap called for _name " << _name << "\n";
	//std::cout << "...Constructor ScavTrap called for hit_points " << _hit_pts << "\n";
};


// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)	// WHAT IS THIS LAST (copy) ???
{
	std::cout << GRE"Copy Constructor ScavTrap \n" << RES;
	*this = copy;	// IS THIS CORRECT?
					// MAYBE MISSING COPYING OF THE PARENT?
					// IT LOOKS LIKE PARENT'S VARIABLES ARE NOW ALREADY
					//	A PART OF THE CHILD, SO NO NEED TO DO ANYTHING 
					// WITH THE PARENT
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << GRE"Destructor ScavTrap (" << RES << _name << ")\n"; 
}


// Overloaded operators
ScavTrap &ScavTrap::operator= (const ScavTrap &orig)
{
	// HERE PROBABLY NEEDS TO COPY ALL THE VARIABLES FROM orig
	//		Which is only 1: int _guard
	// 		But im not sure if also from the parent  ???
	this->_hit_pts = orig._hit_pts;;
	this->_energy_pts = orig._energy_pts;
	this->_attack_damage = orig._attack_damage;
	this->_guard = orig._guard;
	this->_name = orig._name;
	return (*this);
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
