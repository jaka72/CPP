/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 10:33:58 by tblaase       #+#    #+#                 */
/*   Updated: 2022/09/15 15:32:48 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>

// classes

class ClapTrap
{
	protected:
		unsigned int _hit_pts;

	public:
	// Constructors
		ClapTrap();

	// Deconstructors
		virtual ~ClapTrap();

};