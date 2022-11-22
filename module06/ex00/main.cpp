/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/22 15:56:21 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include "Conversion.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please provide 1 argument only.\n";
		return (1);
	}

	try
	{
		Conversion con1(argv[1]);
	}
	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	
	return 0;
}
