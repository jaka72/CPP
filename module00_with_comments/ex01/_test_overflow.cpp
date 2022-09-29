/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _test_overflow.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 13:21:04 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/22 13:20:37 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <iomanip>	    // for setw()
# include <iostream>	// for setw()

// max int 2147483647
// max long 9223372036854775807

// ADD CHECKING FOR EMPTY FIELDS

int	main(void)
{
    int long	index = 0;

	std::cout << "Choose index: ";
	std::cin >> index;
	std::cout << "index: " << index << "\n";

	return (0);
}






