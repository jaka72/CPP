/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/19 22:03:09 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>





#include "Conversion.hpp"



// floats, last displayable: 99999999999999999999999999999999999999

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
	// int n;
    // std::cout << argv[1] << "\n";
    // std::string s1 = "1234";
	// n = stoi(s1);			// stoi not recognized here, but works in _test_stoi ???????
     //   std::cout << n << "\n";
    return 0;
}



/*

    // double f = -99999999999999999999999999.123f;
    // std::cout << " m_float " << f << "\n";
    // std::cout << " m_int " << (int)f << "\n";
    
    //float i1 = nan;   error, unknown word, also -inf, +inff ...
    //float i2 = 1.   ;   // valid
    // float i3 = .0f   ;   // valid
    // float i4 = .1f   ;   // valid
    // float i5 = 0.f   ;   // valid
    // float i6 = 1.f   ;   // valid
    
    // std::cout << "float .0f [" << i3 << "]\n";
    // std::cout << "float .1f [" << i4 << "]\n";
    // std::cout << "float 0.f [" << i5 << "]\n";
    // std::cout << "float 1.f [" << i6 << "]\n";
    

    // std::string s1 = "21474836499";
    // std::string s2 = "9223372036854775807";
    // long double i7 = atof(s2.c_str());
    // std::cout << "int 999... overflow [" << sizeof(i7) << ", " << i7 << " ]\n";
    // std::cout << "MAX INT [" << INT_MAX << "]\n";

    //float f1 = 9223372036854775807.0;
    //float f2 = 9223372036854775807999999999999999999999999999999999.0;
    // float f3 = 99999.9;
    // float f4 = 9999999.9;
    // float f5 = 99999999.9;
    // float f6 = 9999999999999999999999999999999999999999999.9;
    // std::cout << f3 << ", " << f4 << ", " << f5 << ", " << f6  << "\n";

    // float f7 = 2147483646.0f;
    // std::cout << f7 << "\n";

    
    // char c = '\t';

    // if (isprint(c))
    //     std::cout << "yes is print\n";
    // else    
    //     std::cout << "no is not print\n";

    // t_indx indx;
	// indx._i 	 = 0;
	// indx._start = 0;


*/