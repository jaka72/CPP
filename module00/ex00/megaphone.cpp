#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	i, j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			argv[j][i] = toupper(argv[j][i]);
			i++;
		}
		std::cout << argv[j] << ' ';
		j++;
	}
	std::cout << '\n';
	return (0);
}
