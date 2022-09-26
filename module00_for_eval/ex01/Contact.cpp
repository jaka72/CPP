/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:10 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/26 20:48:31 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"


std::string Contact::get_name(std::string field)
{
	if (field == "First Name")
		return (this->firstname);
	else if (field == "Last Name")
		return (this->lastname);
	else if (field == "Nickname")
		return (this->nickname);
	else if (field == "Darkest Secret")
		return (this->darkest_secret);
	else if (field == "Phone Number")
		return (this->phone_number);
	return ("no string stored");
}


void Contact::choose_field(std::string str, std::string field)
{
	if (str == "First Name:")
		this->firstname = field;
	else if (str == "Last Name:")
		this->lastname = field;
	else if (str == "Nickname:")
		this->nickname = field;
	else if (str == "Darkest Secret:")
		this->darkest_secret = field;
}



int	Contact::store_name(std::string str)
{
	std::string field;
	while (1)
	{
		int	repeat = 0;
		std::cout << std::setw(18) << std::left << str;
		std::getline(std::cin, field);
		if (check_if_eof() != 0)
			exit (1);
		if (check_if_empty(field) == 1)
			continue ;
		int i = 0;
		while (1)
		{
			if (!isalpha(field[i]) && !isspace(field[i]))
			{
				std::cout << "Only alphabet letters allowed!\n";
				repeat = 1;
				break ;
			}
			if (isspace(field[i]) && field[i] != ' ')
				field[i] = ' ';
			i++;
			if (field[i] == '\0')
				break ;
		}
		if (repeat == 1)
			continue ;
		choose_field(str, field);
		return (0);
	}
}


int	Contact::store_number(std::string str)
{
	std::string field;
	while (1)
	{
		int	repeat = 0;
		std::cout << std::setw(18) << std::left << str;
		std::getline(std::cin, field);
		if (check_if_eof() != 0)
			exit (1);
		if (check_if_empty(field) == 1)
			continue ;
		int i = 0;
		while (1)
		{
			if (!isdigit(field[i]) && !isspace(field[i]))
			{
				std::cout << "Only digits allowed!\n";
				repeat = 1;
				break ;
			}
			if (isspace(field[i]) && field[i] != ' ')
				field[i] = ' ';
			i++;
			if (field[i] == '\0')
				break ;
		}
		if (repeat == 1)
			continue ;
		if (str == "Phone Number:")
			this->phone_number = field;
		return (0);
	}
}
