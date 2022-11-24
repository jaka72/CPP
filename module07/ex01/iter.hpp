/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 11:26:04 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/11/24 16:53:02 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>


// template <typename T>
// void	addOne(T &n)
// {
// 	n++;
// }



// // Non-template function, just for strings
// void	addOne(std::string &str)
// {
// 	str[0] = str[0] + 1;
// }



template <typename T>
void    print_elem(const T &c)
{
	std::cout << std::setw(10) << std::left;
	std::cout  << c;
	// return (1);
}


template <typename T>
void    iter(T *arr,  size_t len,  void (*func)(const T& n))
{
	if (arr == NULL || func == NULL)
		return ;
	
	size_t i = 0;
	while (i < len)
	{
		func(arr[i]);
		i++;
	}
	//if (func(1) == 1)
		std::cout << "\n";
}

#endif
