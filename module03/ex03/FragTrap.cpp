/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/11 16:14:50 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
	IN THE BASE CLASS THE MEMBERS ARE INITIALIZED AFTER FUNC()
	BUT HERE IN INHERITED CLASS THEY ARE INITIALIZED AS MEMBERS ???
*/
FragTrap::FragTrap(): ClapTrap()
{
	//hit_pts = 100;		// CAN BE ALSO WITHOUT ->this
	this->_hit_pts = 90;	// inherited from Scav
	this->_energy_pts = 100;
	this->_attack_damage = 30;
	//this->guard = false;
	std::cout << GRE"  Default constructor FragTrap\n" << RES; 
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
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_pts = 90;
	this->_energy_pts = 100;
	this->_attack_damage = 30;
	//this->guard = false;
	_name = name;
	std::cout << GRE"  Constructor FragTrap (" <<RES<< name << ")\n";
	//std::cout << "...Constructor FragTrap called for this->m_name " << this->m_name << "\n";
	//std::cout << "...Constructor FragTrap called for m_name " << m_name << "\n";
	//std::cout << "...Constructor FragTrap called for hit_points " << hit_pts << "\n";
}



FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)	// WHAT IS THIS LAST (copy) ???
{
	std::cout << GRE"  Copy Constructor FragTrap \n" << RES;
	std::cout << GRE"   (It's a copy of the FragTrap " << copy._name << ")\n" << RES;

	*this = copy;
}


FragTrap::~FragTrap()
{
	std::cout << GRE"  Destructor FragTrap (" << RES << _name << ")\n"; 
}


// Overloaded operators
// FragTrap &FragTrap::operator= (const FragTrap &orig)
// {
// 	// ??? FragTrap has no own vars to be copied ???
// 	// this->_guard = orig._guard;
// 	*this = orig;
// 	return (*this);
// }


void FragTrap::highFivesGuys(void)
{
	std::cout << CYN"\nFunction highFivesGuys() called from FragTrap " << _name << RES << "\n\n"; 
}

