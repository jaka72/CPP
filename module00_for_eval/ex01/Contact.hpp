/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:10 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/26 16:06:39 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>	// for setw()
# include "utils.hpp"
# include "PhoneBook.hpp"

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		// Contact();
		
		// ~Contact();

		// int		get_name(std::string str, std::string &field);
		// int		get_number(std::string str, std::string &field);

		// void	print_the_contact(PhoneBook	pb, int i);

		// Getter
		std::string get_name(int n);
		void		set_name(int n, std::string str);
		int			store_name(std::string str);

	
};

std::string Contact::get_name(int n)
{
	if (n == 0)
		return (this->firstname);
	return ("no string returned");
}

void Contact::set_name(int n, std::string str)
{
	if (n == 0)
		this->firstname = str;
}



// int	PhoneBook::store_name(std::string str, std::string &field)
int	Contact::store_name(std::string str)
{
	while (1)
	{
		std::cout << std::setw(18) << std::left << str;
		// std::getline(std::cin, field);
		std::getline(std::cin, ct.set_name(0));
		if (check_if_eof() != 0)
			exit (1);
		if (check_if_empty(field) == 1)
			continue ;
		int i = 0;
		while (1)
		{
			if (!isalpha(field[i]) && !isspace(field[i]))
			{
				std::cout << "Only alphabet letters allowed!\n";
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


#endif
