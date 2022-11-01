/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/01 18:24:21 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include <limits>       // overflow CPP
#include<bits/stdc++.h> // overflow C   PROBABLY BETTER USE THE CPP LIMITS

#include "conversion.hpp"

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
    
    return 0;
}
