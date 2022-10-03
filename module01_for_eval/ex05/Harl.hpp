/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:01:23 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 18:29:40 by jaka          ########   odam.nl         */
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
		

		// TEST: HOW TO CALL IT FROM MAIN ???
		void *a;
		void TEST();



		typedef struct s_data
		{
			std::string level;
			void (Harl::*pointerToFunction)(void);	// function pointer
		
			void (Harl::*ptf)(void);	// function pointer
		
		} t_data;
		
		t_data data[4];

		t_data datatest[1];

};

#endif
