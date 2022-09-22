/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:04 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/22 15:47:37 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <iomanip>	// for setw()
#include "utils.hpp"
#include "PhoneBook.hpp"

// PROBLEM: IF DIGIT OVERFLOW WHEN SEARCH, IT STARTS LOOPING ENDLESSLY

// Check: more words for the name  allowed?

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


void	choose_and_show(PhoneBook ph, int count)
{
	int	index;

	if (count == 0)
		return ;
	std::cout << "Choose index: ";
	std::cin >> index;
	
	if (index >= 2147483647)
		index = 0;
	if (index > count && index <= MAX_CONTACTS)
	{
		std::cout << "This field is empty, there are " << count
					<< " contacts in the Phonebook\n";
	}
	else if (index < 1 || index > count)
	{
		std::cout << "Out of range, there are 1-8 contacts in the Phonebook\n";
	}
	else
		print_the_contact(ph, index - 1);
}


void	add_a_contact(PhoneBook &pb, int &count, int &counter)
{
	int current = count; 
	if (current == MAX_CONTACTS)
		current = counter % 8;
	std::cout << "Enter contact " << current + 1 << ":\n";
	get_name("First Name:", pb.contact[current].firstname);
	get_name("Last Name:", pb.contact[current].lastname);
	get_name("Nickname:", pb.contact[current].nickname);
	// get_number(pb, count);
	get_number(pb.contact[current].phone_number);
	get_name("Darkest Secret:", pb.contact[current].darkest_secret);
	if (count < 8)
		count++;
	counter++;
}


// JUST FOR TESTING //////////////////////////////////////////
void	fill_phonebook(PhoneBook &pb, int &count, int &counter)
{
	int i = 0;
	while (i < 8)
	{
		int current = count; 
		if (current == MAX_CONTACTS)
			current = counter % 8;
		pb.contact[current].firstname = "aaa";
		pb.contact[current].lastname = "aaa";
		pb.contact[current].nickname = "aaa";
		pb.contact[current].phone_number = "123";
		pb.contact[current].darkest_secret = "aaa";
		if (count < 8)
			count++;
		counter++;
		i++;
	}
}


int	main(void)
{
	std::string	command;
	std::string	sub_str;
	PhoneBook	phonebook;
	int			count = 0;
	int			counter = 0; 

	// JUST FOR TESTING, TO FILL THE PHONEBOOK
	fill_phonebook(phonebook, count, counter);
	while (1)
	{
		std::cout << "\nEnter a command (a=ADD, s=SEARCH or e=EXIT): ";
		std::cin >> command;
		if(std::cin.eof())
		{
			std::cin.clear();
			return (0);						// If ctrl-D
		}
		std::cin.ignore(1000, '\n');		// ignore all after first word until the newline												
		if (command == "a")
			add_a_contact(phonebook, count, counter);
		else if (command == "s")
		{
			print_phonebook(phonebook, count);
			choose_and_show(phonebook, count);
			std::cin.clear();
		}
		else if (command == "e")
			return (0);
		else
			continue ;
	}
	return (0);
}
