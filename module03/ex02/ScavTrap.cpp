/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:37:04 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/08 19:37:05 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
	IN THE BASE CLASS THE MEMBERS ARE INITIALIZED AFTER FUNC()
	BUT HERE IN INHERITED CLASS THEY ARE INITIALIZED AS MEMBERS ???
*/
ScavTrap::ScavTrap(): ClapTrap()
{
	//hit_pts = 100;		// CAN BE ALSO WITHOUT ->this
	this->hit_pts = 100;
	this->energy_pts = 50;
	this->attack_damage = 20;
	this->guard = false;
	std::cout << GRE"Default constructor ScavTrap called\n" << RES; 
}

/*
	WHY IS IT GOOD TO HAVE THE SAME name IN THE ClapTrap ARGUMENT ???
	IT CREATES HIS PARENT, A Claptrap, BUT IT'S INVISIBLE.
	THE INVISIBLE PARENT CAN HAVE THE SAME name. 
	IT CAN ALSO HAVE ANOTHER STRING OR EMPTY - IN CREATES A ClapTrap OBJECT
	WITH ANOTHER NAME OR DEFAULT.

	You can override parent members, like hit_pts = 100;
	Otherwise, hit_pts will have value 10, which comes from parent Claptrap 
*/
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	hit_pts = 100;
	this->energy_pts = 50;
	this->attack_damage = 20;
	this->guard = false;
	m_name = name;
	std::cout << GRE"Constructor ScavTrap called to create " <<RES<< name << "\n";
	//std::cout << "...Constructor ScavTrap called for this->m_name " << this->m_name << "\n";
	//std::cout << "...Constructor ScavTrap called for m_name " << m_name << "\n";
	//std::cout << "...Constructor ScavTrap called for hit_points " << hit_pts << "\n";
};



ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)	// WHAT IS THIS LAST (copy) ???
{
	std::cout << GRE"Copy Constructor ScavTrap called\n" << RES;
}


ScavTrap::~ScavTrap()
{
	std::cout << GRE"Destructor ScavTrap called for " << RES << m_name << "\n"; 
}


// Overloaded operators
ScavTrap &ScavTrap::operator= (const ScavTrap &ScavTrap)
{
	return (*this);
}


void ScavTrap::guardGate()
{
	std::cout << BLU;
	if (guard == false)
	{
		guard = true;
		std::cout << "\nFunction guardgate() called ON: " << m_name << " is in Gate keeper mode\n"; 
	}
	else
	{
		guard = false;
		std::cout << "\nFunction guardgate() called OFF: " << m_name << " is not in Gate keeper mode\n"; 
	}
	std::cout << RES;
}
