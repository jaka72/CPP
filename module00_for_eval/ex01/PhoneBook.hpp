/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 14:31:50 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/09/26 20:54:44 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "utils.hpp"
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact contact[MAX_CONTACTS];

	public:
		// Member functions
		void		add_a_contact(int &count, int &counter);
		int			get_number(std::string str, std::string &field);
		void		print_the_contact(int i);
		int			choose_and_show(int count);
		void		print_phonebook(int count);
};

#endif
