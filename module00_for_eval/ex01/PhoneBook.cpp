/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 15:16:59 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/09/26 20:53:50 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

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


int	PhoneBook::get_number(std::string str, std::string &field)
{
	while (1)
	{
		std::cout << std::setw(18) << std::left << str;
		std::getline(std::cin, field);
		if (check_if_eof() != 0)
			exit (1);
		if (check_if_empty(field) == 1)
			continue ;
		int i = 0;
		while (field[i])
		{
			if (!isdigit(field[i]) && !isspace(field[i]))
			{
				std::cout << "Phone number can only be digits!\n";
				break ;
			}
			if (isspace(field[i]) && field[i] != ' ')
				field[i] = ' ';
			i++;
			if (field[i] == '\0')
				return (0);
		}
	}
}



void	PhoneBook::print_the_contact(int i)
{
 	std::cout << "\nContact nr. " << i + 1 << '\n';
 	std::cout << "  First name:         " << contact[i].get_name("First Name") << '\n';
 	std::cout << "  Last name:          " << contact[i].get_name("Last Name") << '\n';
 	std::cout << "  Nickname:           " << contact[i].get_name("Nickname") << '\n';
 	std::cout << "  Phone Number:       " << contact[i].get_name("Phone Number") << '\n';
 	std::cout << "  Darkest Secret:     " << contact[i].get_name("Darkest Secret") << '\n';
}



int	PhoneBook::choose_and_show(int count)
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
		std::cout << "Please give correct index\n";
		choose_and_show(count);
	}
	else
		print_the_contact(index - 1);
	return (0);
}



void	PhoneBook::print_phonebook(int count)
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
		std::cout << std:: setw(10) << get_substr(contact[j].get_name("First Name")) << " | ";
		std::cout << std:: setw(10) << get_substr(contact[j].get_name("Last Name")) << " | ";
		std::cout << std:: setw(10) << get_substr(contact[j].get_name("Nickname")) << " | ";
		std::cout << std::endl;
		j++;
	}
	print_line();
}
