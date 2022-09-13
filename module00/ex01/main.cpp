#include "main.hpp"

// CHECK FOR WHAT IS ALLOWE AS INPUT, MAYBE LIKE EMPTY INPUT ETC ... 


void	print_phonebook(PhoneBook pb, int count)
{
	int	j;

	j = 0;
	print_line();
	std::cout << std:: setw(10) << "Index" << " | " << "First Name" << " | "
			<< "Last Name " << " | " << " Nickname  |\n";
	print_line();
	if (count == 0)
	{
		std::cout << std::setw(20) << "List is empty.\n";
		print_line();
		return ;
	}
	while (j < count)
	{
		std::cout << std:: setw(10) << j + 1 << " | ";
		std::cout << std:: setw(10) << get_substr(pb.contact[j].firstname_orig) << " | ";
		std::cout << std:: setw(10) << get_substr(pb.contact[j].lastname_orig) << " | ";
		std::cout << std:: setw(10) << get_substr(pb.contact[j].nickname) << " | ";
		std::cout << std::endl;
		j++;
	}
	print_line();
}


void	choose_and_show(PhoneBook ph, int count)
{
	int	index;

	if (count == 0)
		return ;
	std::cout << "Choose index: ";
	std::cin >> index;
	if (index < 1 || index > count)
	{
		std::cout << "Index is out of range, try again.\n";
	}
	else
	{
		print_the_contact(ph, index - 1);
	}
}


void	add_a_contact(PhoneBook &pb, int &count)
{
	if (count == 8)
		count = 7;
	std::cout << "Enter contact " << count + 1 << ':' << std::endl;
	std::cout << "  Firstname_orig:      ";
	std::getline(std::cin, pb.contact[count].firstname_orig);
	std::cout << "  Lastname_orig:       ";
	std::getline(std::cin, pb.contact[count].lastname_orig);
	std::cout << "  Nickname:        ";
	std::getline(std::cin, pb.contact[count].nickname);
	std::cout << "  Phone number:    ";
	std::getline(std::cin, pb.contact[count].phone_number);
	std::cout << "  Darkest secret:  ";
	std::getline(std::cin, pb.contact[count].darkest_secret);
	count++;
}


int	main(void)
{
	int			count;
	std::string	command;
	std::string	sub_str;
	PhoneBook	phonebook;

	count = 0;
	while (1)
	{
		std::cout << "\nEnter a command (a=ADD, s=SEARCH or e=EXIT): ";
		std::cin >> command;
		std::cin.ignore(1000, '\n');
		if (command == "a")
			add_a_contact(phonebook, count);
		else if (command == "s")
		{
			print_phonebook(phonebook, count);
			choose_and_show(phonebook, count);
		}
		else if (command == "e")
			return (0);
	}
	return (0);
}
