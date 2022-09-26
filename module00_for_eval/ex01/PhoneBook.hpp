/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 14:31:50 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/09/26 16:02:56 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "utils.hpp"
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	public:
		Contact contact[MAX_CONTACTS];
		
		void		add_a_contact(int &count, int &counter);

		// int			store_name(std::string str, std::string &field);
		//int				store_name(std::string str, Contact ct);

		int			get_number(std::string str, std::string &field);
		void		print_the_contact(int i);

		int			choose_and_show(int count);

		void		print_phonebook(int count);

		std::string get_substr(std::string str);

};

#endif
