/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:04 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/27 12:55:52 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include "utils.hpp"
#include "PhoneBook.hpp"


int	main(void)
{
	std::string	command;
	std::string	sub_str;
	PhoneBook	phonebook;
	int			count = 0;
	int			counter = 0; 

	// JUST FOR TESTING, TO FILL THE PHONEBOOK
	//phonebook.test_fill_phonebook(count, counter);
	
	while (1)
	{
		std::cout << "\nEnter a command (ADD, SEARCH or EXIT): ";
		getline(std::cin, command);
		if (check_if_eof() != 0)
			return (1);
		if (command == "ADD")
			phonebook.add_a_contact(count, counter);
		else if (command == "SEARCH")
		{
			phonebook.print_phonebook(count);
			if (phonebook.choose_index_print_contact(count) != 0)
				return (1);
		}
		else if (command == "EXIT")
			return (0);
		else
			continue ;
	}
	return (0);
}



// JUST FOR TESTING //////////////////////////////////////////
/*
void	Contact::test_fill_contact()
{
	this->firstname = "Silvia";
	this->lastname = "aaaaaa";
	this->nickname = "bbbbbb";
	this->phone_number = "123 456";
	this->darkest_secret = "cccccc";
}

void	PhoneBook::test_fill_phonebook(int &count, int &counter)
{
	int i = 0;
	while (i < MAX_CONTACTS)
	{
		int current = count; 
		if (current == MAX_CONTACTS)
			current = counter % MAX_CONTACTS;
		
		// test_fill_fields();
		contact[current].test_fill_contact();
		if (count < MAX_CONTACTS)
			count++;
		counter++;
		i++;
	}
}
*/
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// MAIN FOR TESTING
// 		std::cout << "\nEnter a command (a=ADD, s=SEARCH or e=EXIT): ";
// int	main(void)
// {
// 	std::string	command;
// 	std::string	sub_str;
// 	PhoneBook	phonebook;
// 	int			count = 0;
// 	int			counter = 0; 

// 	// JUST FOR TESTING, TO FILL THE PHONEBOOK
// 	// phonebook.test_fill_phonebook(count, counter);
	
// 	while (1)
// 	{
// 		std::cout << "\nEnter a command (a=ADD, s=SEARCH or e=EXIT): ";
// 		getline(std::cin, command);
// 		if (check_if_eof() != 0)
// 			return (1);
// 		if (command == "a")
// 			phonebook.add_a_contact(count, counter);
// 		else if (command == "s")
// 		{
// 			phonebook.print_phonebook(count);
// 			if (phonebook.choose_index_print_contact(count) != 0)
// 				return (1);
// 			//std::cin.clear();
// 		}
// 		else if (command == "e")
// 			return (0);
// 		else
// 			continue ;
// 	}
// 	return (0);
// }
