/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_name_and_number.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 17:16:57 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/20 18:31:13 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <iomanip>	// for setw()

#include "utils.hpp"

int check_if_empty(std::string &str)
{
	int i = 0;
	while (str[i])
	{
		if (isalpha(str[i]) || isdigit(str[i]))
			return (0);
		i++;
	}
	std::cout << "Field must not be empty!\n";
	return (1);
}


int	get_number(std::string &field)
{
	while (1)
	{
		std::cout << std::setw(18) << std::left << "Phone Number:";
		std::getline(std::cin, field);
		if (check_if_empty(field) == 1)
			continue ;
		int i = 0;
		while (field[i])
		{
			if (!isdigit(field[i]) && !isspace(field[i]))
			{
				std::cout << "Phone number must only be digits!\n";
				break ;
			}
			if (isspace(field[i]) && field[i] != ' ')
				field[i] = ' ';
			i++;
			if (field[i] == '\0')
				return (0);
		}
	}
}


int	get_name(std::string str, std::string &field)
{
	while (1)
	{
		
		std::cout << std::setw(18) << std::left << str;	
		// std::cout << "  " << str << "    ";	
		std::getline(std::cin, field);
		if (check_if_empty(field) == 1)
			continue ;
		int i = 0;
		while (1)
		{
			if (!isalpha(field[i]) && !isspace(field[i]))
			{
				std::cout << "Only alphabet letters allowed!\n";
				break ;
			}
			if (isspace(field[i]) && field[i] != ' ')
				field[i] = ' ';
			i++;
			if (field[i] == '\0')
				return (0);
		}
	}
}
