/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:04 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/26 20:50:04 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>	// for setw()
#include "utils.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"


// JUST FOR TESTING //////////////////////////////////////////
// void	fill_phonebook(PhoneBook &pb, int &count, int &counter)
// {
// 	int i = 0;
// 	while (i < MAX_CONTACTS)
// 	{
// 		int current = count; 
// 		if (current == MAX_CONTACTS)
// 			current = counter % MAX_CONTACTS;
// 		pb.contact[current].firstname = "aaa";
// 		pb.contact[current].lastname = "aaa";
// 		pb.contact[current].nickname = "aaa";
// 		pb.contact[current].phone_number = "123";
// 		pb.contact[current].darkest_secret = "aaa";
// 		if (count < MAX_CONTACTS)
// 			count++;
// 		counter++;
// 		i++;
// 	}
// }



// MAIN FOR TESTING
int	main(void)
{
	std::string	command;
	std::string	sub_str;
	PhoneBook	phonebook;
	int			count = 0;
	int			counter = 0; 

	// JUST FOR TESTING, TO FILL THE PHONEBOOK
	//fill_phonebook(phonebook, count, counter);
	
	while (1)
	{
		std::cout << "\nEnter a command (a=ADD, s=SEARCH or e=EXIT): ";
		getline(std::cin, command);
		if (check_if_eof() != 0)
			return (1);
		if (command == "a")
			phonebook.add_a_contact(count, counter);
		else if (command == "s")
		{
			phonebook.print_phonebook(count);
			if (phonebook.choose_and_show(count) != 0)
				return (1);
			std::cin.clear();
		}
		else if (command == "e")
			return (0);
		else
			continue ;
	}
	return (0);
}

// MAIN FOR EVALUATION
// int	main(void)
// {
// 	std::string	command;
// 	std::string	sub_str;
// 	PhoneBook	phonebook;
// 	int			count = 0;
// 	int			counter = 0; 

// 	// JUST FOR TESTING, TO FILL THE PHONEBOOK
// 	fill_phonebook(phonebook, count, counter);
// 	while (1)
// 	{
// 		std::cout << "\nEnter a command (ADD, SEARCH or EXIT): ";
// 		getline(std::cin, command);
// 		if (check_if_eof() != 0)
// 			return (1);
// 		if (command == "ADD")
// 			add_a_contact(phonebook, count, counter);
// 		else if (command == "SEARCH")
// 		{
// 			print_phonebook(phonebook, count);
// 			choose_and_show(phonebook, count);
// 			std::cin.clear();
// 		}
// 		else if (command == "EXIT")
// 			return (0);
// 		else
// 			continue ;
// 	}
// 	return (0);
// }
