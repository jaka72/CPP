/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 14:31:50 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/09/27 12:34:14 by jaka          ########   odam.nl         */
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

		void		add_a_contact(int &count, int &counter);
		int			choose_index_print_contact(int count);
		void		print_contact(int i);
		void		print_phonebook(int count);

//		void		test_fill_phonebook(int &count, int &counter);

};

#endif
