/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:25:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/23 16:44:57 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	print_line(void)
{
	std::cout << "---------------------------------------------------\n";
}


std::string get_substr(std::string str)
{
	std::string newstr;
	if (str.length() <= 10)
		return (str);
	newstr = str.substr(0, 9).append(".");
	return (newstr);
}


void	print_the_contact(PhoneBook	pb, int i)
{
	std::cout << "\nContact nr. " << i + 1 << '\n';
	std::cout << "  First name:     " << pb.contact[i].firstname << '\n';
	std::cout << "  Last name:      " << pb.contact[i].lastname << '\n';
	std::cout << "  Nickname:       " << pb.contact[i].nickname << '\n';
	std::cout << "  Phone number:   " << pb.contact[i].phone_number << '\n';
	std::cout << "  Darkest secret: " << pb.contact[i].darkest_secret << '\n';
}

int check_if_eof()
{
	if (std::cin.eof())
	{
		std::cin.clear();		// IS THIS NECESSSARY ??
		return (1);
	}
	return (0);
}
