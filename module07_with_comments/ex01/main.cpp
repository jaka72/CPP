/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/13 11:55:21 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Iter.hpp"
 
template <typename T>
void    print_arr(T &c)
{
    std::cout << c << " ";
}


template <typename T>
void change(T &c)
{
     c = c - 32;
	//c = std::toupper(static_cast<unsigned char>(c));
}


int main()
{
    char arrA[] = {'a', 'b', 'c', 'd', 'e'};
    int arrB[] = {11, 22, 33, 44, 55};
    
    size_t lenA = sizeof(arrA) / sizeof(arrA[0]);
    size_t lenB = sizeof(arrB) / sizeof(arrB[0]);
    
    //std::cout << "lenA " << lenA << ",   lenB " << lenB << "\n";
    
    {
        
        // void (*fptr)(int) = &print_me;
        // ::iter(arr, 5, fptr);
        
        ::iter(arrA, lenA, print_arr);
        ::iter(arrA, lenA, change);
        ::iter(arrA, lenA, print_arr);
        
        ::iter(arrB, lenB, print_arr);
        ::iter(arrB, lenB, change);
        ::iter(arrB, lenB, print_arr);   
    }
    
    return 0;
}