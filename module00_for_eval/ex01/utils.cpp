/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:25:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/26 20:52:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <cstdlib>
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
		std::cin.clear();		// IS THIS NECESSSARY ??
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
		// if (isalpha(str[i]) || isdigit(str[i]))
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

	// WHAT ELSE TO USE INSTEAD OF strcpy --> <string.h>
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
