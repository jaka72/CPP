/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:06:29 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 19:05:34 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Harl.hpp"

int check_arguments(int argc)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <arg>\n";
		std::cout << "       (DEBUG, INFO, WARNING, ERROR)\n";
		return (1);
	}
	return (0);
}


int get_level(char **argv, Harl harl)
{
	int ret;
	std::string str = argv[1];
	int i = 0;
	while (i < 4)
	{
		ret = str.compare((harl.data[i]).level);
		if (ret == 0)
			break ;
		i++;
	}
	return (i);
}


int main(int argc, char **argv)
{
	Harl harl;

	if (check_arguments(argc) != 0)
		return (1);

	int level = get_level(argv, harl);

	switch(level)
	{
		case 0:
			harl.call_complaints(level);
			break ;
		case 1:
			harl.call_complaints(level);
			break ;
		case 2:
			harl.call_complaints(level);
			break ;
		case 3:
			harl.call_complaints(level);
			break ;
		default:
			std::cout << "Usage: ./harlFilter <arg>\n";
			std::cout << "       (DEBUG, INFO, WARNING, ERROR)\n";
	}
}