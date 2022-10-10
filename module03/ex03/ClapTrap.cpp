/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:49 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/09 10:47:16 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Where to initialize these values ???


// Constructor Default
ClapTrap::ClapTrap()	// :	_name("Default"), _hit_pts(10), _energy_pts(10), _attack_damage(0)
{
	std::cout << GRE"Default constructor ClapTrap\n" << RES;
	_name = "Default";		// MAYBE HERE BETTER TO INIT. AFTER FUNC NAME, LIKE IN DEFAULT CONSTR ???
	_hit_pts = 10;			// OR SHALL I INITIALIZE ALREADY IN THE HEADER ???
	_energy_pts = 10;
	_attack_damage = 0;
}


ClapTrap::ClapTrap(std::string name)	// : _name("Default"), _hit_pts(10), _energy_pts(10), _attack_damage(0)
{
	_name = name;
	_hit_pts = 10;
	_energy_pts = 10;
	_attack_damage = 0;
	std::cout << GRE"Constructor ClapTrap (" <<RES<< name << ")\n"; 
}

// Constructor Copy
ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << GRE"Copy constructor ClapTrap \n" << RES; 
	*this = claptrap;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << GRE"Destructor ClapTrap (" <<RES<< _name << ")\n"; 
}

//	HERE ALL MEMBERS ARE COPIED ONE-BY-ONE, SO THAT
// 	THE COPY CONSTRUCTOR CAN BE SIMPLIFIED WITH *this = orig
ClapTrap &ClapTrap::operator= (const ClapTrap &orig)
{
	if (this == &orig)
		return (*this);
	this->_name = orig._name;
	this->_hit_pts = orig._hit_pts;
	this->_energy_pts = orig._energy_pts;
	this->_attack_damage = orig._attack_damage;
	return (*this);
}

// Public member functions
void	ClapTrap::attack(const std::string &target)
{	
	std::cout << LRD;
	if (_energy_pts <= 0 || _hit_pts <= 0)
	{
		std::cout << _name << " can't attack, because has no energy" 
			" points left.\n" << RES; 
		return ;
	}
	// _attack_damage++;
	if (_energy_pts > 0)
	{	
		std::cout << this->_name << " attacks " << target <<
			", causing him " << _attack_damage << " hit points of damage.\n";
		_energy_pts--;
		std::cout << "   (" << _name << " now has "<<  _energy_pts <<
			" energy points left)\n\n";
	}
	//else
	//	std::cout << _name << " now has zero energy points and died.\n\n";
	// 
}



void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << LMAG;
	//_attack_damage++; // 	DOES THIS BELONG HERE ??
	std::cout << _name << " takes damage of "
		<< amount << " points\n";
	this->_hit_pts -= amount;
	if (this->_hit_pts > 0)
		std::cout << "   (Now has " << _hit_pts << " hit points, " << _energy_pts << " energy points.)\n\n";
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
		std::cout <<"\n"<< _name << " can't be repaired, because he has 0 energy" 
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
