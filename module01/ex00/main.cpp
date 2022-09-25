/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:32:40 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/25 17:38:04 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/*
    Better to allocate the object on Heap, if you 
    want to use it outside of function scope.
    (so the function returns a pointer to the object)
*/


int main(void)
{
    randomChump("Matilda");
    randomChump("Joseph");
}
