/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 11:26:04 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/11/22 19:59:20 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>

void    iter(T *arr,  size_t len,  void (*func)(T& n))
{
	if (arr == NULL || func == NULL)
		return ;
	
	size_t i = 0;
	while (i < len)
	{
		func(arr[i]);
		i++;
	}
	std::cout << "\n";
}

#endif
