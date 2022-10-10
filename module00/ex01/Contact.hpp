/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:10 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/27 12:34:19 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <stdlib.h>	// for exit
# include <iomanip>		// for setw()
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

		int			store_name(std::string str);
		int			store_number(std::string str);
		void 		store_to_correct_field(std::string str, std::string field);
		std::string get_field(std::string field);

//		void		test_fill_contact();
};

#endif
