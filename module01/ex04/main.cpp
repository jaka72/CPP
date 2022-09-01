#include <iostream>
#include <fstream>
// #include <string>

// WHAT IF FIND IS THE SAME AS TARGET STRING, DO YOU GET INFINITE LOOP?


int main()
{
//     char data[100];
//     std::ifstream fl;

//     fl.open("infile");

//     std::cout << "Reading from the file \n";

//     fl >> data;
//     std::cout << data << '\n';

// std::string infile = "infile";	// NO NO NOT LIKE THIS !!
std::ifstream infile("infile");
// std::string outfile = "outfile";
std::ofstream outfile("outfile");

std::string stringToFind = "bbb";
std::string replaceWith = "XXX";

std::string line;
size_t len = stringToFind.length();

//  std::cout << "NPOS: " << std::string::npos << '\n';
//  4.294.967.295

int i {0};
while (std::getline(infile, line))		// above ifstream was not correctly syntaxed
{
	std::cout << i << '\n';
	std::cout << line << '\n';
	while (true)
	{
		size_t pos = line.find(stringToFind);
		std::cout << "pos: " << pos << '\n';
		if (pos != std::string::npos && pos != 0)
		{
			std::string start = line.substr(0, pos);
			std::cout << "Start: " << start << '\n';
			// outfile << line;	// WRITE START TO FILE 
			outfile << start;	// WRITE START TO FILE 
			outfile << ".";
			outfile << replaceWith << '.';

			line = line.substr(pos + len);
			//outfile << line	// WRITE START TO FILE
			std::cout << "rest: " << line << '\n';
			//line.replace(pos, len, replaceWith);
			outfile << line;
		
		}
		else
			break;
	}
	//outfile << line << '\n'; 
}










}