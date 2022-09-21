/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:01:23 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 19:03:24 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();

		void complain(std::string level);
	
		typedef struct s_data
		{
			std::string level;
			// function pointer
			void (Harl::*pointerToFunction)(void);

		} t_data;
		
		t_data data[4];

	private:
		void debug();
		void info();
		void warning();
		void aaa();
		void init();
};

#endif
