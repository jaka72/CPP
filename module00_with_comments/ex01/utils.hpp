#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <cstring>
# include "PhoneBook.hpp"

// ONE FUNC REDUNDANT HERE ???

void		print_line(void);
std::string	get_substr(std::string str);
void		print_the_contact(PhoneBook	pb, int i);

int	get_number(std::string str, std::string &field);
int	get_name(std::string str, std::string &field);


int check_if_eof();






#endif
