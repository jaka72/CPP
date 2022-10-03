#include <iostream>

int main()
{
	std::string str1 = "HI THIS IS BRAIN";

	std::string *stringPTR = &str1;     // POINTER
	std::string &stringREF = str1;      // REFERENCE

	// std::string *asd;
	// 	asd = &str1;
	
	std::cout << " str1:                " << str1 << "\n";           // STRING VALUE
	std::cout << "&str1:                " << &str1 << "     (address of str1)\n\n";		// THE ADRES
	
	std::cout << " stringREF:           " << stringREF << "\n";      // A REFERENCE CAN BE NORMALY PRINTED AS A STRING
	std::cout << "&stringREF:           " << &stringREF << "     (reference, same as the address of str1)\n";   //   PRINTS THE ADRES OF THE STRING
	std::cout << "*stringREF:           " << "(* of reference not possible)\n\n";   //   ERROR


	std::cout << "     *stringPTR            " << *stringPTR << "\n";
	std::cout << "      stringPTR:           " << stringPTR << "     (address of str1)\n";    // POINTER, THE ADDRESS OF str1
	std::cout << "     &stringPTR            " << &stringPTR << "     (address of the pointer)\n";
	std::cout << "   &(*stringPTR)           " << &(*stringPTR) << "\n";
	std::cout << "&(*&(*stringPTR)))         " << &(*(&(*stringPTR))) << "\n\n";

}
