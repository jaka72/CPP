/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 11:26:04 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/11/24 11:46:49 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>


template <typename T>
int    print_elem(T &c)
{
	std::cout << std::setw(10) << std::left;
	std::cout  << c;
	return (1);
}



template <typename T>
int	addOne(T &n)
{
	n++;
	return (0);
}



// Non-template function, just for strings
int	addOne(std::string &str)
{
	str[0] = str[0] + 1;
	return (0);
}



template <typename T>
void    iter(T *arr,  size_t len,  int (*func)(T& n))
{
	if (arr == NULL || func == NULL)
		return ;
	
	size_t i = 0;
	while (i < len)
	{
		func(arr[i]);
		i++;
	}
	char a = 'a';
	if (func(a) == 1)
		std::cout << "\n";
}

#endif
