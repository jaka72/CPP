/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/28 18:16:09 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Only 1 argument allowed.\n";
        return (1);
    }
    
    // Check arg if it is just numbers.
    //      If there are more alphabet letters, the input is not valid.

    // char to int      OK
    // char to float    /
    // char to double   /
    //      If it is only 1 non-digit char, it is valid (unless it is non printable).
    
    
    // int to char      ok
    // int to float     ok
    // int to double    ok  
    
    
    
    
    //      If there are only digits, there can be 1 dot as decimal point.



    // If there is 'f' at the end, it must be float. It must not be larger than float. So it can also be double. 
    // If it is without 'f', it can be maximum double. But in this case, can it be float? Or is float not possible ???


    return 0;
}