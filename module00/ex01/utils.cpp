/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:25:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/27 13:04:17 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "string.h"

void	print_line(void)
{
	std::cout << "---------------------------------------------------\n";
}


int check_if_eof()
{
	if (std::cin.eof())
	{
		std::cout << "\n";
		return (1);
	}
	return (0);
}


int check_if_empty(std::string &str)
{
	int i = 0;
	while (str[i])
	{
		if (!isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}


int	check_and_choose_index(std::string &str, int &index)
{
	std::cout << "Choose index: ";
	getline(std::cin, str);			// Getline needs string
	char chr[str.length() + 1];		//	Convert to char* and

	strcpy(chr, str.c_str());		//	copy from string to char*
	index = atoi(chr);				// atoi needs char*
	
	if (check_if_eof() != 0)
		return (1);
	return (0);
}


std::string get_substr(std::string str)
{
	std::string newstr;
	if (str.length() <= 10)
		return (str);
	newstr = str.substr(0, 9).append(".");
	return (newstr);
}


int	get_and_check_input(std::string str, std::string &field)
{
	std::cout << std::setw(18) << std::left << str;
	std::getline(std::cin, field);
	if (check_if_eof() != 0)
		exit (1);
	if (check_if_empty(field) == 1)
		return (1);
	return (0);
}


int	check_input_letters(std::string str, std::string &field, int &i, int &repeat)
{
	if (str == "Phone Number:")
	{
		if (!isdigit(field[i]) && !isspace(field[i]))
		{
			std::cout << "Only digits allowed!\n";
			repeat = 1;
			return (1);
		}
	}
	else
		if (!isalpha(field[i]) && !isspace(field[i]))
		{
			std::cout << "Only alphabet letters allowed!\n";
			repeat = 1;
			return (1);
		}
	if (isspace(field[i]) && field[i] != ' ')
		field[i] = ' ';
	i++;
	if (field[i] == '\0')
		return (1);	
	return (0);
}

