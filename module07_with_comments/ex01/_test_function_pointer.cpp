#include <iostream>
#include <iomanip>      // std::setw



template <typename T>
int    print_elem(T &c)
// void    print_elem(T &c)
//int    print_elem(T &c)
{
	std::cout << std::setw(10) << std::left;
	std::cout  << c;
	return (1);
}

template <typename T>
int	addOne(T& c)
{
	c++;
    return (0);
}

// Non-template function, just for strings
int	addOne(std::string &str)
{
	str[0] = str[0] + 1;
	return (0);
}


// Non-template function, just for strings
// void	addOne(std::string &str)
// {
// 	str[0] = str[0] + 1;
// }


template <typename T>
void    iter(T *arr,  size_t len,  int (*func)(T& n))
// void    iter(T *arr,  size_t len,  int (*func)(char& n))
//void    iter(char arr[],  size_t len,  int (*func)(char& n))
{
	if (arr == NULL || func == NULL)
		return ;
	
	size_t i = 0;
	while (i < len)
	{
		func(arr[i]);
		i++;
	}
    int a = 'a';
	//if (func(a) == 1)
		std::cout << "\n";
}


int main()
{
	char		arrA[] = {'a', 'b', 'c', 'd', 'e'};
	int			arrB[] = {11, 22, 33, 44, 55};

	std::string	arrE[] = {"John", "Maria", "Joseph", "Natasha", "George"};



	
	size_t lenA = sizeof(arrA) / sizeof(arrA[0]);
	size_t lenB = sizeof(arrB) / sizeof(arrB[0]);

	size_t lenE = sizeof(arrE) / sizeof(arrE[0]);


	
	
	{
		::iter(arrA, lenA, print_elem);

		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	}

	{
		::iter(arrA, lenA, print_elem);
		::iter(arrA, lenA, addOne);
		::iter(arrA, lenA, print_elem);
		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

		::iter(arrB, lenB, print_elem);
		::iter(arrB, lenB, addOne);
		::iter(arrB, lenB, print_elem);
		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

        // ::iter(arrE, lenE, print_elem);
		// ::iter(arrE, lenE, addOne);
		// ::iter(arrE, lenE, print_elem);
		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
		
    }
}