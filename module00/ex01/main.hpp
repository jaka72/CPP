#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <iomanip>	// for setw()

class Contact
{
	public:
	// private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

class PhoneBook
{
	public:
		Contact contact[8];
};

void		print_line(void);
std::string	get_substr(std::string str);
void		print_the_contact(PhoneBook	pb, int i);

#endif
