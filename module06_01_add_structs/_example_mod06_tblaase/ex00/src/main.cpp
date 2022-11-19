/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 16:37:18 by tblaase       #+#    #+#                 */
/*   Updated: 2022/11/01 20:56:28 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"




int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "One Argument required." << std::endl;
		return (1);
	}
	try
	{
		Conversion conversion(argv[1]);
		// try
		// {
		// 	Conversion copy(conversion);
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << std::endl;
		// }
	}
	catch(const Conversion::ErrorException& e)
	{
		std::cerr << e.what() << std::endl;
	}

		std::cerr << "What is UCHAR_MAX: " << UCHAR_MAX << std::endl;


	
	return (0);
}
