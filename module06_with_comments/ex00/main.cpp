/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 18:05:40 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include <limits>       // overflow CPP
//#include<bits/stdc++.h> // overflow C   for Linux

#include "Conversion.hpp"

/* QUESTIONS

    - Shall I use getters and setters always for all private vars??
    
    SUBJECT SAYS, YOU NEED TO ACQUIRE THE STRING INTO THE RIGHT TYPE, SO IT IS NOT 
    A STRING ANYMORE. SO THIS PROBABLY MEANS, FIRST INTO DOUBLE, THEN INTO 
    EVERYTHING ELSE.
    
*/


/*
    TYPE CASTING (TYPE CONVERSION)

    a) Implicit (automatic by compiler)
    b) Explicit (manual by programmer)

        b1) With () cast operator 

        b2) With <> 
            - Static_cast           static_cast < new_data_type > (expression); 
                                    x = static_cast < int > (y); 

            - dynamic_cast          To handle polimorphism. Only used when casting from base to derived class
                                    (at runtime, only for class pointers)
            - const_cast
            
            - reinterpret_cast

            - regular cast
*/


// floats, last displayable: 99999999999999999999999999999999999999

int main(int argc, char **argv)
{
    // std::cout << "Main start\n";
    if (argc != 2)
    {
        std::cout << "Only 1 argument allowed.\n";
        return (1);
    }
    

    Conversion con1(argv[1]);

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

    
    char c = '\n';

    if (isprint(c))
        std::cout << "yes is print\n";
    else    
        std::cout << "no is not print\n";

    
    return 0;
}
