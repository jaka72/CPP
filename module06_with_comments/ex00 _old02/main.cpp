/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/03 11:00:03 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include <limits>       // overflow CPP
#include<bits/stdc++.h> // overflow C   PROBABLY BETTER USE THE CPP LIMITS

#include "conversion.hpp"

/*
    TYPE CASTNG (TYPE CONVERSION)

    a) Implicit (automatic by compiler)
    b) Explicit (manual by programmer)

        b1) With () cast operator 

        b2) With <> 
            - Static_cast           static_cast < new_data_type > (expression); 
                                    x = static_cast < int > (y);  
            - dynamic_cast          (at runtime, only for class pointers)
            
            - const_cast
            
            - reinterpret_cast


*/


// floats, last displayable: 99999999999999999999999999999999999999

int main(int argc, char **argv)
{
    std::cout << "Main start\n";
    if (argc != 2)
    {
        std::cout << "Only 1 argument allowed.\n";
        return (1);
    }
    

    Conversion con1(argv[1]);

    double f = -99999999999999999999999999.123f;
    std::cout << " float " << f << "\n";
    std::cout << " int " << (int)f << "\n";
    
    //float i1 = nan;   error, unknown word, also -inf, +inff ...
    //float i2 = 1.   ;   // valid
    float i3 = .0f   ;   // valid
    float i4 = .1f   ;   // valid
    float i5 = 0.f   ;   // valid
    float i6 = 1.f   ;   // valid
    
    std::cout << "float .0f [" << i3 << "]\n";
    std::cout << "float .1f [" << i4 << "]\n";
    std::cout << "float 0.f [" << i5 << "]\n";
    std::cout << "float 1.f [" << i6 << "]\n";
    

    std::string s1 = "21474836499";
    std::string s2 = "9223372036854775807";
    long double i7 = atof(s2.c_str());
    std::cout << "int 999... overflow [" << sizeof(i7) << ", " << i7 << " ]\n";
    std::cout << "MAX INT [" << INT_MAX << "]\n";

    //float f1 = 9223372036854775807.0;
    //float f2 = 9223372036854775807999999999999999999999999999999999.0;
    
    return 0;
}
