/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:14 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/08 19:36:15 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Where to initialize these values ???


// Constructor Default
ClapTrap::ClapTrap():	m_name("Default"), hit_pts(10), energy_pts(10), attack_damage(0)
{
	std::cout << GRE"Default constructor ClapTrap called (no name)\n" << RES; 
}


ClapTrap::ClapTrap(std::string name): m_name("Default"), hit_pts(10), energy_pts(10), attack_damage(0)
{
	m_name = name;		// MAYBE HERE BETTER TO INIT. AFTER FUNC NAME, LIKE IN DEFAULT CONSTR ???
	// hit_pts = 10;
	// energy_pts = 10;
	// attack_damage = 0;
	std::cout << GRE"Constructor ClapTrap called to create " <<RES<< name << "\n"; 
}

// Constructor Copy
ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	std::cout << GRE"Copy constructor ClapTrap called\n" << RES; 
	*this = claptrap;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << GRE"Destructor ClapTrap called for " <<RES<< m_name << "\n"; 
}

//	HERE ALL MEMBERS ARE COPIED ONE-BY-ONE, SO THAT
// 	THE COPY CONSTRUCTOR CAN BE SIMPLIFIED WITH *this = orig
ClapTrap &ClapTrap::operator= (const ClapTrap &orig)
{
	if (this == &orig)
		return (*this);
	this->m_name = orig.m_name;
	this->hit_pts = orig.hit_pts;
	this->energy_pts = orig.energy_pts;
	this->attack_damage = orig.attack_damage;
	return (*this);
}

// Public member functions
void	ClapTrap::attack(const std::string &target)
{	
	std::cout << LRD;
	if (energy_pts <= 0 || hit_pts <= 0)
	{
		std::cout << m_name << " can't attack, because has no energy" 
			" points left.\n" << RES; 
		return ;
	}
	// attack_damage++;
	if (energy_pts > 0)
	{	std::cout <<"\n"<< m_name << " attacks " << target <<
			", causing him " << attack_damage << " points of damage!\n";
		energy_pts--;
		std::cout << "   (" << m_name << " now has "<<  energy_pts <<
			" energy points left)\n" << RES;
	}
	//else
	//	std::cout << m_name << " now has zero energy points and died.\n\n";
	// 
}



void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << LMAG;
	//attack_damage++; // 	DOES THIS BELONG HERE ??
	std::cout <<"\n"<< m_name << " takes damage of "
		<< amount << " points\n";
	this->hit_pts -= amount;
	if (this->hit_pts > 0)
		std::cout << "   (Now he has " << this->hit_pts << " hit points left)\n";
	else
	{
		this->hit_pts = 0;
		std::cout << "   (Now he has zero hit points and died)\n";
	}
	std::cout << RES;
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << GRN;
	if (energy_pts <= 0)
	{
		std::cout <<"\n"<< m_name << " can't be repaired, because he has no energy" 
			" points left\n" << RES; 
		return ;
	}
	hit_pts += amount;
	energy_pts--;
	std::cout <<"\n" << m_name << " repaires himself by amount " 
		<< amount << "!\n";
	std::cout << "   (Now he has " << hit_pts << " hit points)\n";
	std::cout << RES;
}
