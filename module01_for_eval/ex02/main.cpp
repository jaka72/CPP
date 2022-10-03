/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 13:12:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 13:19:02 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;     // POINTER
	std::string &stringREF = str;      // REFERENCE


	
	std::cout << "            str            " << str << "\n";           // STRING VALUE
	std::cout << "           &str            " << &str << "     (address of str)\n\n";		// THE ADRES
	
	std::cout << "      stringREF            " << stringREF << "\n";      // A REFERENCE CAN BE NORMALY PRINTED AS A STRING
	std::cout << "     &stringREF            " << &stringREF << "     (reference, same as the address of str)\n";   //   PRINTS THE ADRES OF THE STRING
	std::cout << "     *stringREF            " << "(* of reference not possible)\n\n";   //   ERROR


	std::cout << "     *stringPTR            " << *stringPTR << "\n";
	std::cout << "      stringPTR            " << stringPTR << "     (address of str)\n";    // POINTER, THE ADDRESS OF str1
	std::cout << "     &stringPTR            " << &stringPTR << "     (address of the pointer)\n";
	std::cout << "   &(*stringPTR)           " << &(*stringPTR) << "\n";
	std::cout << "&(*&(*stringPTR)))         " << &(*(&(*stringPTR))) << "\n\n";

}
