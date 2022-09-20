#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <cstring>
# include "PhoneBook.hpp"



void		print_line(void);
std::string	get_substr(std::string str);
void		print_the_contact(PhoneBook	pb, int i);

int	get_number(std::string &field);
int	get_name(std::string str, std::string &field);


#endif
