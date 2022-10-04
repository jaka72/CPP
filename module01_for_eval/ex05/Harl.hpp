/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:01:23 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 11:44:46 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:

		void debug();
		void info();
		void warning();
		void error();

		void init();

	public:

		// Default constructor
		Harl();

		// Destructor
		~Harl();

		// Public member functions
		void complain(std::string level);
		
		typedef struct s_data
		{
			std::string	level;
			void		(Harl::*pointerToFunction)(void);
		} t_data;
		t_data data[4];
};

#endif
