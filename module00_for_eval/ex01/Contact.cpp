/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:10 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/26 15:19:50 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

// int	Contact::get_number(std::string str, std::string &field)
// {
// 	while (1)
// 	{
// 		std::cout << std::setw(18) << std::left << str;
// 		std::getline(std::cin, field);
// 		if (check_if_eof() != 0)
// 			exit (1);
// 		if (check_if_empty(field) == 1)
// 			continue ;
// 		int i = 0;
// 		while (field[i])
// 		{
// 			if (!isdigit(field[i]) && !isspace(field[i]))
// 			{
// 				std::cout << "Phone number can only be digits!\n";
// 				break ;
// 			}
// 			if (isspace(field[i]) && field[i] != ' ')
// 				field[i] = ' ';
// 			i++;
// 			if (field[i] == '\0')
// 				return (0);
// 		}
// 	}
// }


// int	Contact::get_name(std::string str, std::string &field)
// {
// 	while (1)
// 	{
// 		std::cout << std::setw(18) << std::left << str;
// 		std::getline(std::cin, field);
// 		if (check_if_eof() != 0)
// 			exit (1);
// 		if (check_if_empty(field) == 1)
// 			continue ;
// 		int i = 0;
// 		while (1)
// 		{
// 			if (!isalpha(field[i]) && !isspace(field[i]))
// 			{
// 				std::cout << "Only alphabet letters allowed!\n";
// 				break ;
// 			}
// 			if (isspace(field[i]) && field[i] != ' ')
// 				field[i] = ' ';
// 			i++;
// 			if (field[i] == '\0')
// 				return (0);
// 		}
// 	}
// }

// void	Contact::print_the_contact(PhoneBook	pb, int i)
// {
// 	std::cout << "\nContact nr. " << i + 1 << '\n';
// 	std::cout << "  First name:     " << pb.contact[i].firstname << '\n';
// 	std::cout << "  Last name:      " << pb.contact[i].lastname << '\n';
// 	std::cout << "  Nickname:       " << pb.contact[i].nickname << '\n';
// 	std::cout << "  Phone number:   " << pb.contact[i].phone_number << '\n';
// 	std::cout << "  Darkest secret: " << pb.contact[i].darkest_secret << '\n';
// }
