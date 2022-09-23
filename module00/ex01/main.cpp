/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:04 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/23 19:16:58 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>	// for setw()
#include <string>	// getline
#include <bits/stdc++.h> // atoi
#include "utils.hpp"
#include "PhoneBook.hpp"


// #include "libft.h"
#include "libft/libft.h"

// ctrl-D should exit ?

// 

// CHECK FOR WHAT IS ALLOWED AS INPUT, MAYBE LIKE EMPTY INPUT ETC ... 
//		like empty fields ,  
//		too long string ...
//		max input, negative ... etc
// 		I allow multiple words for name, but if they are separated with tabs
//		it will deform the table -> therefore tabs must be replaced with 'spaces
//		Over nine entries must override the oldest, not the last !!


void	print_phonebook(PhoneBook pb, int count)
{
	int	j = 0;

	print_line();
	std::cout << std:: setw(10) << "Index" << " | " << "First Name" << " | "
			<< "Last Name " << " | " << " Nickname  |\n";
	print_line();
	if (count == 0)
	{
		std::cout << std::setw(20) << "List is empty.\n";
		print_line();
		return ;
	}
	while (j < count)
	{
		std::cout << std:: setw(10) << j + 1 << " | ";
		std::cout << std:: setw(10) << get_substr(pb.contact[j].firstname) << " | ";
		std::cout << std:: setw(10) << get_substr(pb.contact[j].lastname) << " | ";
		std::cout << std:: setw(10) << get_substr(pb.contact[j].nickname) << " | ";
		std::cout << std::endl;
		j++;
	}
	print_line();
}

int	check_and_choose_index(std::string &str, int &index)
{
	std::cout << "Choose index: ";
	getline(std::cin, str);			// Getline needs string
	char chr[str.length() + 1];		//	Convert to char* and
	strcpy(chr, str.c_str());		//	copy from string to char*
	index = ft_atoi(chr);				// atoi needs char*
	if (check_if_eof() != 0)
	{
		std::cout << "\n";
		return (1);
	}
	return (0);
}


int	choose_and_show(PhoneBook ph, int count)
{
	int	index;
	std::string str;
	if (count == 0)
		return (0);
	while (str == "")		
	{
		if (check_and_choose_index(str, index) != 0)
			return (1);
	}
	if (index > count && index <= MAX_CONTACTS)
	{
		std::cout << "This field is empty, there are " << count
					<< " contacts in the Phonebook\n";
	}
	else if (index < 1 || index > count)
	{
		std::cout << "Out of range, there are 1-8 contacts in the Phonebook\n";
		choose_and_show(ph, count);
	}
	else
		print_the_contact(ph, index - 1);
	return (0);
}


void	add_a_contact(PhoneBook &pb, int &count, int &counter)
{
	int current = count; 
	if (current == MAX_CONTACTS)
		current = counter % MAX_CONTACTS;
	std::cout << "Enter contact " << current + 1 << ":\n";
	get_name("First Name:", pb.contact[current].firstname);
	get_name("Last Name:", pb.contact[current].lastname);
	get_name("Nickname:", pb.contact[current].nickname);
	get_number("Phone Number:", pb.contact[current].phone_number);
	get_name("Darkest Secret:", pb.contact[current].darkest_secret);
	if (count < MAX_CONTACTS)
		count++;
	counter++;
}


// JUST FOR TESTING //////////////////////////////////////////
void	fill_phonebook(PhoneBook &pb, int &count, int &counter)
{
	int i = 0;
	while (i < MAX_CONTACTS)
	{
		int current = count; 
		if (current == MAX_CONTACTS)
			current = counter % MAX_CONTACTS;
		pb.contact[current].firstname = "aaa";
		pb.contact[current].lastname = "aaa";
		pb.contact[current].nickname = "aaa";
		pb.contact[current].phone_number = "123";
		pb.contact[current].darkest_secret = "aaa";
		if (count < MAX_CONTACTS)
			count++;
		counter++;
		i++;
	}
}

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
			add_a_contact(phonebook, count, counter);
		else if (command == "s")
		{
			print_phonebook(phonebook, count);
			if (choose_and_show(phonebook, count) != 0)
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
