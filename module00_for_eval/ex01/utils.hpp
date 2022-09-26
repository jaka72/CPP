/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 14:31:27 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/09/26 15:25:48 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include "PhoneBook.hpp"
# include "Contact.hpp"

// ONE FUNC REDUNDANT HERE ???

void		print_line(void);
std::string	get_substr(std::string str);
//void		print_the_contact(PhoneBook	pb, int i);

// int	get_number(std::string str, std::string &field);
// int	get_name(std::string str, std::string &field);

int         check_if_eof();
int         check_if_empty(std::string &str);

int         check_and_choose_index(std::string &str, int &index);



#endif
