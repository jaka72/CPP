#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cstring>		// PROBABLY SOME OF THESE ARE NOT USED
#include <stdlib.h>		// for exit()

// WHAT IF FIND IS THE SAME AS TARGET STRING, DO YOU GET INFINITE LOOP?

// CHECK IF open() file FAILED !!!

std::string loop_till_end_of_line(std::string &line, std::string stringToFind,
			std::string replaceWith, size_t &pos, std::ofstream &outfile)
{
	size_t len = stringToFind.length();
	std::string start;
	// std::string rest;
	while (true)
	{
		//std::cout << "Inner loop,  line: " << line << '\n';
		pos = line.find(stringToFind);
		//std::cout << "   pos: " << pos << '\n';
		
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
	
	std::string new_name = argv[1];
	new_name.append(".replace");


	// std::string infile = "infile";	// NO NO NOT LIKE THIS !!
	std::ofstream outfile(new_name);	// DOES THIS MANNER ALSO NEED TO close()
	std::ifstream infile(argv[1]);



	//std::ifstream infile;
	//infile.open(argv[1]);

	//	CHECK IF OPEN FAILED
	if	(!(infile.is_open()) || !(outfile.is_open()))
	{
		std::cout << "Error with opening a file\n";
		exit (1);
	}
	
	// std::string stringToFind = "XX X ";
	// std::string replaceWith = ".";
	std::string stringToFind = argv[2];
	std::string replaceWith = argv[3];
	
	std::string line;
	// size_t len = stringToFind.length();
	size_t pos;
	
	//  std::cout << "NPOS: " << std::string::npos << '\n';
	//  4.294.967.295
	
	int i = 0;
	while (std::getline(infile, line))
	{
		//std::cout << "\nOuter loop: i" << i << '\n';
		//std::cout << "line:  " << line << '\n';

		line = loop_till_end_of_line(line, stringToFind, replaceWith, pos, outfile);
		i++;
		outfile << line << '\n';
		
		//outfile << line << '\n'; 
	}
	infile.close();
	outfile.close();

}