/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_test_stoi.cpp                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/19 21:52:24 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>



int main()
{
   
    std::cout << "Main test stoi\n";

	int n;
    std::string s1 = "1234";
	n = stoi(s1);			
        std::cout << n << "\n";




    return 0;
}
