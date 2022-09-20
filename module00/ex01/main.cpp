/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:04 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/20 18:24:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <iomanip>	// for setw()
#include "utils.hpp"
#include "PhoneBook.hpp"

// CHECK FOR WHAT IS ALLOWE AS INPUT, MAYBE LIKE EMPTY INPUT ETC ... 
//		like empty fields ,  
//		too long string ...
//		max input, negative ... etc
// 		I allow multiple words for name, but if they are separated with tabs
//		it will deform the table -> therefore tabs must be replaces with 'spaces

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
	if (index > count && index <= 8)
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


void	add_a_contact(PhoneBook &pb, int &count)
{
	if (count == 8)
		count = 7;
	std::cout << "Enter contact " << count + 1 << ":\n";
	
	get_name("First Name:", pb.contact[count].firstname);
	get_name("Last Name:", pb.contact[count].lastname);
	get_name("Nickname:", pb.contact[count].nickname);
	// get_number(pb, count);
	get_number(pb.contact[count].phone_number);
	get_name("Darkest Secret:", pb.contact[count].darkest_secret);
	count++;
}

// ADD CHECKING FOR EMPTY FIELDS

int	main(void)
{
	int			count;
	std::string	command;
	std::string	sub_str;
	PhoneBook	phonebook;

	count = 0;
	while (1)
	{
		std::cout << "\nEnter a command (a=ADD, s=SEARCH or e=EXIT): ";
		std::cin >> command;
		//std::cout << "\nEntered : " << command << "\n";
		std::cin.ignore(1000, '\n');			// ignore all after first
												// word until the newline
		if (command == "a")
			add_a_contact(phonebook, count);
		else if (command == "s")
		{
			print_phonebook(phonebook, count);
			choose_and_show(phonebook, count);
		}
		else if (command == "e")
			return (0);
	}
	return (0);
}
