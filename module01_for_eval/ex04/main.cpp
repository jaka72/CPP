/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 19:09:07 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 13:08:05 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

// size_t len = stringToFind.length();
//  std::cout << "NPOS: " << std::string::npos << '\n';
//  4.294.967.295


std::string		loop_till_end_of_line(std::string &line,
									std::string stringToFind,
									std::string replaceWith, size_t &pos,
									std::ofstream &outfile)
{
	size_t len = stringToFind.length();
	std::string start;
	while (true)
	{
		pos = line.find(stringToFind);
		//std::cout << "   pos: " << pos << '\n';
		if (pos != std::string::npos)
		{
			start = line.substr(0, pos);
			outfile << start;
			outfile << replaceWith;
			
			line = line.substr(pos + len);
			line = loop_till_end_of_line(line, stringToFind,
										 replaceWith, pos, outfile);
		}
		else
			break;
	}
	return (line);
}



int	main(int argc, char **argv)
{
	if (check_arguments(argc, argv) != 0)
		return (1);

	std::ifstream infile;
	std::ofstream outfile;
	open_files_and_check(argv, infile, outfile);

	std::string stringToFind = argv[2];
	std::string replaceWith = argv[3];
	std::string line;
	size_t position = 0;
	
	int i = 0;
	while (std::getline(infile, line))
	{
		line = loop_till_end_of_line(line, stringToFind, replaceWith, position, outfile);
		i++;
		outfile << line << '\n';	// Last word appends to the outfile
	}
	infile.close();
	outfile.close();
}
