/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 19:09:07 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 19:38:28 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cstring>		// PROBABLY SOME OF THESE ARE NOT USED
#include <stdlib.h>		// for exit()

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

std::string loop_till_end_of_line(std::string &line, std::string stringToFind,
									std::string replaceWith, size_t &pos,
									std::ofstream &outfile)
{
	size_t len = stringToFind.length();
	std::string start;
	// std::string rest;
	
	while (true)
	{
		//std::cout << "   Inner loop,  line: " << line << '\n';
		// Pos stops at the found pattern
		pos = line.find(stringToFind);
		std::cout << "   pos: " << pos << '\n';
		
		if (pos != std::string::npos)
		{
			start = line.substr(0, pos);
			//std::cout << "   Start: " << start << "     -> this goes to outfile\n";
			outfile << start;
			//std::cout << "   replace " << replaceWith << "    -> this goes to outfile\n";
			outfile << replaceWith;
			
			line = line.substr(pos + len);
			//std::cout << "   Rest: " << line << '\n';
			//break;
			line = loop_till_end_of_line(line, stringToFind, replaceWith, pos, outfile);
		}
		else
		{
			//std::cout << "Else,  pos: " << pos << "\n";
			break;
		}
	}
	//outfile << line;
	return (line);
}




int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments.\n";
		std::cout << "Usage: ./replace  <file_name>  <find>  <replace>\n";
		return (0);
	}

	// SEEM TO BE 2 MANNERS OF OPEN() FILE, WHICH ONE IS TO USE ??
	// A)
	//		std::ofstream infile;	// DOES THIS MANNER ALSO NEED TO close()
	//		infile.open("infile");
	// B)
	// 		std::ifstream infile("infile");	// DOES THIS MANNER ALSO NEED TO close()
	

	// OPEN INFILE
										// 		NOT GOOD !!
	// std::ifstream infile(argv[1]);	// std::ifstream infile = argv[1];
	//	OR
	std::ifstream infile;
	infile.open(argv[1]);


	// CREATE OUTFILE AND OPEN IT
	std::string argv1(argv[1]);		// string == std::string new_name = argv[1];
	argv1.append(".replace");		// append:  argv[1].abcd
	std::ofstream outfile;			// declare o-stream
	outfile.open(argv1.c_str());		// c_str() makes a string suitable to pass to function
									//		converts it to const *char

	//	CHECK IF OPEN FAILED
	if	((infile.is_open() == 0) || (outfile.is_open() == 0))
	{
		std::cout << "Error with opening a file\n";
		exit (1);
	}


	// std::string stringToFind = "XX X ";
	// std::string replaceWith = ".";
	std::string stringToFind = argv[2];
	std::string replaceWith = argv[3];
	
	std::string line;
	size_t position;
	
	// size_t len = stringToFind.length();
	//  std::cout << "NPOS: " << std::string::npos << '\n';
	//  4.294.967.295
	
	int i = 0;
	while (std::getline(infile, line))
	{
		std::cout << "\nOuter loop: i" << i << '\n';
//		std::cout << "line_old:  " << line << '\n';

		// Returned line is only the last word from the line
		line = loop_till_end_of_line(line, stringToFind, replaceWith, position, outfile);
		i++;
		// Last word appends to outfile
		outfile << line << '\n';
		
	}
	infile.close();
	outfile.close();
}
