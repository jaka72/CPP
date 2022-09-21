#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	public:
		Contact contact[MAX_CONTACTS];
};

#endif
