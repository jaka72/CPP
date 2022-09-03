#include <iostream>
#include <fstream>

//////////////////////////////////////////////////////////////////
// USING ORIGINAL replace() TO COMPARE AND TEST WITH my_replace()

void findAndReplaceAll(std::string &data, std::string toFind, std::string replaceStr)
{
    // Get the first occurrence
    size_t pos = data.find(toFind);
	
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos, toFind.size(), replaceStr);
		
        // Get the next occurrence from the current position
        pos = data.find(toFind, pos + replaceStr.size());
    }
}

int main(int argc, char **argv)
{
	// SEEM TO BE 2 MANNERS OF OPEN() FILE, WHICH ONE IS TO USE ??
	// A)
	//		std::ofstream infile;	// DOES THIS MANNER ALSO NEED TO close()
	//		infile.open("infile");
	// B)
	// 		std::ifstream infile("infile");	// DOES THIS MANNER ALSO NEED TO close()
		
	
	std::ifstream infile(argv[1]);	// DOES THIS MANNER ALSO NEED TO close()
	std::string out_temp = argv[1];
	out_temp.append(".replace_orig");
	std::ofstream outfile(out_temp);


	//std::ofstream outfile("outfile");	// DOES THIS MANNER ALSO NEED TO close()


	std::string stringToFind = argv[2];
	std::string replaceWith = argv[3];

    std::string data;
    //std::string data = "aaaXXXbbbcccXXXdddeeeXXXfffiii";
    //std::cout << data << '\n';


	while (std::getline(infile, data))
	{

		findAndReplaceAll(data, stringToFind, replaceWith);
		outfile << data << '\n';
		std::cout << data << '\n';
		
	}

	infile.close();
	outfile.close();
	
    return 0;
}
