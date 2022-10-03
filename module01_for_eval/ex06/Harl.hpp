/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:01:23 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/29 12:51:36 by jaka          ########   odam.nl         */
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
//		int trial();

	public:

		// Constructor
		Harl();

		// Destructor
		~Harl();

		// Public member functions
		void	complain(std::string level);

		void	call_complaints(int i);
	
		// Structs
		typedef struct s_data
		{
			std::string level;
			
			// function pointer
			void (Harl::*pointerToFunction)(void);

			// TRIAL
			//int (Harl::*pointerToTRIAL)(void);
		} t_data;
		t_data data[4];
};

#endif
