/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:10 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/27 13:02:51 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string Contact::get_field(std::string field)
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


void Contact::store_to_correct_field(std::string str, std::string field)
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
		if (get_and_check_input(str, field) != 0)
			continue ;
		int i = 0;
		while (1)
		{
			if (check_input_letters(str, field, i, repeat) != 0)
				break ;
		}
		if (repeat == 1)
			continue ;
		store_to_correct_field(str, field);
		return (0);
	}
}


int	Contact::store_number(std::string str)
{
	std::string field;
	while (1)
	{
		int	repeat = 0;
		if (get_and_check_input(str, field) != 0)
			continue ;
		int i = 0;
		while (1)
		{
			if (check_input_letters(str, field, i, repeat) != 0)
				break ;
		}
		if (repeat == 1)
			continue ;
		if (str == "Phone Number:")
			this->phone_number = field;
		return (0);
	}
}
