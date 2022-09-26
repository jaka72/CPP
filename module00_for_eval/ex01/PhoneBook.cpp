/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 15:16:59 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/09/26 16:06:25 by jmurovec      ########   odam.nl         */
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
	contact[current].store_name("First Name");
	// get_name("First Name:", contact[current].firstname);
	// get_name("Last Name:", contact[current].lastname);
	// get_name("Nickname:", contact[current].nickname);
	// get_number("Phone Number:", contact[current].phone_number);
	// get_name("Darkest Secret:", contact[current].darkest_secret);
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



// // int	PhoneBook::store_name(std::string str, std::string &field)
// int	PhoneBook::store_name(std::string str, Contact ct)
// {
// 	while (1)
// 	{
// 		std::cout << std::setw(18) << std::left << str;
// 		// std::getline(std::cin, field);
// 		std::getline(std::cin, ct.set_name(0));
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

void	PhoneBook::print_the_contact(int i)
{
// 	std::cout << "\nContact nr. " << i + 1 << '\n';
 	std::cout << "  First name:     " << contact[i].get_name(0) << '\n';
// 	std::cout << "  First name:     " << contact[i].firstname << '\n';
// 	std::cout << "  Last name:      " << contact[i].lastname << '\n';
// 	std::cout << "  Nickname:       " << contact[i].nickname << '\n';
// 	std::cout << "  Phone number:   " << contact[i].phone_number << '\n';
// 	std::cout << "  Darkest secret: " << contact[i].darkest_secret << '\n';
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
		std::cout << "Out of range, there are 1-8 contacts in the Phonebook\n";
		choose_and_show(count);
	}
	else
		print_the_contact(index - 1);
	return (0);
}

// void	PhoneBook::add_a_contact(int &count, int &counter)
// {
// 	int current = count; 
// 	if (current == MAX_CONTACTS)
// 		current = counter % MAX_CONTACTS;
// 	std::cout << "Enter contact " << current + 1 << ":\n";
// 	get_name("First Name:", contact[current].firstname);
// 	get_name("Last Name:", contact[current].lastname);
// 	get_name("Nickname:", contact[current].nickname);
// 	get_number("Phone Number:", contact[current].phone_number);
// 	get_name("Darkest Secret:", contact[current].darkest_secret);
// 	if (count < MAX_CONTACTS)
// 		count++;
// 	counter++;
// }


std::string PhoneBook::get_substr(std::string str)
{
	std::string newstr;
	if (str.length() <= 10)
		return (str);
	newstr = str.substr(0, 9).append(".");
	return (newstr);
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
		std::cout << std:: setw(10) << get_substr(contact[j].get_name(0)) << " | ";
		// std::cout << std:: setw(10) << get_substr(contact[j].firstname) << " | ";
		// std::cout << std:: setw(10) << get_substr(contact[j].lastname) << " | ";
		// std::cout << std:: setw(10) << get_substr(contact[j].nickname) << " | ";
		std::cout << std::endl;
		j++;
	}
	print_line();
}
