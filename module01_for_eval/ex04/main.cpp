/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 19:09:07 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 15:23:51 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

// WHAT IF FIND IS THE SAME AS TARGET STRING, DO YOU GET INFINITE LOOP?

// CHECK IF open() file FAILED !!!

//	Position always starts from 0 and stops at the found old pattern.
//	This chunk ('start') from 0 to the pattern goes to outfile line.
//	After this the new pattern appends to outfile line.
//	Then the original line is skipped for the length of the new pattern.
//	From there it continues search for the old pattern. 
//	When position reaches end of line, it becomes NPOS ??????
//	At the end only the last chunk of the line (after last old 
//		pattern) is stored in the line. It must be appended to the 
//		outfile line.

	// size_t len = stringToFind.length();
	//  std::cout << "NPOS: " << std::string::npos << '\n';
	//  4.294.967.295



std::string		loop_till_end_of_line(	std::string &line,
									std::string stringToFind,
									std::string replaceWith, size_t &pos,
									std::ofstream &outfile)
{
	size_t len = stringToFind.length();
	std::string start;
	while (true)
	{
		pos = line.find(stringToFind);
		std::cout << "   pos: " << pos << '\n';
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
	if (check_arguments(argc) != 0)
		return (1);

	std::ifstream infile;
	std::ofstream outfile;
	open_files_and_check(argv, infile, outfile);

	std::string stringToFind = argv[2];
	std::string replaceWith = argv[3];
	std::string line;
	size_t position = 0;	// NOT SURE IF IT IS AUTOM. SET TO ZERO ??
	
	int i = 0;
	while (std::getline(infile, line))
	{
		// std::cout << "\nOuter loop: i" << i << '\n';
		// Returned line is only the last word from the line
		line = loop_till_end_of_line(line, stringToFind, replaceWith, position, outfile);
		i++;

		// Last word appends to the outfile
		outfile << line << '\n';
	}
	infile.close();
	outfile.close();
}
