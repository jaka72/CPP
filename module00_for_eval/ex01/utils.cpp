/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:25:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/26 15:35:54 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	print_line(void)
{
	std::cout << "---------------------------------------------------\n";
}


// std::string get_substr(std::string str)
// {
// 	std::string newstr;
// 	if (str.length() <= 10)
// 		return (str);
// 	newstr = str.substr(0, 9).append(".");
// 	return (newstr);
// }


// void	print_the_contact(PhoneBook	pb, int i)
// {
// 	std::cout << "\nContact nr. " << i + 1 << '\n';
// 	std::cout << "  First name:     " << pb.contact[i].firstname << '\n';
// 	std::cout << "  Last name:      " << pb.contact[i].lastname << '\n';
// 	std::cout << "  Nickname:       " << pb.contact[i].nickname << '\n';
// 	std::cout << "  Phone number:   " << pb.contact[i].phone_number << '\n';
// 	std::cout << "  Darkest secret: " << pb.contact[i].darkest_secret << '\n';
// }

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
		if (isalpha(str[i]) || isdigit(str[i]))
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
