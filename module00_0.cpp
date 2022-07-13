#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		argv[1][i] = toupper(argv[1][i]);
		i++;
	}
	
	std::cout << argv[1] << '\n';
	
	return (0);
}
