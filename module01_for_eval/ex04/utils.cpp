/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:19:46 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 13:15:21 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"


int	check_arguments(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments.\n";
		std::cout << "Usage: ./replace  <file_name>  <find>  <replace>\n";
		return (1);
	}
	if (strcmp(argv[2], "") == 0)
	{
		std::cout << "Error: Cannot replace an empty string\n";
		return (1);
	}
	return (0);
}


void	open_files_and_check(char **argv, std::ifstream &infile, std::ofstream &outfile)
{
	infile.open(argv[1]);

	// std::string argv1(argv[1]);
	std::string argv1 = argv[1];
	
	argv1.append(".replace");
	outfile.open(argv1.c_str());	// c_str() makes a string suitable to pass to function
									//		converts it to const *char

	if	((infile.is_open() == 0) || (outfile.is_open() == 0))
	{
		std::cout << "Error with opening a file\n";
		exit (1);
	}
}
