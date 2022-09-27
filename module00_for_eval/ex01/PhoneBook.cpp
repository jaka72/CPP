/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 15:16:59 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/09/27 13:04:03 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add_a_contact(int &count, int &counter)
{
	int current = count; 
	if (current == MAX_CONTACTS)
		current = counter % MAX_CONTACTS;
	std::cout << "Enter contact " << current + 1 << ":\n";
	contact[current].store_name("First Name:");
	contact[current].store_name("Last Name:");
	contact[current].store_name("Nickname:");
	contact[current].store_number("Phone Number:");
	contact[current].store_name("Darkest Secret:");
	if (count < MAX_CONTACTS)
		count++;
	counter++;
}


void	PhoneBook::print_contact(int i)
{
 	std::cout << "\nContact nr. " << i + 1 << '\n';
 	std::cout << "  First name:         " << contact[i].get_field("First Name") << '\n';
 	std::cout << "  Last name:          " << contact[i].get_field("Last Name") << '\n';
 	std::cout << "  Nickname:           " << contact[i].get_field("Nickname") << '\n';
 	std::cout << "  Phone Number:       " << contact[i].get_field("Phone Number") << '\n';
 	std::cout << "  Darkest Secret:     " << contact[i].get_field("Darkest Secret") << '\n';
}


int	PhoneBook::choose_index_print_contact(int count)
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
		choose_index_print_contact(count);
	}
	else if (index < 1 || index > count)
	{
		std::cout << "Please give correct index (1-8)\n";
		choose_index_print_contact(count);
	}
	else
		print_contact(index - 1);
	return (0);
}


void	PhoneBook::print_phonebook(int count)
{
	print_line();
	std::cout << std:: setw(10) << "Index" << " | " << "First Name"
			  << " | " << "Last Name " << " | " << " Nickname  |\n";
	print_line();
	if (count == 0)
	{
		std::cout << std::setw(20) << "List is empty.\n";
		print_line();
		return ;
	}
	int	j = 0;
	while (j < count)
	{
		std::cout << std:: setw(10) << j + 1 << " | ";
		std::cout << std:: setw(10) << get_substr(contact[j].get_field("First Name")) << " | ";
		std::cout << std:: setw(10) << get_substr(contact[j].get_field("Last Name")) << " | ";
		std::cout << std:: setw(10) << get_substr(contact[j].get_field("Nickname")) << " | ";
		std::cout << std::endl;
		j++;
	}
	print_line();
}
