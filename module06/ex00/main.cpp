/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/21 16:28:46 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include "Conversion.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Only 1 argument allowed.\n";
        return (1);
    }

    try
    {
        Conversion con1(argv[1]);
    }
    
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


//////////////////////////////////////////////////////////

//     std::cout.precision(10);

//     float f = 123.111111;  // --->>> 1.23457e +06
// //            1234570       // biger than original
//     std::cout << "float main: " << std::fixed << f << "\n";
//     f = 1234567.999;  // --->>> 1.23457e +06 // biger than original
//     std::cout << "float main: " << f << "\n";
//     f = 1234571.999;  // --->>> 1.23457e +06 // smaller than original
//     std::cout << "float main: " << f << "\n";


    // int x = -2147483648;
    // std::cout << "x:   " << x << "\n";
    
    return 0;
}
