#include "main.hpp"

void	print_line(void)
{
	std::cout << "---------------------------------------------------\n";
}


std::string get_substr(std::string str)
{
	std::string newstr;
	if (str.length() <= 10)
		return (str);
	newstr = str.substr(0, 9).append(".");
	return (newstr);
}


void	print_the_contact(PhoneBook	pb, int i)
{
	std::cout << "\nContact nr. " << i << '\n';
	std::cout << "  First name:     " << pb.contact[i].first_name << '\n';
	std::cout << "  Last name:      " << pb.contact[i].last_name << '\n';
	std::cout << "  Nickname:       " << pb.contact[i].nickname << '\n';
	std::cout << "  Phone number:   " << pb.contact[i].phone_number << '\n';
	std::cout << "  Darkest secret: " << pb.contact[i].darkest_secret << '\n';
	// std::cout << std::endl;
}
