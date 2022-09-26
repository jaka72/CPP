/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:10 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/26 20:51:12 by jaka          ########   odam.nl         */
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
		// Contact();
		// ~Contact();

		// Member Functions
		std::string get_name(std::string field);
		int			store_name(std::string str);
		int			store_number(std::string str);
		void 		choose_field(std::string str, std::string field);
};

#endif
