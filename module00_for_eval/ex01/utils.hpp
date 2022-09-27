/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/26 14:31:27 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/09/27 13:04:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include "PhoneBook.hpp"
# include "Contact.hpp"

void		print_line(void);
std::string	get_substr(std::string str);
int         check_if_eof();
int         check_if_empty(std::string &str);
int         check_and_choose_index(std::string &str, int &index);

int			get_and_check_input(std::string str, std::string &field);
int			check_input_letters(std::string str, std::string &field,
								int &i, int &repeat);

#endif
