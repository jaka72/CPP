/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:50:03 by tblaase       #+#    #+#                 */
/*   Updated: 2022/11/22 19:42:41 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"


void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

template <typename T>
void myPrint(T &t)
{
	std::cout << "myprint: " << t << "\n";
}


int main()
{
	char a[] = {'A', 'B', 'C'};
	// double a[] = {65.1, 66.1, 67.1};
	// double a[] = {65, 66, 67};

	std::cout << "Original:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	// ::iter(a, sizeof(a) / sizeof(char), ft_tolower);
	::iter(a, sizeof(a) / sizeof(char), myPrint);

	std::cout << "Changed:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	// ::iter(a, 2, ft_toupper);
	::iter(a, sizeof(a) / sizeof(char), myPrint);


	std::cout << "Changed:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;
} 
